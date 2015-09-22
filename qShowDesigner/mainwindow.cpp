#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialconfig.h"
#include "qlineeditlabel.h"

#include <QtDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mSd(parent),
    mSettings("IconuxTech","qShowDesigner")
{
    ui->setupUi(this);

    mStatusLabel = new QLabel(this);
    ui->statusBar->addWidget(mStatusLabel, 1);
    ui->statusBar->setSizeGripEnabled(false);
    mStatusLabel->setText("Not Connected");

    ui->gridLayout->setColumnStretch(1,1);

    for(int row = 0; row < 12; row++)
    {
        QString rowStr = QString::number(row+1);
        QString lblText = "Scene " + rowStr;

        QPushButton *sceneBtn = new QPushButton(rowStr, this);
        sceneBtn->setMaximumWidth(50);
        ui->gridLayout->addWidget(sceneBtn, row, 0);
        // connect each button to the same slot which selects the scene
        connect( sceneBtn, SIGNAL(released()), this, SLOT(on_btn_num_released()));

        QLineEditLabel *lel = new QLineEditLabel(this);
        lel->showAsLabel();
        lel->setText( mSettings.value("rowLabel/"+rowStr, lblText).toString());
        ui->gridLayout->addWidget(lel, row, 1);
        connect( lel, SIGNAL(editingFinished()), this, SLOT(on_editing_finished()));
    }

    /*for(int row = 0; row < ui->gridLayout->rowCount(); row++)
    {
        QLayoutItem *item = ui->gridLayout->itemAtPosition(row, 1);

        QLineEditLabel *label = qobject_cast<QLineEditLabel*> (item->widget());
        if ( !label )
        {
            continue;
        }
        QString lblText = "Scene " + QString::number(row+1);
        label->setText( lblText );
    }*/
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_btn_num_released()
{
    // cast sender to push button
    QPushButton *pushButton = qobject_cast<QPushButton*>(sender());
    QString buttonNumber = pushButton->text();
    int scene = buttonNumber.toInt();

    qDebug() << "Button " << scene << " was released";

    if (!mSd.SelectScene(scene))
    {
        ui->statusBar->showMessage("Failed to set scene");
    }

    // get the sender as a QWidget object
    QWidget *buttonWidget = qobject_cast<QWidget*>(sender());
    if (!buttonWidget)
        return;

    // find the index button in the layout
    int btnIndex = ui->gridLayout->indexOf(buttonWidget);
    if ( btnIndex < 0 )
    {
        qDebug() << "Button not found in layout " << btnIndex;
        return;
    }

    int rowOfButton, columnOfButton, rowSpanOfButton, columnSpanOfButton;
    // get the row and column of the button
    ui->gridLayout->getItemPosition(btnIndex, &rowOfButton, &columnOfButton, &rowSpanOfButton, &columnSpanOfButton);

    // make sure the row and column match the button that sent the signal
    QLayoutItem *item = ui->gridLayout->itemAtPosition(rowOfButton, columnOfButton);
    QPushButton *clickedButton = qobject_cast<QPushButton*>(item->widget());
    if (!clickedButton)
    {
        qDebug() << "Button does match row and column in layout";
        return;
    }

    // the scene is the row + 1
    //if (!mSd.SelectScene(rowOfButton + 1)
}

void MainWindow::on_actionAlways_on_top_triggered()
{
    //if (windowStaysOnTopCheckBox->isChecked())
           //flags |= Qt::WindowStaysOnTopHint;
    Qt::WindowFlags flags;
    setWindowFlags(Qt::WindowStaysOnTopHint);
    //Qt::X11BypassWindowManagerHint for this flag to work correctly
    show();
}

void MainWindow::on_editing_finished()
{
    Save();
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
    for (int row; row < ui->gridLayout->rowCount(); row++)
    {
        QString rowStr = QString::number(row+1);
        QLayoutItem *item = ui->gridLayout->itemAtPosition(row, 1);
        QLineEditLabel *label = qobject_cast<QLineEditLabel*> (item->widget());
        mSettings.setValue("rowLabel/"+rowStr, label->text());
    }
}


