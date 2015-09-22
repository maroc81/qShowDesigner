#include "showdesigner.h"


#include <QtDebug>
#include <QThread>


ShowDesigner::ShowDesigner(QObject *parent) :
    QObject(parent),
    mPort(this),
    mSelectedScene(-1),
    mIsConnected(false)
{

}

ShowDesigner::~ShowDesigner()
{

}

bool ShowDesigner::ConnectToShowDesigner(const QString &port)
{
    char req1[] = { 0x55, 0x25, 0x05 };
    char req2[] = { 0xa5, 0x01 };
    char resp[3];

    if ( mPort.isOpen() )
    {
        mPort.close();
    }

    qDebug() << "Opening port..";
    mPort.setPortName(port);
    mPort.setBaudRate(QSerialPort::Baud38400);
    mPort.setDataBits(QSerialPort::Data8);
    mPort.setStopBits(QSerialPort::OneStop);
    mPort.setParity(QSerialPort::NoParity);
    mPort.setFlowControl(QSerialPort::NoFlowControl);

    if (!mPort.open( QIODevice::ReadWrite))
    {
        mErrorString = mPort.errorString();
        qDebug() << "Failed to open port " << port << " Error: " << mPort.errorString();
        return false;
    }

    // clear any data still in the output or input buffers
    if ( !mPort.clear() )
    {
        mErrorString = "Failed to clear port before connecting " + mPort.errorString();
        qDebug() << Q_FUNC_INFO << mErrorString;
    }

    // when the windows show designer software connects
    // it opens the com port, sets baud to 1200 and data to 7 bits
    // clears RTS and sends a sequence of characters
    // it then sets port back to 38400 and 8 bits then clears RTS
    // and sends a final sequence

    // 1. Configure port and open
    // 2. Set baud to 1200 and 7 data bits
    // 3. Set RTS true
    // 4. Clear RTS
    // 5. Send 0x55 0x25 0x5
    // 6. Set baud to 38400 and 8 data bits
    // 7. Wait 1 second
    // 8. Set RTS false (twice, don't know why)
    // 9. Send 0xa5 0x01
    // 10. Read 0xa5 0x01

    mPort.setBaudRate(QSerialPort::Baud1200);
    mPort.setDataBits(QSerialPort::Data7);
    mPort.setRequestToSend(true);
    mPort.setRequestToSend(false);
    mPort.write( req1, sizeof( req1 ));
    mPort.waitForBytesWritten(1000);
    QThread::msleep(1000);

    mPort.setBaudRate(QSerialPort::Baud38400);
    mPort.setDataBits(QSerialPort::Data8);
    // dont' know why but strace and usb monitor
    // show the sd monitor program setting RTS false twice
    mPort.setRequestToSend(false);
    mPort.setRequestToSend(false);
    mPort.write( req2, sizeof( req2 ));


    QByteArray dataFromSd;
    while ( dataFromSd.length() < 2 )
    {
        if (!mPort.waitForReadyRead(100))
        {
            mErrorString = "Read failed: timed out waiting for connect response from lighting controller";
            qDebug() << Q_FUNC_INFO << mErrorString;
            return false;
        }
        QByteArray tmpba = mPort.readAll();
        dataFromSd.append(tmpba);
        if ( dataFromSd.length() == 0 )
        {
            mErrorString = "Read failed: read from lighting controller failed";
            qDebug() << Q_FUNC_INFO << mErrorString;
            return false;
        }
    }

    qDebug() << "Read response from lighting controller " << dataFromSd;
    QByteArray cmp(req2, 2);
    if ( dataFromSd.startsWith(cmp))
    {
        mErrorString = "Connection to show designer succeeded";
        qDebug() << Q_FUNC_INFO << mErrorString;
        mIsConnected = true;
        return true;
    }

    return false;
}

\

/**
 * @brief ShowDesigner::SelectScene
 *
 * @param scene
 * @return
 */
bool ShowDesigner::SelectScene(int scene)
{
    qint64 retval;

    // TODO: check if scene is already selected and
    // prevent reselection in case that makes the scene go black

    // clear any data still in the output or input buffers
    if ( !mPort.clear() )
    {
        mErrorString = "Failed to clear port before selecting scene " + mPort.errorString();
        qDebug() << Q_FUNC_INFO << mErrorString;
    }

    // send select scene sequence
    // 0xa5 0x0f <scene no minus 1> 0x00
    // 0x0f may correspond to the page number
    char data[2048] = {0xa5, 0x0f, scene - 1, 0x00};

    retval = mPort.write(data, 4);
    if (retval != 4 )
    {
        mErrorString = "Write failed: can't select scene " + mPort.errorString();
        qDebug() << Q_FUNC_INFO << mErrorString;
        return false;
    }

    // after a scene is selected, it triggers a dump of the
    // fixtures if fixture monitoring is enabled

    return true;
}

QString ShowDesigner::GetErrorString() const
{
    return mErrorString;
}

bool ShowDesigner::ReadFixtures()
{
    char data[2048] = {0};

    //show designer responds with
    // 0xa5 0x09 0x03 0x90 0x00 0xff
    // plus a long sequence that may be the fixture
    // channel settings after the scene is set
    if (!mPort.waitForReadyRead(1000))
    {
        qDebug() << Q_FUNC_INFO << "Read failed: timed out waiting for response from lighting controller";
        return false;
    }

    int retval = mPort.read(data, sizeof(data));
    if (retval <= 0)
    {
        qDebug() << Q_FUNC_INFO << "Read data failed: readData returned " << retval;
        qDebug() << mPort.errorString();
    }

    char resp[] = { 0xa5, 0x09, 0x03, 0x90, 0x00, 0xff };

    QByteArray qData(data, retval);
    QByteArray qResp(resp, sizeof(resp));

    QByteArray qHex = qData.toHex();

    qDebug() << Q_FUNC_INFO << qHex.toStdString().c_str();

    if (qData.startsWith(qResp))
    {
        //qDebug() << Q_FUNC_INFO << "Scene " << scene <<" selected successfully";
        //mSelectedScene = scene;
        return true;
    }
    else
    {
        //qDebug() << Q_FUNC_INFO << "Scene " << scene << " NOT selected successfully";
        return false;
    }
}

bool ShowDesigner::ParseFixture(QList<char> chars)
{

}
