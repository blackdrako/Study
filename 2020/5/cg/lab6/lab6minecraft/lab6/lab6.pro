TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        Application.cpp \
        Camera.cpp \
        Display.cpp \
        Model.cpp \
        ModelCoords.cpp \
        MusicPlayer.cpp \
        Util/STDUtil.cpp \
        Util/FileUtil.cpp \
        Util/Loader.cpp \
        Util/Random.cpp \
        Util/TimeCheck.cpp \

HEADERS  += \
        Application.h \
        Camera.h \
        Display.h \
        Model.h \
        ModelCoords.h \
        MusicPlayer.h \
        Util/Random.h \
        Util/Array2D.h \
        Util/Array3D.h \
        Util/FileUtil.h \
        Util/Hasher.h \
        Util/Loader.h \
        Util/Log.h \
        Util/Native.h \
        Util/Singleton.h \
        Util/TimeCheck.h \
        Util/STD_Util.h \

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/SFML/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/SFML/lib/ -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
else:unix: LIBS += -L$$PWD/SFML/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += C:\Qt\glm \
               C:\Qt\glut-3.7

LIBS += -lopengl32 -lglu32

INCLUDEPATH += $$PWD/SFML/include
DEPENDPATH += $$PWD/SFML/include
