#ifndef FIXTURESMODEL_H
#define FIXTURESMODEL_H

#include <QAbstractTableModel>

#include "Fixture.h"

class FixturesModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    FixturesModel(QObject *parent = 0);
    ~FixturesModel();

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


#endif // FIXTURESMODEL_H
