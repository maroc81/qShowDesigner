#ifndef FIXTURE_H
#define FIXTURE_H

#include <QString>
#include <QMap>

class Fixture
{
public:
    class Channel
    {
    public:
        Channel();
        virtual ~Channel();

        QString mName;
        quint8 mValue;
        quint8 mNum;
    };

    Fixture();
    virtual ~Fixture();

    void SetName(const QString &name);
    QString GetName();

    void SetChannelValue(int num, qint8 val);
    qint8 GetChannelValue(int num);

private:
    QMap<quint8, Channel> mChannels;
    QString mName;
};

#endif // FIXTURE_H
