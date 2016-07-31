#ifndef FIXTURESWINDOW_H
#define FIXTURESWINDOW_H

#include <QDialog>
#include <QString>
#include <QSettings>

#include "ShowDesigner.h"
#include "FixturesModel.h"

namespace Ui {
class FixturesWindow;
}

/**
 * @brief The FixturesWindow class provies a Window (dialog really) to
 * show all of the fixtures and their properties.
 */
class FixturesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FixturesWindow( ShowDesigner *sd, QWidget *parent = 0);
    ~FixturesWindow();

    QLayout* GetChannelSlider(QString name);

public slots:
    void on_ChannelValueChanged(int value, int num);
    void on_FixtureSelected();
    void on_FixturesChanged();
    void on_FixtureChanged( quint8 fixId );
    void on_ChannelChanged( quint8 fixId, quint8 channelNum);

protected:
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    void moveEvent(QMoveEvent *event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_btnRefresh_released();

    void on_btnRefresh_clicked();

    void on_Fixtures_destroyed();

private:
    Ui::FixturesWindow *ui;
    ShowDesigner *mSd;
    FixturesModel *mModel;
    QSettings mSettings;
};



#endif // FIXTURESWINDOW_H
