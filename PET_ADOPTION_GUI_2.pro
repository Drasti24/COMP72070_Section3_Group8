QT       += core gui
QT       += uitools
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# INCLUDEPATH += "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\cppwinrt\winrt"
# win32: LIBS += -lWs2_32

# Get the path to the Windows SDK include directory
#win_sdk_include = $$system(echo %WindowsSdkDir%)

# Specify the location of Windows SDK headers
INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um"
# LIBS += "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22000.0/um/x64" -luser32 -lkernel32
# INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/shared" \
#                "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um" \
#                "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/winrt"

# INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um"
# INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/shared"
# INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/cppwinrt/winrt"

# # Specify the location of Windows SDK libraries
# win32: {
#     win_sdk_lib = "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22000.0/um/x64"
#     LIBS += -L$$win_sdk_lib -lWs2_32
# }

SOURCES += \
    Login.cpp \
    MainGUI.cpp \
    Message.cpp \
    Packet.cpp \
    PetAdopter.cpp \
    PetAdopterWindow.cpp \
    PetPost.cpp \
    PetSeller.cpp \
    ProvinceEnum.cpp \
    UserProfile.cpp \
    commonloginwindow.cpp \
    pet_seller_window.cpp \
    petadopterprofilewindow.cpp \
    petinfowindow.cpp \
    petsellerprofilewindow.cpp \
    postpagewindow.cpp \
    welcomewindow.cpp

HEADERS += \
    Login.h \
    Message.h \
    Packet.h \
    PetAdopter.h \
    PetAdopterWindow.h \
    PetPost.h \
    PetSeller.h \
    ProvinceEnum.h \
    UserProfile.h \
    commonloginwindow.h \
    pet_seller_window.h \
    petadopterprofilewindow.h \
    petinfowindow.h \
    petsellerprofilewindow.h \
    postpagewindow.h \
    welcomewindow.h

FORMS += \
    PetAdopterWindow.ui \
    commonloginwindow.ui \
    pet_seller_window.ui \
    petadopterprofilewindow.ui \
    petinfowindow.ui \
    petsellerprofilewindow.ui \
    postpagewindow.ui \
    welcomewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
