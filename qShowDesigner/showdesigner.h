#ifndef SHOWDESIGNER_H
#define SHOWDESIGNER_H

#include "fixture.h"

#include <QThread>
#include <QSerialPort>
#include <QString>
#include <QList>
#include <QByteArray>

class ShowDesigner : public QThread
{

    Q_OBJECT

public:

    enum Functions
    {
        eUnknown = -1,
        eScene = 0,
        eFixture = 4,
        eFixtureGroup = 5
    };

    enum ActiveFunction
    {
        eActiveFuncInvalid = -1,
        eActiveFuncScene = 0x00,
        eActiveFuncShow = 0x01,
        eActiveFuncPreset = 0x02,
        eActiveFuncChase = 0x04,
        eActiveFuncFixture = 0x06,
        eActiveFuncFixtureGroup = 0x07,
        eActiveFuncNone = 0xff
    };

    struct Response
    {
        quint8 start;
        quint8 cmd;
        qint16 length;
        QByteArray payload;
    };

    explicit ShowDesigner(QObject *parent = 0);
    ~ShowDesigner();

    bool ConnectToShowDesigner(const QString &port);

    QString GetErrorString() const;
    quint16 GetPageNo();

    bool SendCmd(const char *data, qint64 count);
    bool PushButton(int button);
    bool SelectScene(int scene);
    bool RequestPageUp();
    bool RequestPageDown();
    bool RequestFixtures();
    bool SetFixtureChannel(quint8 fixNum, quint8 channel, quint8 value);
    bool RequestScenes(quint16 pageNo = 0);
    bool RequestPageNo();
    bool SelectFunction( enum Functions func);

    bool ToFixture(Response &resp, Fixture &fix);
    void SetFixtures(QMap<quint8,Fixture> fixtures);
    QMap<quint8,Fixture> GetFixtures();
    Fixture GetFixtureByNum(quint8 fixNum);



    void Decode(QByteArray &data);
    void test();

signals:
    void pageChanged(quint16 pageNo);
    void fixturesChanged();
    void fixtureChanged(quint8 fixId);
    void channelChanged(quint8 fixId, quint8 channelNum);

protected:
    void run() Q_DECL_OVERRIDE;

private:

    bool ProcessResp(struct Response &resp);
    bool ParseFixture(struct Response &resp);

    bool mRun;
    QSerialPort mPort;
    bool mIsConnected;
    QString mErrorString;
    QByteArray mReadData;
    QMap<quint8,Fixture> mFixtures;

    struct Response mResp;

    // selected page number on the controller
    qint8 mPageNo;
    enum ActiveFunction mActiveFunc;
    // last button "pushed"
    int mPushedButton;
    // selected scene
    int mSelectedScene;
    // current function
    enum Functions mFunc;

};

#endif // SHOWDESIGNER_H
