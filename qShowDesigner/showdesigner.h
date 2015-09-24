#ifndef SHOWDESIGNER_H
#define SHOWDESIGNER_H

#include <QThread>
#include <QSerialPort>
#include <QString>
#include <QList>
#include <QByteArray>

class ShowDesigner : public QThread
{

    Q_OBJECT

public:

    class Channel
    {
    public:
        Channel();
        virtual ~Channel();

    private:
        QString mName;
        quint8 mValue;
        quint8 mNum;
    };

    /**
     * @brief Container class for fixture data.
     *
     */
    class Fixture
    {
    public:
        Fixture();
        virtual ~Fixture();
        void SetChannel(int num, qint8 val);
        qint8 GetChannel(int num);
        void SetName(const QString &name);
        QString GetName();
    private:
        QList<Channel> mChannels;
        QString mName;
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


signals:

    void pageChanged(quint16 pageNo);

protected:
    void run() Q_DECL_OVERRIDE;

private:

    struct ShowDesignerResponse
    {
        quint8 start;
        quint8 cmd;
        qint16 length;
        QByteArray payload;
    };

    void Decode(QByteArray &data);
    bool ProcessResp(struct ShowDesignerResponse &resp);
    bool ParseFixture(struct ShowDesignerResponse &resp);

    bool mRun;
    QSerialPort mPort;
    bool mIsConnected;
    QString mErrorString;
    QByteArray mReadData;
    QList<Fixture> mFixtures;

    struct ShowDesignerResponse mResp;

    // selected page number on the controller
    qint16 mPageNo;
    // selected scene
    int mSelectedScene;

};

#endif // SHOWDESIGNER_H
