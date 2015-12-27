#ifndef FIXTURES_H
#define FIXTURES_H

#include <QDialog>
#include <QString>

#include <QAbstractTableModel>

#include "showdesigner.h"

namespace Ui {
class Fixtures;
}


class FixtureModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    FixtureModel(QObject *parent = 0);
    ~FixtureModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;


    void SetFixtures(QMap<quint8,Fixture> fixtures);
    void UpdateFixture(Fixture &fixture);
    void UpdateChannel(Fixture &fixture, Fixture::Channel &channel);
    QMap<quint8,Fixture> GetFixtures();
    QMap<quint8,Fixture> GetSelectedFixtures();

signals:
    void fixtureSelected();

private:

    QMap<quint8,Fixture> mFixtures;
    QMap<quint8,bool> mSelected;
};

class Fixtures : public QDialog
{
    Q_OBJECT

public:
    explicit Fixtures( ShowDesigner *sd, QWidget *parent = 0);
    ~Fixtures();

    QLayout* GetChannelSlider(QString name);

public slots:
    void on_ChannelValueChanged(int value, int num);
    void on_FixtureSelected();
    void on_FixturesChanged();
    void on_FixtureChanged( Fixture fixture );
    void on_ChannelChanged( Fixture fixture, Fixture::Channel channel);


private slots:
    void on_btnRefresh_released();

    void on_btnRefresh_clicked();

    void on_Fixtures_destroyed();

private:
    Ui::Fixtures *ui;
    ShowDesigner *mSd;
    FixtureModel *mModel;
};



#endif // FIXTURES_H
