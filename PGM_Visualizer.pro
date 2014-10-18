TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    matrix.cpp \
    pgm.cpp \
    image.cpp

HEADERS += \
    matrix.h \
    pgm.h \
    image.h

LIBS += -lfreeglut -lopengl32 -lglu32
