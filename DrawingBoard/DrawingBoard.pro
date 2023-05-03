QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += shape/

SOURCES += \
    CDrawBoardWidget.cpp \
    DrawWidget.cpp \
    mypoint.cpp \
    shape/contentedit.cpp \
    shape/demensionsdata.cpp \
    shape/ellipsedata.cpp \
    shape/erasuredata.cpp \
    shape/linedata.cpp \
    main.cpp \
    shape/rectangledata.cpp \
    shape/shapedata.cpp \
    systemdata.cpp \
    shape/textdata.cpp \
    shape/triangeledata.cpp

HEADERS += \
    CDrawBoardWidget.h \
    DrawWidget.h \
    MACRO.h \
    mypoint.h \
    shape/contentedit.h \
    shape/demensionsdata.h \
    shape/ellipsedata.h \
    shape/erasuredata.h \
    shape/linedata.h \
    shape/rectangledata.h \
    shape/shapedata.h \
    systemdata.h \
    shape/textdata.h \
    shape/triangeledata.h

FORMS += \
    CDrawBoardWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource/Icon/res.qrc

# 定义却没有使用的警告消除
QMAKE_CXXFLAGS += -Wno-unused-parameter
QMAKE_CXXFLAGS += -Wno-unused-variable
QMAKE_CXXFLAGS += -Wno-unused-function
