#include "CRpmsgCOM.h"

CRpmsgCOM::CRpmsgCOM()
{
    m_rpmsgTTY =  new QFile(RPMSG_TTY);
    if (m_rpmsgTTY->open(QIODevice::ReadWrite))
    {
        qDebug() << "Open Rpmsg tty Successful";
    }
}

CRpmsgCOM::~CRpmsgCOM()
{
    if (m_rpmsgTTY->isOpen())
        m_rpmsgTTY->close();

    delete m_rpmsgTTY;
}

double CRpmsgCOM::getTemperature()
{
    QByteArray response;
    response = read("getTemperature");
    if (!response.isEmpty())
    {
        return response.toFloat();
    }
    else
    {
        qDebug() << "Couldn't read temperature";
        return 0;
    }
}

double CRpmsgCOM::getPressure()
{
    QByteArray response;
    response = read("getPressure");
    if (!response.isEmpty())
    {
        return response.toFloat();
    }
    else
    {
        qDebug() << "Couldn't read Pressure";
        return 0;
    }
}

quint32 CRpmsgCOM::getHeartBeat()
{
    QByteArray response;
    response = read("getHeartbeat");
    if (!response.isEmpty())
    {
        return response.toInt();
    }
    else
    {
        qDebug() << "Couldn't read HeartBeat";
        return 0;
    }
}

QByteArray CRpmsgCOM::read(QByteArray request)
{

}
