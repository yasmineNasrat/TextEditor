QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    eighthdialog.cpp \
    fifthdialog.cpp \
    fourthdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    openfiledialog.cpp \
    savedialog.cpp \
    secdialog.cpp \
    seventhdialog.cpp \
    showall.cpp \
    swapdialog.cpp \
    texteditor.cpp \
    thirddialog.cpp \
    wordscountdialog.cpp

HEADERS += \
    eighthdialog.h \
    fifthdialog.h \
    fourthdialog.h \
    mainwindow.h \
    openfiledialog.h \
    savedialog.h \
    secdialog.h \
    seventhdialog.h \
    showall.h \
    swapdialog.h \
    texteditor.h \
    thirddialog.h \
    wordscountdialog.h

FORMS += \
    eighthdialog.ui \
    fifthdialog.ui \
    fourthdialog.ui \
    mainwindow.ui \
    openfiledialog.ui \
    savedialog.ui \
    secdialog.ui \
    seventhdialog.ui \
    showall.ui \
    swapdialog.ui \
    thirddialog.ui \
    wordscountdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
