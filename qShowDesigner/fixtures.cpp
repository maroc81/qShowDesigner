#include "fixtures.h"
#include "ui_fixtures.h"
#include "qchannelslider.h"

#include <QtDebug>
#include <QSpinBox>
#include <QLayout>
#include <QLayoutItem>
#include <QStandardItemModel>

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

FixtureModel::FixtureModel(QObject *parent) : QAbstractTableModel(parent)
{
}

FixtureModel::~FixtureModel()
{
}

int FixtureModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mFixtures.count();
}

int FixtureModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 15;
}

QVariant FixtureModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    //qDebug() << QString("row %1, col%2, role %3").arg(row).arg(col).arg(role);

    quint8 id = mFixtures.keys().at(row);
    Fixture f = mFixtures.value(id);
    QMap<quint8, Fixture::Channel> channels = f.GetChannels();
    bool selected = mSelected[id];

    switch(role)
    {
    case Qt::DisplayRole:
    {
        quint8 chanNum = (col-1)/2;
        QString chanName("");
        QVariant chanValue = QString("");
        if (channels.contains(chanNum))
        {
            chanName = channels[chanNum].mName;
            chanValue = channels[chanNum].mValue;
        }
        switch(col)
        {
        case 1:
            return f.GetId();
        case 2:
            return f.GetName();
        default:
            if (col % 2 == 1)
            {
                return chanName;
            }
            else
            {
                return chanValue;
            }
        }
        break;
    }
    case Qt::FontRole:
            //QFont boldFont;
            //boldFont.setBold(true);
            //return boldFont;
        break;
    case Qt::BackgroundRole:
            //QBrush redBackground(Qt::red);
            //return redBackground;
        break;
    case Qt::TextAlignmentRole:
            //return Qt::AlignRight + Qt::AlignVCenter;
        break;
    case Qt::CheckStateRole:
        if (col == 0)
        {
            if (selected)
            {
                return Qt::Checked;
            }
            else
            {
                return Qt::Unchecked;
            }
        }
    }
    return QVariant();
}

bool FixtureModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid())
    {
        int row = index.row();
        int col = index.column();
        if ( role == Qt::CheckStateRole )
        {
            // get the id/key of the fixture at this row
            quint8 id = mFixtures.keys().at(row);
            mSelected[id] = value == Qt::Checked ? true : false;
            qDebug() << "Got Checkstate " << mSelected[id] << " for fixture " << id << " at " << col << " " << index.row() << " value = " << value;
            emit dataChanged(index, index);
            return true;
        }
    }
    return false;
}

QVariant FixtureModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    //qDebug() << QString("section %2, role %3").arg(section).arg(role);
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("");
            case 1:
                return QString("Id");
            case 2:
                return QString("Name");
            default:
                if (section % 2 == 1)
                {
                    return QString("Ch %1 Name").arg((section - 1)/2);
                }
                else
                {
                    return QString("Ch %1 Val").arg((section - 1)/2);
                }
            }
        }
        else
        {
            return QString("%1").arg(section+1);
        }
    }
    return QVariant();
}

Qt::ItemFlags FixtureModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    int col = index.column();

    if ( col == 0 )
    {
        return QAbstractTableModel::flags(index) | Qt::ItemIsUserCheckable;
    }
    return Qt::ItemIsEnabled;
}

void FixtureModel::SetFixtures(QMap<quint8,Fixture> fixtures)
{
    bool changeLayout = false;
    if (mFixtures.count() != fixtures.count())
    {
        changeLayout = true;
    }
    mFixtures = fixtures;
    if ( changeLayout )
    {
        emit layoutChanged();
    }
    QModelIndex start = index(0,0);
    QModelIndex stop = index(rowCount()-1, columnCount()-1);
    qDebug() << stop;
    qDebug() << mFixtures[45].GetChannelValue(1);
    emit dataChanged(start, stop);
}

void FixtureModel::UpdateFixture(Fixture &fixture)
{
    if (mFixtures.contains(fixture.GetId()))
    {
        mFixtures.insert(fixture.GetId(), fixture);
        int row = 0;
        foreach( quint8 id, mFixtures.keys())
        {
            if (id == fixture.GetId())
            {
                break;
            }
            row++;
        }

        QModelIndex start = index(row,0);
        QModelIndex stop = index(row, columnCount()-1);
        emit dataChanged(start, stop);
    }
}

void FixtureModel::UpdateChannel(Fixture &fixture, Fixture::Channel &channel)
{
    // for now just update the whole fixture
    UpdateFixture( fixture );
}

QMap<quint8,Fixture> FixtureModel::GetFixtures()
{
    return mFixtures;
}

QMap<quint8,Fixture> FixtureModel::GetSelectedFixtures()
{
    QMap<quint8,Fixture> selected;

    foreach(quint8 key, mSelected.keys())
    {
        if (mFixtures.contains(key) && mSelected[key])
        {
            selected[key] = mFixtures[key];
        }
    }
    return selected;
}

Fixtures::Fixtures( ShowDesigner *sd, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::Fixtures),
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
    mModel = new FixtureModel();
    mModel->SetFixtures(mSd->GetFixtures());
    connect(mModel, SIGNAL(fixtureSelected()), this, SLOT(on_FixtureSelected()));
    connect(mSd, SIGNAL(fixturesChanged()), this, SLOT(on_FixturesChanged()));
    connect(mSd, SIGNAL(fixtureChanged(Fixture)), this, SLOT(on_FixtureChanged(Fixture)));
    connect(mSd, SIGNAL(channelChanged(Fixture, Fixture::Channel)), this, SLOT(on_ChannelChanged(Fixture, Fixture::Channel)));
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

    //mSd->test();
}

void Fixtures::resizeEvent(QResizeEvent *event)
{
    int h = height();
    int w = width();
    mSettings.setValue(FIXTURES_HEIGHT, h);
    mSettings.setValue(FIXTURES_WIDTH, w);
    QWidget::resizeEvent(event);
}

void Fixtures::moveEvent(QMoveEvent *event)
{
    int xpos = x();
    int ypos = y();
    mSettings.setValue(FIXTURES_X, xpos);
    mSettings.setValue(FIXTURES_Y, ypos);
    QWidget::moveEvent(event);
}

Fixtures::~Fixtures()
{
    delete ui;
    delete mModel;
}

void Fixtures::on_Fixtures_destroyed()
{

}

void Fixtures::on_ChannelValueChanged(int value, int num)
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

void Fixtures::on_FixtureSelected()
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

void Fixtures::on_FixturesChanged()
{
    qDebug() << "Fixture changed";
    // update the model and refresh the table
    mModel->SetFixtures(mSd->GetFixtures());
}

void Fixtures::on_FixtureChanged(Fixture fixture)
{
    mModel->UpdateFixture( fixture );
}

void Fixtures::on_ChannelChanged(Fixture fixture, Fixture::Channel channel)
{
    mModel->UpdateChannel( fixture, channel );
}

void Fixtures::on_btnRefresh_released()
{
    const char testdata[] = {char(0xa5),0x08,0x03,0x00,0x2c,0x01,0x7f};
    QByteArray ba(testdata, sizeof(testdata));
    mSd->Decode( ba );
}

void Fixtures::on_btnRefresh_clicked()
{
    mSd->RequestFixtures();
}


