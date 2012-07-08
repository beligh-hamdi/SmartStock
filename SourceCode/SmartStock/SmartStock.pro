#-------------------------------------------------
#
# Project created by QtCreator 2012-06-30T20:34:36
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartStock
TEMPLATE = app

RC_FILE = smartstock.rc


SOURCES += main.cpp\
        mainwindow.cpp \
    smartstockform.cpp \
    utilisateur.cpp \
    produit.cpp \
    stock.cpp \
    categorie.cpp \
    connexiondatabase.cpp

HEADERS  += mainwindow.h \
    library.h \
    smartstockform.h \
    utilisateur.h \
    produit.h \
    stock.h \
    categorie.h \
    connexiondatabase.h


FORMS    += mainwindow.ui \
    smartstockform.ui

OTHER_FILES += \
    smartstock.rc
