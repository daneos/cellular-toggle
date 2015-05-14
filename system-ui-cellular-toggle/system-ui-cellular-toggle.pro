#-------------------------------------------------
#
# Project created by QtCreator 2015-05-14T12:01:04
#
#-------------------------------------------------

QT       += dbus image icon cellular

#QT       -= gui

TARGET = system-ui-cellular-toggle
TEMPLATE = lib

INCLUDEPATH += /home/daneos/QtSDK/Madde/sysroots/harmattan_sysroot_10.2011.34-1_slim/usr/include

DEFINES += SYSTEMUICELLULARTOGGLE_LIBRARY

SOURCES += cellulartoggle.cpp

HEADERS += cellulartoggle.h\
        system-ui-cellular-toggle_global.h \
    mtabstracttoggle.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEBDE93F3
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = system-ui-cellular-toggle.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog
