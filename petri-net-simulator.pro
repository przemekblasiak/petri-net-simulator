TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    node.cpp \
    place.cpp \
    transition.cpp \
    arrow.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    node.h \
    place.h \
    transition.h \
    arrow.h
