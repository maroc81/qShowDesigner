#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialconfig.h"
#include "qlineeditlabel.h"

#include <QtDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QLayout>
#include <QStandardPaths>

#define SETTING_BTNLBL "buttonLabel/"
#define SETTING_WINDOW "window/"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mSd(parent),
    mSettings("iconux.org","qShowDesigner")
{
    ui->setupUi(this);
    mFixtureDialog = new Fixtures(&mSd, this);

    //QString configpath = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation).first();
    //mSettings = new QSettings(configpath + "/qShowDesigner.ini", QSettings::IniFormat);
    //qDebug() << "Loaded config file " <<  configpath + "/qShowDesigner.ini";

    mStatusLabel = new QLabel(this);
    ui->statusBar->addWidget(mStatusLabel, 1);
    ui->statusBar->setSizeGripEnabled(false);
    mStatusLabel->setText("Not Connected");

    ui->gridLayout->setColumnStretch(1,1);

    // set each button text to numbers 1 through 12
    // load each button label text from settings or initialize to Scene #
    for(int row = 0; row < 12; row++)
    {
        QString btnStr = QString::number(row+1);
        QString lblText = "Scene " + btnStr;

        QPushButton *sceneBtn = new QPushButton(btnStr, this);
        sceneBtn->setMaximumWidth(50);
        ui->gridLayout->addWidget(sceneBtn, row, 0);
        // connect each button to the same slot which selects the scene
        connect( sceneBtn, SIGNAL(released()), this, SLOT(on_btn_num_released()));

        QLineEditLabel *lel = new QLineEditLabel(this);
        lel->showAsLabel();
        lel->setText( mSettings.value(SETTING_BTNLBL + btnStr, lblText).toString());
        ui->gridLayout->addWidget(lel, row, 1);
        connect( lel, SIGNAL(editingFinished()), this, SLOT(on_editing_finished()));
    }

    // load always on top setting
    ui->actionAlways_on_top->setChecked(mSettings.value(SETTING_WINDOW "alwaysontop", false).toBool());
    connect( &mSd, SIGNAL(pageChanged(quint16)), this, SLOT(on_page_changed(quint16)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mFixtureDialog;
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{

}

void MainWindow::on_action_Connect_triggered()
{
    SerialConfig sc(this);
    sc.exec();
    if (sc.result() == QDialog::Accepted)
    {
        mStatusLabel->setText("Connecting...");
        if (!mSd.ConnectToShowDesigner(sc.GetPort()))
        {
            mStatusLabel->setText("Not Connected");
            ui->statusBar->showMessage("Connection Failed");
            ShowErrorMessage("Failed to Connect to Show Designer", mSd.GetErrorString());
        }
        else
        {
            mStatusLabel->setText("Connected");
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionAlways_on_top_triggered()
{
    Qt::WindowFlags flags = windowFlags();
    if (ui->actionAlways_on_top->isChecked())
    {
        flags |= Qt::WindowStaysOnTopHint;
        // for Linux/X11, need to also set flag to bypass window manager
        // flags |= Qt::X11BypassWindowManagerHint;
    }
    else
    {
        flags &= ~Qt::WindowStaysOnTopHint;
        // flags &= ~Qt::X11BypassWindowManagerHint;
    }
    setWindowFlags( flags );
    mSettings.setValue(SETTING_WINDOW "alwaysontop", ui->actionAlways_on_top->isChecked());
    show();
}


void MainWindow::on_actionFixtures_triggered()
{
    mFixtureDialog->show();
}

void MainWindow::on_btnDown_clicked()
{
    mSd.RequestPageDown();
}

void MainWindow::on_btnUp_clicked()
{
    mSd.RequestPageUp();
}

void MainWindow::on_btn_num_released()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    QString buttonNumber = clickedButton->text();
    int btnNum = buttonNumber.toInt();

    qDebug() << "Button " << btnNum << " was released";


    if (!mSd.PushButton(btnNum))
    {
        ui->statusBar->showMessage("Failed to set scene");
    }

    for (int row = 0; row < ui->gridLayout->rowCount(); row++)
    {
        QLayoutItem *item = ui->gridLayout->itemAtPosition(row, 0);
        QPushButton *btn = qobject_cast<QPushButton*> (item->widget());
        btn->setStyleSheet("");
    }
    clickedButton->setStyleSheet("background-color:red");
}

void MainWindow::on_editing_finished()
{
    Save();
}

void MainWindow::on_page_changed(quint16 pageNo)
{
    ui->lePage->setText(QString::number((uint)pageNo));
}

void MainWindow::ShowErrorMessage(const QString &text, const QString &informativeText)
{
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.setInformativeText(informativeText);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
}

void MainWindow::Save()
{
    qDebug() << "Saving settings";
    for (int row = 0; row < ui->gridLayout->rowCount(); row++)
    {
        QString rowStr = QString::number(row+1);
        QLayoutItem *item = ui->gridLayout->itemAtPosition(row, 1);
        QLineEditLabel *label = qobject_cast<QLineEditLabel*> (item->widget());
        mSettings.setValue(SETTING_BTNLBL + rowStr, label->text());
    }
    mSettings.sync();
    qDebug() << mSettings.status();
}


