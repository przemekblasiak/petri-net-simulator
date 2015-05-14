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
    json/src/json_reader.cpp \
    json/src/json_value.cpp \
    json/src/json_writer.cpp


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
    json/include/json/autolink.h \
    json/include/json/config.h \
    json/include/json/features.h \
    json/include/json/forwards.h \
    json/include/json/json.h \
    json/include/json/reader.h \
    json/include/json/value.h \
    json/include/json/writer.h \
    json/src/json_batchallocator.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
