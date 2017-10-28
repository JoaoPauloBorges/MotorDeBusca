#-------------------------------------------------
#
# Project created by QtCreator 2017-03-22T20:31:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MotorDeBusca
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Persistencia.cpp \
    FileName.cpp \
    Palavra.cpp \
    RelPalavra_FileName.cpp \
    ResultadoPesq.cpp \
    DadosPersistidos.cpp

HEADERS  += mainwindow.h \
    Persistencia.h \
    Entry.h \
    HashTable.h \
    FileName.h \
    Palavra.h \
    RelPalavra_FileName.h \
    ResultadoPesq.h \
    DadosPersistidos.h

FORMS    += mainwindow.ui
RC_ICONS = Pacman1.ICO
