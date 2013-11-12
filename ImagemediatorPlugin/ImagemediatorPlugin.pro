######################################################################
# Automatically generated by qmake (2.01a) Fri Aug 23 13:22:33 2013
######################################################################
CONFIG(debug, debug|release):    message(Debug build!)
CONFIG(release, debug|release):    message(Release build!)

QT -= gui

TARGET = imagemediatorPlugin

CONFIG(debug, debug|release): TARGET = ImagemediatorPlugin_Debug
CONFIG(release, debug|release): TARGET = ImagemediatorPlugin_Release

TEMPLATE = lib
CONFIG += dll

DEFINES += IMAGEMEDIATORPLUGIN_LIB

# Input
HEADERS += imagemediatorplugin.h imagemediatorplugin_global.h
SOURCES += imagemediatorplugin.cpp

CONFIG(debug, debug|release): DESTDIR = $$PWD/../../../NoobaVSS_build/NoobaFE/Debug/plugins/
CONFIG(release, debug|release): DESTDIR = $$PWD/../../../NoobaVSS_build/NoobaFE/Release/plugins/

# include opencv
unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
    # remove sym links to the shared lib from the DESTDIR
    QMAKE_POST_LINK = find $$DESTDIR -maxdepth 1 -type l -exec rm -f {} \;
}

CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../NoobaVSS_build/NoobaPluginAPI/Debug/ -lNoobaPluginAPId
CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../NoobaVSS_build/NoobaPluginAPI/Release/ -lNoobaPluginAPI

INCLUDEPATH += $$PWD/../../../NoobaVSS/NoobaPluginAPI/
DEPENDPATH += $$PWD/../../../NoobaVSS/NoobaPluginAPI/
