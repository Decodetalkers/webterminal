QT       += core gui

CONFIG+=debug_and_release
CONFIG(debug, debug|release){
    TARGET = webview3
    DEFINES +=DEBUG
    RESOURCES += \
        res2.qrc
} else {
    TARGET =webview
    RESOURCES += \
        res.qrc
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webenginewidgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    widgets/webview.cpp \
    widgets/my_webengine.cpp \
    widgets/split_web.cpp \
    widgets/item.cpp \
    widgets/console.cpp \
    widgets/new_app.cpp \
    function/function.cpp

HEADERS += \
    mainwindow.h \
    widgets/webview.h \
    widgets/my_webengine.h \
    widgets/split_web.h \
    widgets/items.h \
    widgets/console.h \
    widgets/new_app.h \
    function/function.h


LIBS += -L/usr/include -lqtermwidget5
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
