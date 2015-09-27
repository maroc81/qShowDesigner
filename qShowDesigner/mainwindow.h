#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSettings>

#include "showdesigner.h"

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

    void on_btn_num_released();

    void on_actionAlways_on_top_triggered();

    void on_editing_finished();

    void on_page_changed(quint16 pageNo);

    void on_btnDown_clicked();

    void on_btnUp_clicked();

private:
    void ShowErrorMessage(const QString &text, const QString &informativeText = "");
    void Save();

    Ui::MainWindow *ui;
    ShowDesigner mSd;
    QLabel *mStatusLabel;
    QSettings mSettings;

};

#endif // MAINWINDOW_H
