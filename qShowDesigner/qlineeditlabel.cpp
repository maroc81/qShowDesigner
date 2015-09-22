#include "qlineeditlabel.h"

QLineEditLabel::QLineEditLabel(QWidget *parent) : QLineEdit(parent)
{
    connect(this, SIGNAL(editingFinished()), this, SLOT(onEditFinished()));
}

void QLineEditLabel::showAsLabel()
{
    QString style = ""
        "border: none;"
        "background: lightgray;"
        "padding: 0 0px;";

    setReadOnly(true);
    setStyleSheet(style);
}

void QLineEditLabel::showAsLineEdit()
{
    QString style = ""\
            "border: 2px solid gray;"
            "border-radius: 2px;"
            "padding: 0 8px;"
            "background: white;"
            "selection-background-color: darkgray;";
    setReadOnly(false);
    setStyleSheet(style);
}

void QLineEditLabel::mouseDoubleClickEvent(QMouseEvent * event)
{
    if (isReadOnly())
    {
        showAsLineEdit();
        selectAll();
    }
    else
    {
        showAsLabel();
    }
}

void QLineEditLabel::onEditFinished()
{
    showAsLabel();
}
