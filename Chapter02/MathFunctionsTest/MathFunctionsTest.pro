QT -= gui

# No debug output
CONFIG(release, debug|release): DEFINES += QT_NO_DEBUG_OUTPUT

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Include library
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-MathFunctions-Desktop_Qt_5_12_3_MinGW_64_bit-Release/release/ -lMathFunctions
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-MathFunctions-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/debug/ -lMathFunctions
else:unix: LIBS += -L$$PWD/../build-MathFunctions-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/ -lMathFunctions

INCLUDEPATH += $$PWD/../MathFunctions
DEPENDPATH += $$PWD/../MathFunctions

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-MathFunctions-Desktop_Qt_5_12_3_MinGW_64_bit-Release/release/libMathFunctions.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-MathFunctions-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/debug/libMathFunctions.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-MathFunctions-Desktop_Qt_5_12_3_MinGW_64_bit-Release/release/MathFunctions.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-MathFunctions-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/debug/MathFunctions.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-MathFunctions-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/libMathFunctions.a
