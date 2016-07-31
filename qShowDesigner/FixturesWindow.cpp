#include "FixturesWindow.h"
#include "ui_FixturesWindow.h"
#include "QChannelSlider.h"

#include <QtDebug>
#include <QSpinBox>
#include <QKeyEvent>

#define FIXTURES_HEIGHT     "Fixtures/height"
#define FIXTURES_WIDTH      "Fixtures/width"
#define FIXTURES_X          "Fixtures/x"
#define FIXTURES_Y          "Fixtures/y"


void clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0)) != 0)
    {
        if (item->layout())
        {
            clearLayout(item->layout());
            //delete item->layout();
        }
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }
}


FixturesWindow::FixturesWindow( ShowDesigner *sd, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::FixturesWindow),
    mSd(sd),
    mSettings("iconux.org","qShowDesigner")
{
    ui->setupUi(this);

    clearLayout(ui->hlChannelSliders);

    ui->hlChannelSliders->addLayout(new QChannelSlider(1));
    ui->hlChannelSliders->addLayout(new QChannelSlider(2));
    ui->hlChannelSliders->addLayout(new QChannelSlider(3));
    ui->hlChannelSliders->addLayout(new QChannelSlider(4));
    ui->hlChannelSliders->addLayout(new QChannelSlider(5));
    ui->hlChannelSliders->addLayout(new QChannelSlider(6));

    // create fixture model and initialize it to current fixtures
    mModel = new FixturesModel();
    mModel->SetFixtures(mSd->GetFixtures());
    connect(mModel, SIGNAL(fixtureSelected()), this, SLOT(on_FixtureSelected()), Qt::QueuedConnection);
    connect(mSd, SIGNAL(fixturesChanged()), this, SLOT(on_FixturesChanged()), Qt::QueuedConnection);
    connect(mSd, SIGNAL(fixtureChanged(quint8)), this, SLOT(on_FixtureChanged(quint8)), Qt::QueuedConnection);
    connect(mSd, SIGNAL(channelChanged(quint8, quint8)), this, SLOT(on_ChannelChanged(quint8, quint8)),Qt::QueuedConnection);
    ui->tblFixtures->setModel(mModel);

    ui->tblFixtures->setColumnWidth(0,30);
    ui->tblFixtures->resizeColumnsToContents();
    for (int c = 2; c < ui->tblFixtures->horizontalHeader()->count(); ++c)
    {
        //ui->tblFixtures->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
    }
    ui->tblFixtures->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tblFixtures->resizeColumnsToContents();

    for (int i = 0; i < ui->hlChannelSliders->count(); i++)
    {
       QLayoutItem *layoutItem = ui->hlChannelSliders->itemAt(i);
       QChannelSlider* chsl = qobject_cast<QChannelSlider*>(layoutItem->layout());
       connect( chsl, SIGNAL(valueChanged(int,int)), this, SLOT(on_ChannelValueChanged(int,int)));
    }

    int h = mSettings.value(FIXTURES_HEIGHT, 800).toInt();
    int w = mSettings.value(FIXTURES_WIDTH, 1200).toInt();
    resize(w, h);

    int x = mSettings.value(FIXTURES_X, 0).toInt();
    int y = mSettings.value(FIXTURES_Y, 0).toInt();
    move(x, y);
}

void FixturesWindow::resizeEvent(QResizeEvent *event)
{
    int h = height();
    int w = width();
    mSettings.setValue(FIXTURES_HEIGHT, h);
    mSettings.setValue(FIXTURES_WIDTH, w);
    QWidget::resizeEvent(event);
}

void FixturesWindow::moveEvent(QMoveEvent *event)
{
    int xpos = x();
    int ypos = y();
    mSettings.setValue(FIXTURES_X, xpos);
    mSettings.setValue(FIXTURES_Y, ypos);
    QWidget::moveEvent(event);
}

void FixturesWindow::keyPressEvent(QKeyEvent *event)
{
    if ( Qt::Key_F9 == event->key())
    {
        mSd->test();
    }
    else if ( Qt::Key_F10 == event->key())
    {
        static quint8 chan = 123;
        char test[] = {char(0xa5), 0x08, 0x03,0x00,0x00,0x00, char(chan)};
        chan += 5;
        QByteArray testarray(test, sizeof(test));
        mSd->Decode(testarray);

    }
}

FixturesWindow::~FixturesWindow()
{
    delete ui;
    delete mModel;
}

void FixturesWindow::on_Fixtures_destroyed()
{

}

void FixturesWindow::on_ChannelValueChanged(int value, int num)
{
    if (ui->chkUpdate->isChecked())
    {
        //  for each checked fixture, update channel
        QMap<quint8,Fixture> fixtures = mModel->GetSelectedFixtures();
        foreach(Fixture f, fixtures)
        {
            Fixture::Channel channel = f.GetChannel(num);
            qDebug() << "Setting fixture " << f.GetId() << " channel " << channel.mNum << " value " << value;
            mSd->SetFixtureChannel(f.GetId(), channel.mNum, value);
        }
    }
}

void FixturesWindow::on_FixtureSelected()
{
    // get selected fixtures and label each channel slider
    QMap<quint8,Fixture> fixtures = mModel->GetSelectedFixtures();
    foreach(Fixture f, fixtures)
    {
        for( int i = 0; i < f.GetChannels().count(); i++)
        {
            Fixture::Channel channel = f.GetChannel(i+1);
            QLayoutItem *layoutItem = ui->hlChannelSliders->itemAt(i);
            QChannelSlider* chsl = qobject_cast<QChannelSlider*>(layoutItem->layout());
            if (!chsl->GetName().contains(channel.mName.trimmed()))
            {
                chsl->SetName(channel.mName);
            }
        }
    }
}

void FixturesWindow::on_FixturesChanged()
{
    qDebug() << "Fixtures changed";
    // update the model and refresh the table
    mModel->SetFixtures(mSd->GetFixtures());
}

void FixturesWindow::on_FixtureChanged(quint8 fixId)
{
    Fixture fix = mSd->GetFixtureByNum(fixId);
    mModel->UpdateFixture( fix );
}

void FixturesWindow::on_ChannelChanged(quint8 fixId, quint8 channelNum)
{
    Fixture fix = mSd->GetFixtureByNum(fixId);
    Fixture::Channel chan = fix.GetChannel( channelNum );
    mModel->UpdateChannel( fix, chan );
}

void FixturesWindow::on_btnRefresh_released()
{
    //const char testdata[] = {char(0xa5),0x08,0x03,0x00,0x2c,0x01,0x7f};
    //QByteArray ba(testdata, sizeof(testdata));
    //mSd->Decode( ba );
}

void FixturesWindow::on_btnRefresh_clicked()
{
    mSd->RequestFixtures();
}


