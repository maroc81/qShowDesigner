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
    QChannelSlider(int number, QString name = "", QWidget *parent = 0);


    void SetChannelValue( int value );
    void SetName(QString name);
    QString GetName();
    void SetChannelNum( int number );
    int GetChannelNum();

    void Hide();
    void Show();

signals:
    // emitted when channel changed
    void valueChanged(int value, int num);

public slots:

    void onSliderMoved(int position);
    void onSliderChanged(int value);
    void onSpinBoxChanged(int value);


private:

    QSlider *mSlider;
    QLabel *mLabel;
    QSpinBox *mSpinBox;

    int mChannel;
    int mValue;
};

#endif // QCHANNELSLIDER_H
