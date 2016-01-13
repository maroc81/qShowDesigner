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
    Fixture(quint8 id, QString name, quint8 type);
    virtual ~Fixture();

    void SetName(const QString &name);
    QString GetName() const;

    void SetChannelValue(int num, quint8 val);
    qint8 GetChannelValue(int num) const;
    Channel GetChannel(int num) const;

    void SetId(quint8 id);
    quint8 GetId() const;

    void SetType(quint8 type);
    quint8 GetType() const;

    void SetChannels(QMap<quint8, Channel> channels );
    QMap<quint8, Channel> GetChannels() const;


private:
    QMap<quint8, Channel> mChannels;
    quint8 mId;
    QString mName;
    quint8 mType;
};

#endif // FIXTURE_H
