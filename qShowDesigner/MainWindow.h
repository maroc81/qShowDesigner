#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSettings>

#include "ShowDesigner.h"
#include "FixturesWindow.h"

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_action_Connect_triggered();

    void on_actionExit_triggered();

    void on_actionAlways_on_top_triggered();

    void on_actionFixtures_triggered();

    void on_btnDown_clicked();

    void on_btnUp_clicked();

    void on_btn_num_released();

    void on_editing_finished();

    void on_page_changed(quint16 pageNo);

private:
    void ShowErrorMessage(const QString &text, const QString &informativeText = "");
    void Save();

    Ui::MainWindow *ui;
    ShowDesigner mSd;
    QLabel *mStatusLabel;
    QSettings mSettings;
    FixturesWindow* mFixtureDialog;

};

#endif // MAINWINDOW_H
