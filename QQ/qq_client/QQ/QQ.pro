QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chat.cpp \
    internet.cpp \
    main.cpp \
    qq_list.cpp \
    qq_main_menu.cpp

HEADERS += \
    chat.h \
    internet.h \
    qq_list.h \
    qq_main_menu.h

FORMS += \
    chat.ui \
    qq_list.ui \
    qq_main_menu.ui
LIBS += -lpthread libwsock32 libws2_32
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
