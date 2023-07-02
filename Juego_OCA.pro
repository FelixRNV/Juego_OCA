QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    inicio.cpp \
    main.cpp \
    juego_oca.cpp \
    newjuego.cpp \
    newtematica.cpp \
    puntajes.cpp \
    selecjugadores.cpp \
    tematicas.cpp \
    tipodejuego.cpp

HEADERS += \
    inicio.h \
    juego_oca.h \
    newjuego.h \
    newtematica.h \
    puntajes.h \
    selecjugadores.h \
    tematicas.h \
    tipodejuego.h

FORMS += \
    inicio.ui \
    juego_oca.ui \
    newjuego.ui \
    newtematica.ui \
    puntajes.ui \
    selecjugadores.ui \
    tematicas.ui \
    tipodejuego.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
