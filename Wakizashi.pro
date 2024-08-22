QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analysis.cpp \
    analysiscontrol.cpp \
    main.cpp \
    mainwindow.cpp \
    tweaks.cpp

HEADERS += \
    analysis.h \
    analysiscontrol.h \
    mainwindow.h \
    tweaks.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += /usr/include/python3.10
#               /usr/include/pybind11


# Add the necessary libraries
LIBS += -L/usr/lib/python3.10/config-3.10-x86_64-linux-gnu -lpython3.10

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
