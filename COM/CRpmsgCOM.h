#ifndef CRPMSGCOM_H
#define CRPMSGCOM_H

#include <QFile>
#include <QDebug>

#define RPMSG_TTY   "/dev/ttyRPMSG"

class CRpmsgCOM
{
public:
    CRpmsgCOM();
    ~CRpmsgCOM();

public:
    /**
      * GETTERS
      **/
    double       getTemperature();
    double       getPressure();
    quint32     getHeartBeat();

protected:
    QByteArray read(QByteArray request);

private:
    QFile   *m_rpmsgTTY;
};

#endif // CRPMSGCOM_H
