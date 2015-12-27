#include "fixture.h"

Fixture::Fixture() :
    mId(0),
    mName(""),
    mType(0)
{

}

Fixture::Fixture(quint8 id, QString name, quint8 type) :
    mId(id),
    mName(name),
    mType(type)
{

}

Fixture::~Fixture()
{

}

void Fixture::SetName(const QString &name)
{
    mName = name;
}

QString Fixture::GetName() const
{
    return mName;
}

void Fixture::SetChannelValue(int num, quint8 val)
{
    mChannels[num].mValue = val;
}

qint8 Fixture::GetChannelValue(int num) const
{
    return mChannels[num].mValue;
}

Fixture::Channel Fixture::GetChannel(int num) const
{
    return mChannels[num];
}

void Fixture::SetId(quint8 id)
{
    mId = id;
}

quint8 Fixture::GetId() const
{
    return mId;
}

void Fixture::SetType(quint8 type)
{
    mType = type;
}

quint8 Fixture::GetType() const
{
    return mType;
}

void Fixture::SetChannels(QMap<quint8, Channel> channels )
{
    mChannels = channels;
}

QMap<quint8, Fixture::Channel> Fixture::GetChannels() const
{
    return mChannels;
}

Fixture::Channel::Channel()
{

}

Fixture::Channel::~Channel()
{

}
