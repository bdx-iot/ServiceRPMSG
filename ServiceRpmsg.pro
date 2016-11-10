QT += core dbus
QT -= gui

CONFIG += c++11

TARGET = ServiceRpmsg
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    COM/CRpmsgCOM.cpp \
    CInterface.cpp

HEADERS += \
    COM/CRpmsgCOM.h \
    CInterface.h
