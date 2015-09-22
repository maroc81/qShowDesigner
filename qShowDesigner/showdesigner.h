#ifndef SHOWDESIGNER_H
#define SHOWDESIGNER_H

#include <QObject>
#include <QSerialPort>
#include <QString>
#include <QList>

class ShowDesigner : public QObject
{

    Q_OBJECT

public:

    /**
     * @brief Container class for fixture data.
     *
     */
    /*class Fixture
    {
    public:
        Fixture();
        virtual ~Fixture();
        void SetChannel(int num, qint8 val);
        qint8 GetChannel(int num);
        void SetName(const QString &name);
        QString GetName();
    private:
        QList<qint8> channels;
        QString name;
    };*/

    explicit ShowDesigner(QObject *parent = 0);
    ~ShowDesigner();

    bool ConnectToShowDesigner(const QString &port);
    bool SelectScene(int scene);
    QString GetErrorString() const;

    bool ReadFixtures();
    bool ParseFixture(QList<char> chars);

private:

    QSerialPort mPort;
    int mSelectedScene;
    bool mIsConnected;
    QString mErrorString;
    //QList<Fixture> mFixtures;

};

#endif // SHOWDESIGNER_H
