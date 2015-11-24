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
    //Fixture(struct Response resp);
    virtual ~Fixture();

    void SetName(const QString &name);
    QString GetName();

    void SetChannelValue(int num, qint8 val);
    qint8 GetChannelValue(int num);

    void SetId(quint8 id);
    quint8 GetId();

    void SetType(quint8 type);
    quint8 GetType();

    void SetChannels(QMap<quint8, Channel> channels );
    QMap<quint8, Channel> GetChannels();


private:
    QMap<quint8, Channel> mChannels;
    QString mName;
    quint8 mId;
    quint8 mType;
};

#endif // FIXTURE_H
