#include "showdesigner.h"


#include <QtDebug>
#include <QThread>

#define START_BYTE          ((char)0xa5)

#define CMD_ID_START        0x01
#define CMD_ID_PAGENO       0x02
#define CMD_ID_SCENES       0x03
#define CMD_ID_FIXTURES     0x04
#define CMD_ID_SETCHAN      0x08
#define CMD_ID_IDK          0x0b     // don't yet know what this id does but have seen the SD software use it
#define CMD_ID_PAGEUPDN     0x0d
#define CMD_ID_FUNCTION     0x0e
#define CMD_ID_BTN          0x0f

ShowDesigner::ShowDesigner(QObject *parent) :
    QThread(parent),
    mRun(false),
    mPort(this),
    mIsConnected(false),
    mPageNo(-1),
    mPushedButton(-1)
{

}

ShowDesigner::~ShowDesigner()
{
    mRun = false;
    QThread::msleep(100);
}

/**
 * @brief ShowDesigner::ConnectToShowDesigner
 * Performs connect sequence to establish connection to the
 * show designer lighting controller
 * @param port QString containing the port name
 * @return
 */
bool ShowDesigner::ConnectToShowDesigner(const QString &port)
{
    char req1[] = { 0x55, 0x25, 0x05 };
    char req2[] = { START_BYTE, CMD_ID_START };

    // stop the receive thread if it's running
    mRun = false;
    if (!wait(1000UL))
    {
        qDebug() << "Read thread failed to exit";
    }

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
    // 10. If connect sequence hasn't been performed
    //     since last power on we read 0x55 0x25 0x05
    // 11. Read 0xa5 0x01

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
    // read up to 5 characters
    while ( dataFromSd.length() < 5 )
    {
        if (!mPort.waitForReadyRead(1000))
        {
            break;
        }
        dataFromSd.append(mPort.readAll());
    }

    qDebug() << "Read response from lighting controller " << dataFromSd.toHex();
    if ( dataFromSd.length() == 0 )
    {
        mErrorString = "Read failed: timed out waiting for connect response from lighting controller";
        qDebug() << Q_FUNC_INFO << mErrorString;
        return false;
    }
    QByteArray cmp(req2, 2);
    if ( dataFromSd.endsWith(cmp))
    {
        mErrorString = "Connection to show designer succeeded";
        qDebug() << Q_FUNC_INFO << mErrorString;
        mIsConnected = true;
        // start the read thread now that the port is open and connected
        start();
        // request the current page number
        RequestPageNo();
        return true;
    }
    else
    {
        mErrorString = "Invalid response from show designer";
        qDebug() << Q_FUNC_INFO << mErrorString << ": " << dataFromSd.toHex();
        mIsConnected = false;
        return false;
    }

    return false;
}

/**
 * @brief ShowDesigner::run
 * Thread that reads and decodes output from Show Designer
 */
void ShowDesigner::run()
{
    mRun = true;
    while (mRun)
    {
        if (mPort.waitForReadyRead(100))
        {
            QByteArray readData = mPort.readAll();
            Decode(readData);
        }
    }
}

void ShowDesigner::Decode(QByteArray &data)
{
    enum decode_states {
        eDecodeStart = 0,
        eDecodeCmd,
        eDecodeLengthLow,
        eDecodeLengthHigh,
        eDecodePayload
    };

    static enum decode_states state = eDecodeStart;

    char b;
    foreach(b, data )
    {
        switch( state )
        {
        case eDecodeStart:
            if (b == START_BYTE)
            {
                mResp.start = b;
                state = eDecodeCmd;
            }
            break;

        case eDecodeCmd:
            mResp.cmd = b;
            if (mResp.cmd == CMD_ID_START)
            {
                // the start command has no payload
                state = eDecodeCmd;
            }
            else
            {
                state = eDecodeLengthLow;
            }
            break;

        case eDecodeLengthLow:
            mResp.length = b;
            state = eDecodeLengthHigh;
            break;

        case eDecodeLengthHigh:
            mResp.length |= b << 8;
            if (mResp.length > 2048 || mResp.length < 1 )
            {
                qDebug() << "Command length " << mResp.length << " is invalid";
                state = eDecodeStart;
            }
            else
            {
                mResp.payload.clear();
                state = eDecodePayload;
            }
            break;

        case eDecodePayload:
            mResp.payload.append(b);
            if ( mResp.payload.size() >= mResp.length )
            {
                ProcessResp(mResp);
                state = eDecodeStart;
            }
            break;

        default:
            state = eDecodeStart;
            break;
        }
    }
    data.clear();
}

bool ShowDesigner::ProcessResp(Response &resp)
{
    qDebug() << "Processing response for command " << resp.cmd << " with payload " << resp.payload.toHex();

    switch (resp.cmd)
    {
    case CMD_ID_PAGENO:
        if (resp.payload.length() == 2)
        {
            mPageNo = ((quint16)resp.payload[0]) << 8;
            mPageNo |= ((quint16)resp.payload[1]);
            mPageNo++;
            // emit signal whether page number actually changed
            emit pageChanged(mPageNo);
        }
        else
        {
            qDebug() << "Invalid length " << resp.payload.length() << " for response id: " << resp.cmd;
        }
        break;

    case CMD_ID_FIXTURES:
    {
        Fixture fix;
        if ( ToFixture( resp, fix ))
        {
            // add fixture to list of fixtures
        }

        break;
    }
    case CMD_ID_SCENES:

        break;

    case CMD_ID_FUNCTION:
        if (resp.payload.length() == 1)
        {
            char func = resp.payload[0];
            mFunc = (enum Functions) func;
        }
        else
        {
            qDebug() << "Invalid length " << resp.payload.length() << " for response id: " << resp.cmd;
        }
    }
    return false;
}


QString ShowDesigner::GetErrorString() const
{
    return mErrorString;
}

quint16 ShowDesigner::GetPageNo()
{
    return mPageNo;
}

bool ShowDesigner::SendCmd(const char *data, qint64 count)
{
    qint64 retval;

    if (!mPort.isOpen())
    {
        mErrorString = "Failed to send command: Port not open";
        qDebug() << Q_FUNC_INFO << mErrorString;
        return false;
    }

    retval = mPort.write(data, count);
    if (retval != count )
    {
        mErrorString = "Failed to send command: " + mPort.errorString();
        qDebug() << Q_FUNC_INFO << mErrorString;
        return false;
    }
    return true;
}

/**
 * @brief ShowDesigner::PushButton "pushes" a numbered button on the show designer.
 *
 * @param button the button number to push
 * @return
 */
bool ShowDesigner::PushButton(int button)
{
    // TODO: add option to check if button is already pushed and
    // prevent pushing again to prevent going "black" when in scene mode

    // send push button sequence
    const char cmd[] = {START_BYTE, CMD_ID_BTN, (char)(((quint8)button) - 1), 0x00};
    return SendCmd(cmd, sizeof(cmd));
}


bool ShowDesigner::RequestPageUp()
{
    // send page up command
    const char cmd[] = {START_BYTE, CMD_ID_PAGEUPDN, (char)0xff};
    return SendCmd(cmd, sizeof(cmd));
}

bool ShowDesigner::RequestPageDown()
{
    // send page down command
    const char cmd[] = {START_BYTE, CMD_ID_PAGEUPDN, 0x00};
    return SendCmd(cmd, sizeof(cmd));
}

bool ShowDesigner::RequestFixtures()
{
    // send fixtures command
    const char cmd[] = {START_BYTE, CMD_ID_FIXTURES, (char)0xff};
    return SendCmd(cmd, sizeof(cmd));
}

bool ShowDesigner::RequestScenes(quint16 pageNo)
{
    // send scenes command
    if (pageNo == 0)
    {
        pageNo = mPageNo;
    }
    if (pageNo == 0)
    {
        pageNo = 1;
    }
    pageNo = pageNo - 1;
    const char cmd[] = {START_BYTE, CMD_ID_SCENES, (char)(pageNo >> 8), (char)( pageNo & 0xff)};
    return SendCmd(cmd, sizeof(cmd));
}

bool ShowDesigner::RequestPageNo()
{
    // send get page no command
    const char cmd[] = {START_BYTE, CMD_ID_PAGENO};
    return SendCmd(cmd, sizeof(cmd));
}

bool ShowDesigner::SelectFunction(Functions func)
{
    const char cmd[] = {START_BYTE, CMD_ID_FUNCTION, (char) func};
    return SendCmd(cmd, sizeof(cmd));
}

bool ShowDesigner::ToFixture(Response &resp, Fixture &fix)
{
    // fixture response with at least 1 channel is 70 bytes long
    // fixture ids/buttons that aren't assigned will be less than 70 bytes
    if (resp.length < 70)
    {
        qDebug() << Q_FUNC_INFO << " Invalid length of fixture response: " << resp.length;
        return false;
    }

    fix.SetId(resp.payload[0]);
    fix.SetType(resp.payload[1]);

    quint16 numChannels = resp.payload.mid(2,2).toUShort();
    QString name = QString::fromStdString( resp.payload.mid(13,16).toStdString() );
    fix.SetName( name );

    qDebug() << Q_FUNC_INFO << " Read fixture with name: " << fix.GetName() << " id: " << fix.GetId() << " type: " << fix.GetType();

    // channels are 8 bytes each and start at byte 62
    if ( (numChannels * 8 ) + 62  < resp.length)
    {
        qDebug() << Q_FUNC_INFO << "Invalid length: " << resp.length << " for number of channels: " << numChannels;
        return false;
    }

   /* QMap<quint8, Fixture::Channel> channels;
    for ( int i = 0; i << numChannels; i++ )
    {
        channels[]
    }*/

    return true;
}

