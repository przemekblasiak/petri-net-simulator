TEMPLATE = app

QT += gui widgets

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    node.cpp \
    place.cpp \
    transition.cpp \
    arrow.cpp \
    engine.cpp \
    mainwindow.cpp \

# Default rules for deployment.
include(deployment.pri)

INCLUDEPATH += $$PWD/json/include

HEADERS += \
    node.h \
    place.h \
    transition.h \
    arrow.h \
    engine.h \
    mainwindow.h \

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
