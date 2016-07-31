#ifndef QLINEEDITLABEL_H
#define QLINEEDITLABEL_H

#include <QWidget>
#include <QLineEdit>


class QLineEditLabel : public QLineEdit
{
    Q_OBJECT
public:
    explicit QLineEditLabel(QWidget *parent = 0);

    void showAsLabel();
    void showAsLineEdit();

    void mouseDoubleClickEvent(QMouseEvent * event);

signals:

public slots:
    void onEditFinished();

private:

};

#endif // QLINEEDITLABEL_H
