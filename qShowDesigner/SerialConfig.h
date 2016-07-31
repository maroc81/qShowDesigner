#ifndef SERIALCONFIG_H
#define SERIALCONFIG_H

#include <QDialog>

namespace Ui {
class SerialConfig;
}

class SerialConfig : public QDialog
{
    Q_OBJECT

public:
    explicit SerialConfig(QWidget *parent = 0);
    ~SerialConfig();

    QString GetPort();

protected:

    void showEvent(QShowEvent * event);


private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::SerialConfig *ui;
};

#endif // SERIALCONFIG_H
