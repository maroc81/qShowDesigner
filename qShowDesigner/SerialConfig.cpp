#include "SerialConfig.h"
#include "ui_SerialConfig.h"

#include <QSerialPortInfo>

SerialConfig::SerialConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialConfig)
{
    ui->setupUi(this);
}

SerialConfig::~SerialConfig()
{
    delete ui;
}

QString SerialConfig::GetPort()
{
    return ui->cmbSerialPorts->currentText();
}


void SerialConfig::showEvent(QShowEvent * event)
{
    QList<QSerialPortInfo>	ports = QSerialPortInfo::availablePorts();
    QSerialPortInfo portInfo;
    foreach(portInfo, ports)
    {
        ui->cmbSerialPorts->addItem(portInfo.portName());
    }
}

void SerialConfig::on_buttonBox_rejected()
{

}

void SerialConfig::on_buttonBox_accepted()
{

}
