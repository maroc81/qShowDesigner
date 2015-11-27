#ifndef QCHANNELSLIDER_H
#define QCHANNELSLIDER_H

#include <QVBoxLayout>
#include <QString>

class QSlider;
class QLabel;
class QSpinBox;

class QChannelSlider : public QVBoxLayout
{
    Q_OBJECT

public:
    QChannelSlider(QString name = "", QWidget *parent = 0);


    void SetChannelValue( int value );

signals:
    // emitted when channel changed
    void valueChanged(int value);

public slots:

    void onSliderMoved(int position);
    void onSpinBoxChanged(int value);


private:

    QSlider *mSlider;
    QLabel *mLabel;
    QSpinBox *mSpinBox;

    int mValue;
};

#endif // QCHANNELSLIDER_H
