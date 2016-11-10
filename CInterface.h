#ifndef CINTERFACE_H
#define CINTERFACE_H

#include <QObject>

#include "COM/CRpmsgCOM.h"

class CInterface : public QObject
{
    Q_OBJECT
public:
    CInterface();
    ~CInterface();

public:
    Q_INVOKABLE double      getTemperature();
    Q_INVOKABLE double      getPressure();
    Q_INVOKABLE quint32     getHeartBeat();

private:
    CRpmsgCOM   *m_rpmsgCOM;
};

#endif // CINTERFACE_H
