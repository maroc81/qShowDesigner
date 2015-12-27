#include "qchannelslider.h"

#include <QtDebug>
#include <QSlider>
#include <QLabel>
#include <QSpinBox>

QChannelSlider::QChannelSlider(int number, QString name, QWidget *parent) : QVBoxLayout(parent),
    mChannel(number)
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
    connect(mSlider, SIGNAL(valueChanged(int)), this, SLOT(onSliderChanged(int)));
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
        emit valueChanged(mValue, mChannel);
        mSpinBox->setValue(value);
        mSlider->setValue(value);
    }
}

void QChannelSlider::SetName(QString name)
{
    mLabel->setText(name);
}

QString QChannelSlider::GetName()
{
    return mLabel->text();
}

void QChannelSlider::Hide()
{
    mLabel->hide();
    mSlider->hide();
    mSpinBox->hide();
}

void QChannelSlider::Show()
{
    mLabel->show();
    mSlider->show();
    mSpinBox->show();
}

void QChannelSlider::onSliderMoved(int position)
{
    mSpinBox->setValue(position);
    SetChannelValue(position);
}

void QChannelSlider::onSliderChanged(int value)
{
    mSpinBox->setValue(value);
    SetChannelValue(value);
}

void QChannelSlider::onSpinBoxChanged(int value)
{
    mSlider->setValue(value);
    SetChannelValue(value);
}
