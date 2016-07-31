#include "QLineEditLabel.h"

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
    setReadOnly(false);
    setStyleSheet("");
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
