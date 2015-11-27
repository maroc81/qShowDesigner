#ifndef FIXTURES_H
#define FIXTURES_H

#include <QDialog>
#include <QString>

#include <QAbstractTableModel>

#include "showdesigner.h"

namespace Ui {
class Fixtures;
}

class Fixtures : public QDialog
{
    Q_OBJECT

public:
    explicit Fixtures( ShowDesigner *sd, QWidget *parent = 0);
    ~Fixtures();

    QLayout* GetChannelSlider(QString name);

private slots:
    void on_ChannelValueChanged(int value);

private:
    Ui::Fixtures *ui;
    ShowDesigner *mSd;
};


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


};

#endif // FIXTURES_H
