#include "fixture.h"

Fixture::Fixture()
{

}

Fixture::~Fixture()
{

}

void Fixture::SetName(const QString &name)
{
    mName = name;
}

QString Fixture::GetName()
{
    return mName;
}

void Fixture::SetChannelValue(int num, qint8 val)
{
    Channel chan = mChannels[num];
    chan.mValue = val;
}

qint8 Fixture::GetChannelValue(int num)
{
    return mChannels[num].mValue;
}

void Fixture::SetId(quint8 id)
{
    mId = id;
}

quint8 Fixture::GetId()
{
    return mId;
}

void Fixture::SetType(quint8 type)
{
    mType = type;
}
quint8 Fixture::GetType()
{
    return mType;
}

Fixture::Channel::Channel()
{

}

Fixture::Channel::~Channel()
{

}
