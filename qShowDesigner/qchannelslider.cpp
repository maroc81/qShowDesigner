#include "qchannelslider.h"

#include <QtDebug>
#include <QSlider>
#include <QLabel>
#include <QSpinBox>

QChannelSlider::QChannelSlider(QString name, QWidget *parent) : QVBoxLayout(parent)
{
    // label with name of channel
    mLabel = new QLabel(name);

    // slider to allow setting channel value
    mSlider = new QSlider();
    mSlider->setMaximum(255);
    mSlider->setTickPosition(QSlider::TicksBothSides);

    // spin box with slider/channel value
    mSpinBox = new QSpinBox();
    mSpinBox->setMaximum(255);

    connect(mSlider, SIGNAL(sliderMoved(int)), this, SLOT(onSliderMoved(int)));
    connect(mSpinBox, SIGNAL(valueChanged(int)), this , SLOT(onSpinBoxChanged(int)));

    addWidget(mLabel, 0, Qt::AlignHCenter);
    addWidget(mSlider, 0, Qt::AlignHCenter);
    addWidget(mSpinBox);
}

void QChannelSlider::SetChannelValue(int value)
{
    if (mValue != value)
    {
        mValue = value;
        emit valueChanged(mValue);
        mSpinBox->setValue(value);
        mSlider->setValue(value);
    }
}

void QChannelSlider::onSliderMoved(int position)
{
    mSpinBox->setValue(position);
    SetChannelValue(position);
}

void QChannelSlider::onSpinBoxChanged(int value)
{
    mSlider->setValue(value);
    SetChannelValue(value);
}
