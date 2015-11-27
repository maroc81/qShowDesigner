#include "fixtures.h"
#include "ui_fixtures.h"
#include "qchannelslider.h"

#include <QtDebug>
#include <QSpinBox>
#include <QLayout>
#include <QLayoutItem>
#include <QStandardItemModel>

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
    return 1;
}

int FixtureModel::columnCount(const QModelIndex &parent) const
{
    return 15;
}

QVariant FixtureModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    // generate a log message when this method gets called
    qDebug() << QString("row %1, col%2, role %3")
                .arg(row).arg(col).arg(role);

    switch(role)
    {
    case Qt::DisplayRole:
        //return QString("Row%1, Column%2").arg(row + 1).arg(col +1);
        switch(col)
        {
        /*case 1:
            return QString("48");
        case 2:
            return QString("Stage Right");
        case 3:
            return QString("Red");
        case 4:
            return QString("23");
        case 5:
            return QString("Blue");
        case 6:
            return QString("222");
        case 7:
            return QString("Green");
        case 8:
            return QString("54");
        case 9:
            return QString("Strobe");
        case 10:
            return QString("23");
        case 11:
            return QString("Macro");
        case 12:
            return QString("123");
        case 13:
            return QString("Dimmer");
        case 14:
            return QString("255");
            */
        }

        break;
    case Qt::FontRole:
        /*if (row == 0 && col == 0) //change font only for cell(0,0)
        {
            QFont boldFont;
            boldFont.setBold(true);
            return boldFont;
        }*/
        break;
    case Qt::BackgroundRole:

        /*if (row == 1 && col == 2)  //change background only for cell(1,2)
        {
            QBrush redBackground(Qt::red);
            return redBackground;
        }*/
        break;
    case Qt::TextAlignmentRole:

        /*if (row == 1 && col == 1) //change text alignment only for cell(1,1)
        {
            return Qt::AlignRight + Qt::AlignVCenter;
        }*/
        break;
    case Qt::CheckStateRole:

        if (col == 0)
        {
            return Qt::Checked;
        }
    }
    return QVariant();
}

QVariant FixtureModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    qDebug() << QString("section %2, role %3").arg(section).arg(role);
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("");
            case 1:
                return QString("Number");
            case 2:
                return QString("Name");
            default:
                if (section % 2 == 1)
                {
                    return QString("Ch %1 Name").arg((section - 1)/2);
                }
                else
                {
                    return QString("Ch %1 Value").arg((section - 1)/2);
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

Fixtures::Fixtures( ShowDesigner *sd, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::Fixtures)
{
    mSd = sd;
    ui->setupUi(this);

    clearLayout(ui->hlChannelSliders);

    ui->hlChannelSliders->addLayout(new QChannelSlider("Red"));
    ui->hlChannelSliders->addLayout(new QChannelSlider("Green"));
    ui->hlChannelSliders->addLayout(new QChannelSlider("Blue"));
    ui->hlChannelSliders->addLayout(new QChannelSlider("Macro"));
    ui->hlChannelSliders->addLayout(new QChannelSlider("Strobe"));
    ui->hlChannelSliders->addLayout(new QChannelSlider("Dimmer"));

    FixtureModel *model = new FixtureModel();
    ui->tblFixtures->setModel(model);

    ui->tblFixtures->setColumnWidth(0,30);
    ui->tblFixtures->resizeColumnsToContents();
    for (int c = 2; c < ui->tblFixtures->horizontalHeader()->count(); ++c)
    {
        //ui->tblFixtures->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
    }
    ui->tblFixtures->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tblFixtures->resizeColumnsToContents();
}

Fixtures::~Fixtures()
{
    delete ui;
}

void Fixtures::on_ChannelValueChanged(int value)
{
    qDebug() << "Got channel slider changed " << value;
}
