#ifndef SHOWDESIGNER_H
#define SHOWDESIGNER_H

#include "fixture.h"

#include <QThread>
#include <QSerialPort>
#include <QString>
#include <QList>
#include <QByteArray>
#include <QMutex>

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

    // flag to indicate thread is running/should exit
    bool mRun;
    // serial port object to communicate with show designer
    QSerialPort mPort;
    // true if serial port is open and has been connected to show designer
    bool mIsConnected;
    // string containing last error message
    QString mErrorString;
    // array of bytes read from serial port
    QByteArray mReadData;
    // response struct used in decoding serial port data
    struct Response mResp;

    // mutex for serializing access to serial port object
    mutable QMutex mMutex;

    // map of fixture objects
    QMap<quint8,Fixture> mFixtures;
    // map of selected buttons
    QMap<quint8, bool> mSelectedButtons;
    // map of scenes
    QMap<quint8, QString> mScenes;
    // selected page number on the controller
    qint8 mPageNo;
    // the actively selected function on the show designer
    enum ActiveFunction mActiveFunc;
    // current function
    enum Functions mFunc;
    // last button "pushed"
    int mPushedButton;
    // selected scene
    int mSelectedScene;

};

#endif // SHOWDESIGNER_H
