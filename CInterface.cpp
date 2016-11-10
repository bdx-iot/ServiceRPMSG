#include "CInterface.h"

CInterface::CInterface()
{
    m_rpmsgCOM =  new CRpmsgCOM;
}

CInterface::~CInterface()
{
    delete m_rpmsgCOM;
}

double CInterface::getTemperature()
{
    return m_rpmsgCOM->getTemperature();
}

double CInterface::getPressure()
{
    return m_rpmsgCOM->getPressure();
}

quint32 CInterface::getHeartBeat()
{
    return m_rpmsgCOM->getHeartBeat();
}
