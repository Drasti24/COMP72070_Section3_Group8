/********************************************************************************
** Form generated from reading UI file 'petsellerprofilewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PETSELLERPROFILEWINDOW_H
#define UI_PETSELLERPROFILEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PetSellerProfileWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelUsername;
    QLabel *labelUsernameValue;
    QLabel *labelBusinessLocation;
    QLabel *labelBusinessLocationValue;
    QLabel *labelProvince;
    QLabel *labelProvinceValue;
    QPushButton *profilePictureButton;
    QPushButton *postPictureButton;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonEditProfile;

    void setupUi(QMainWindow *PetSellerProfileWindow)
    {
        if (PetSellerProfileWindow->objectName().isEmpty())
            PetSellerProfileWindow->setObjectName("PetSellerProfileWindow");
        PetSellerProfileWindow->resize(800, 600);
        centralwidget = new QWidget(PetSellerProfileWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelUsername = new QLabel(centralwidget);
        labelUsername->setObjectName("labelUsername");
        QFont font;
        font.setPointSize(10);
        labelUsername->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUsername);

        labelUsernameValue = new QLabel(centralwidget);
        labelUsernameValue->setObjectName("labelUsernameValue");

        formLayout->setWidget(0, QFormLayout::FieldRole, labelUsernameValue);

        labelBusinessLocation = new QLabel(centralwidget);
        labelBusinessLocation->setObjectName("labelBusinessLocation");
        labelBusinessLocation->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelBusinessLocation);

        labelBusinessLocationValue = new QLabel(centralwidget);
        labelBusinessLocationValue->setObjectName("labelBusinessLocationValue");

        formLayout->setWidget(1, QFormLayout::FieldRole, labelBusinessLocationValue);

        labelProvince = new QLabel(centralwidget);
        labelProvince->setObjectName("labelProvince");
        labelProvince->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelProvince);

        labelProvinceValue = new QLabel(centralwidget);
        labelProvinceValue->setObjectName("labelProvinceValue");

        formLayout->setWidget(2, QFormLayout::FieldRole, labelProvinceValue);

        profilePictureButton = new QPushButton(centralwidget);
        profilePictureButton->setObjectName("profilePictureButton");
        profilePictureButton->setFont(font);

        formLayout->setWidget(3, QFormLayout::SpanningRole, profilePictureButton);

        postPictureButton = new QPushButton(centralwidget);
        postPictureButton->setObjectName("postPictureButton");
        postPictureButton->setFont(font);

        formLayout->setWidget(4, QFormLayout::SpanningRole, postPictureButton);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButtonEditProfile = new QPushButton(centralwidget);
        pushButtonEditProfile->setObjectName("pushButtonEditProfile");
        pushButtonEditProfile->setFont(font);

        verticalLayout->addWidget(pushButtonEditProfile);

        PetSellerProfileWindow->setCentralWidget(centralwidget);

        retranslateUi(PetSellerProfileWindow);

        QMetaObject::connectSlotsByName(PetSellerProfileWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PetSellerProfileWindow)
    {
        PetSellerProfileWindow->setWindowTitle(QCoreApplication::translate("PetSellerProfileWindow", "Pet Seller Profile", nullptr));
        labelUsername->setText(QCoreApplication::translate("PetSellerProfileWindow", "Username:", nullptr));
        labelBusinessLocation->setText(QCoreApplication::translate("PetSellerProfileWindow", "Business Location:", nullptr));
        labelProvince->setText(QCoreApplication::translate("PetSellerProfileWindow", "Province:", nullptr));
        profilePictureButton->setText(QCoreApplication::translate("PetSellerProfileWindow", "Select Profile Picture", nullptr));
        postPictureButton->setText(QCoreApplication::translate("PetSellerProfileWindow", "Select Post Picture", nullptr));
        pushButtonEditProfile->setText(QCoreApplication::translate("PetSellerProfileWindow", "Edit Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PetSellerProfileWindow: public Ui_PetSellerProfileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PETSELLERPROFILEWINDOW_H
