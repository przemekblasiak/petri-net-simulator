TEMPLATE = app

QT += gui widgets

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    mainwindow.cpp \
    matejkocanvas.cpp \
    datahandler.cpp \
    json/src/json_reader.cpp \
    json/src/json_value.cpp \
    json/src/json_writer.cpp \
    place.cpp \
    transition.cpp \
    arrow.cpp \
    element.cpp \
    editelementdialog.cpp \
    descriptionlabel.cpp \
    simulationengine.cpp \
    graphdialog.cpp \
    state.cpp

# Default rules for deployment.
include(deployment.pri)

INCLUDEPATH += $$PWD/json/include

HEADERS += \
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
    transition.h \
    arrow.h \
    element.h \
    pnsglobal.h \
    editelementdialog.h \
    descriptionlabel.h \
    simulationengine.h \
    graphdialog.h \
    state.h

FORMS += \
    mainwindow.ui \
    place.ui \
    transition.ui \
    editelementdialog.ui \
    descriptionlabel.ui \
    graphdialog.ui \
    state.ui

RESOURCES += \
    resources.qrc
