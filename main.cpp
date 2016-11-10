#include <QCoreApplication>
#include <QtDBus/QDBusConnection>
#include <QDebug>

#include "CInterface.h"

#define SERVICE_NAME        "org.opensilicium.service.rpmsg"
#define PROPERTY_PATH       "/"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /**
      * DBUS INIT
      **/
    if (!QDBusConnection::systemBus().isConnected())
    {
        qDebug() << "DBUS not started !";
    }
    if (!QDBusConnection::systemBus().registerService(SERVICE_NAME))
    {
        qDebug() << " Already Registered !";
    }

    //disk info
    CInterface *interface = new CInterface();
    QDBusConnection::systemBus().registerObject(PROPERTY_PATH,
                                               interface,
                                               QDBusConnection::ExportAllInvokables);

    return a.exec();
}
