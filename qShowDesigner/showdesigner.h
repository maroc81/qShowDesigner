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

    bool SelectScene(int scene);
    bool RequestPageUp();
    bool RequestPageDown();
    bool RequestFixtures();
    bool RequestScenes(quint16 pageNo = 0);
    bool RequestPageNo();

    Fixture ToFixture(struct Response &resp);

signals:
    void pageChanged(quint16 pageNo);

protected:
    void run() Q_DECL_OVERRIDE;

private:

    void Decode(QByteArray &data);
    bool ProcessResp(struct Response &resp);
    bool ParseFixture(struct Response &resp);

    bool mRun;
    QSerialPort mPort;
    bool mIsConnected;
    QString mErrorString;
    QByteArray mReadData;
    QList<Fixture> mFixtures;

    struct Response mResp;

    // selected page number on the controller
    qint16 mPageNo;
    // selected scene
    int mSelectedScene;

};

#endif // SHOWDESIGNER_H
