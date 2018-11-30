#-------------------------------------------------
#
# http://www.amin-ahmadi.com
#
#-------------------------------------------------

QT       += core gui androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtAndroidGallery
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android-sources/AndroidManifest.xml \
    android-sources/src/com/amin/QtAndroidGallery/QtAndroidGallery.java

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources
