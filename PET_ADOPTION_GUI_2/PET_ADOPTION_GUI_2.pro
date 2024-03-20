QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\cppwinrt\winrt"
win32: LIBS += -lWs2_32

SOURCES += \
    ClientNetworking.cpp \
    Login.cpp \
    MainGUI.cpp \
    Message.cpp \
    PetAdopter.cpp \
    PetAdopterWindow.cpp \
    PetPost.cpp \
    PetSeller.cpp \
    ProvinceEnum.cpp \
    UserProfile.cpp \
    pet_seller_window.cpp \
    petadopterprofilewindow.cpp \
    petinfowindow.cpp \
    petsellerprofilewindow.cpp \
    postpagewindow.cpp

HEADERS += \
    ClientNetworking.h \
    Login.h \
    Message.h \
    PetAdopter.h \
    PetAdopterWindow.h \
    PetPost.h \
    PetSeller.h \
    ProvinceEnum.h \
    UserProfile.h \
    pet_seller_window.h \
    petadopterprofilewindow.h \
    petinfowindow.h \
    petsellerprofilewindow.h \
    postpagewindow.h

FORMS += \
    PetAdopterWindow.ui \
    pet_seller_window.ui \
    petadopterprofilewindow.ui \
    petinfowindow.ui \
    petsellerprofilewindow.ui \
    postpagewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
