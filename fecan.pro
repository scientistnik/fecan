greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets serialport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}

TARGET = fecan
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    console.cpp \
    settingswindow.cpp

HEADERS += \
    mainwindow.h \
    console.h \
    settingswindow.h

FORMS += \
    mainwindow.ui \
    settingswindow.ui

RESOURCES +=
