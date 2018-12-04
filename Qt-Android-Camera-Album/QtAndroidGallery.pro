
QT       += core gui
android{
QT       +=androidextras
}
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtAndroidGallery
TEMPLATE = app


SOURCES += main.cpp \
    dialog.cpp \
    tiffimg.cpp

HEADERS  += \
    dialog.h \
    tiffimg.h

FORMS    +=

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android-sources/AndroidManifest.xml \
    android-sources/src/com/amin/QtAndroidGallery/QtAndroidGallery.java \
    android-sources/background.jpg \
    src/background.jpg

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources

RESOURCES += \
    src.qrc
