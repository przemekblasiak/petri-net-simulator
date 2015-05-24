TEMPLATE = app

QT += gui widgets

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    arrow.cpp \
    engine.cpp \
    mainwindow.cpp \
    matejkocanvas.cpp \
    datahandler.cpp \
    json/src/json_reader.cpp \
    json/src/json_value.cpp \
    json/src/json_writer.cpp \
    place.cpp \
    transition.cpp

# Default rules for deployment.
include(deployment.pri)

INCLUDEPATH += $$PWD/json/include

HEADERS += \
    arrow.h \
    engine.h \
    mainwindow.h \
    matejkocanvas.h \
    datahandler.h \
    json/include/json/autolink.h \
    json/include/json/config.h \
    json/include/json/features.h \
    json/include/json/forwards.h \
    json/include/json/json.h \
    json/include/json/reader.h \
    json/include/json/value.h \
    json/include/json/writer.h \
    json/src/json_batchallocator.h \
    place.h \
    transition.h

FORMS += \
    mainwindow.ui \
    place.ui \
    transition.ui

RESOURCES += \
    resources.qrc
