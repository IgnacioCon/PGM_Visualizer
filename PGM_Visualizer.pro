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

win32: LIBS += -lfreeglut -lglut32 -lopengl32
else:unix: LIBS += -lGL -lglut
