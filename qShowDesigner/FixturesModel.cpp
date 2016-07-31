#include "FixturesModel.h"

#include <QLayout>
#include <QLayoutItem>
#include <QStandardItemModel>

#include <QtDebug>

FixturesModel::FixturesModel(QObject *parent) : QAbstractTableModel(parent)
{
}

FixturesModel::~FixturesModel()
{
}

int FixturesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mFixtures.count();
}

int FixturesModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 15;
}

QVariant FixturesModel::data(const QModelIndex &index, int role) const
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

bool FixturesModel::setData(const QModelIndex &index, const QVariant &value, int role)
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

QVariant FixturesModel::headerData(int section, Qt::Orientation orientation, int role) const
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

Qt::ItemFlags FixturesModel::flags(const QModelIndex &index) const
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

void FixturesModel::SetFixtures(QMap<quint8,Fixture> fixtures)
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

void FixturesModel::UpdateFixture(Fixture &fixture)
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

void FixturesModel::UpdateChannel(Fixture &fixture, Fixture::Channel &channel)
{
    // for now just update the whole fixture
    UpdateFixture( fixture );
}

QMap<quint8,Fixture> FixturesModel::GetFixtures()
{
    return mFixtures;
}

QMap<quint8,Fixture> FixturesModel::GetSelectedFixtures()
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

