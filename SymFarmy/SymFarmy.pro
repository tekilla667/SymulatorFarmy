QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cfarmer.cpp \
    chektar.cpp \
    cmaszyna.cpp \
    cnawadniarka.cpp \
    coprysk.cpp \
    cpietruszka.cpp \
    cpoczatek.cpp \
    cpole.cpp \
    croslina.cpp \
    csegment.cpp \
    csklep.cpp \
    ctruskawka.cpp \
    cursus.cpp \
    cursusx.cpp \
    curzadpracy.cpp \
    cziemniak.cpp \
    dialog.cpp \
    gui_coprsyk.cpp \
    gui_csegment.cpp \
    main.cpp \
    kontroler.cpp

HEADERS += \
    cfarmer.h \
    chektar.h \
    cmaszyna.h \
    cnawadniarka.h \
    coprysk.h \
    cpietruszka.h \
    cpoczatek.h \
    cpole.h \
    croslina.h \
    csegment.h \
    csklep.h \
    ctruskawka.h \
    cursus.h \
    cursusx.h \
    curzadpracy.h \
    cziemniak.h \
    dialog.h \
    gui_coprsyk.h \
    gui_csegment.h \
    kontroler.h

FORMS += \
    chektar.ui \
    cpoczatek.ui \
    csklep.ui \
    curzadpracy.ui \
    dialog.ui \
    kontroler.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
