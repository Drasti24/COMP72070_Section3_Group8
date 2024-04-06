/********************************************************************************
** Form generated from reading UI file 'pet_seller_window.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PET_SELLER_WINDOW_H
#define UI_PET_SELLER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PetSellerWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelFirstName;
    QLineEdit *lineEditFirstName;
    QLabel *labelLastName;
    QLineEdit *lineEditLastName;
    QLabel *labelUsername;
    QLineEdit *lineEditUsername;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QLabel *labelBusinessAddress;
    QLineEdit *lineEditBusinessAddress;
    QLabel *labelProvince;
    QLineEdit *lineEditProvince;
    QLabel *labelPhoneNumber;
    QLineEdit *lineEditPhoneNumber;
    QLabel *labelLicenseID;
    QLineEdit *lineEditLicenseID;
    QLabel *labelPostalCode;
    QLineEdit *lineEditPostalCode;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonSubmit;

    void setupUi(QMainWindow *PetSellerWindow)
    {
        if (PetSellerWindow->objectName().isEmpty())
            PetSellerWindow->setObjectName("PetSellerWindow");
        PetSellerWindow->resize(800, 600);
        centralWidget = new QWidget(PetSellerWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelFirstName = new QLabel(centralWidget);
        labelFirstName->setObjectName("labelFirstName");
        QFont font;
        font.setPointSize(10);
        labelFirstName->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelFirstName);

        lineEditFirstName = new QLineEdit(centralWidget);
        lineEditFirstName->setObjectName("lineEditFirstName");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditFirstName);

        labelLastName = new QLabel(centralWidget);
        labelLastName->setObjectName("labelLastName");
        labelLastName->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelLastName);

        lineEditLastName = new QLineEdit(centralWidget);
        lineEditLastName->setObjectName("lineEditLastName");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditLastName);

        labelUsername = new QLabel(centralWidget);
        labelUsername->setObjectName("labelUsername");
        labelUsername->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelUsername);

        lineEditUsername = new QLineEdit(centralWidget);
        lineEditUsername->setObjectName("lineEditUsername");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditUsername);

        labelPassword = new QLabel(centralWidget);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, labelPassword);

        lineEditPassword = new QLineEdit(centralWidget);
        lineEditPassword->setObjectName("lineEditPassword");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditPassword);

        labelBusinessAddress = new QLabel(centralWidget);
        labelBusinessAddress->setObjectName("labelBusinessAddress");
        labelBusinessAddress->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, labelBusinessAddress);

        lineEditBusinessAddress = new QLineEdit(centralWidget);
        lineEditBusinessAddress->setObjectName("lineEditBusinessAddress");
        lineEditBusinessAddress->setFont(font);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditBusinessAddress);

        labelProvince = new QLabel(centralWidget);
        labelProvince->setObjectName("labelProvince");
        labelProvince->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, labelProvince);

        lineEditProvince = new QLineEdit(centralWidget);
        lineEditProvince->setObjectName("lineEditProvince");

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEditProvince);

        labelPhoneNumber = new QLabel(centralWidget);
        labelPhoneNumber->setObjectName("labelPhoneNumber");
        labelPhoneNumber->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, labelPhoneNumber);

        lineEditPhoneNumber = new QLineEdit(centralWidget);
        lineEditPhoneNumber->setObjectName("lineEditPhoneNumber");

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEditPhoneNumber);

        labelLicenseID = new QLabel(centralWidget);
        labelLicenseID->setObjectName("labelLicenseID");
        labelLicenseID->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, labelLicenseID);

        lineEditLicenseID = new QLineEdit(centralWidget);
        lineEditLicenseID->setObjectName("lineEditLicenseID");

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEditLicenseID);

        labelPostalCode = new QLabel(centralWidget);
        labelPostalCode->setObjectName("labelPostalCode");
        labelPostalCode->setFont(font);

        formLayout->setWidget(8, QFormLayout::LabelRole, labelPostalCode);

        lineEditPostalCode = new QLineEdit(centralWidget);
        lineEditPostalCode->setObjectName("lineEditPostalCode");

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEditPostalCode);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButtonCancel = new QPushButton(centralWidget);
        pushButtonCancel->setObjectName("pushButtonCancel");
        pushButtonCancel->setFont(font);

        verticalLayout->addWidget(pushButtonCancel);

        pushButtonSubmit = new QPushButton(centralWidget);
        pushButtonSubmit->setObjectName("pushButtonSubmit");
        pushButtonSubmit->setFont(font);

        verticalLayout->addWidget(pushButtonSubmit);

        PetSellerWindow->setCentralWidget(centralWidget);

        retranslateUi(PetSellerWindow);

        QMetaObject::connectSlotsByName(PetSellerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PetSellerWindow)
    {
        PetSellerWindow->setWindowTitle(QCoreApplication::translate("PetSellerWindow", "Pet Seller SignUp", nullptr));
        labelFirstName->setText(QCoreApplication::translate("PetSellerWindow", "First Name:", nullptr));
        labelLastName->setText(QCoreApplication::translate("PetSellerWindow", "Last Name:", nullptr));
        labelUsername->setText(QCoreApplication::translate("PetSellerWindow", "Username:", nullptr));
        labelPassword->setText(QCoreApplication::translate("PetSellerWindow", "Password:", nullptr));
        labelBusinessAddress->setText(QCoreApplication::translate("PetSellerWindow", "Business Address:", nullptr));
        labelProvince->setText(QCoreApplication::translate("PetSellerWindow", "Province:", nullptr));
        labelPhoneNumber->setText(QCoreApplication::translate("PetSellerWindow", "Phone Number:", nullptr));
        labelLicenseID->setText(QCoreApplication::translate("PetSellerWindow", "License ID:", nullptr));
        labelPostalCode->setText(QCoreApplication::translate("PetSellerWindow", "Postal Code", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("PetSellerWindow", "Cancel", nullptr));
        pushButtonSubmit->setText(QCoreApplication::translate("PetSellerWindow", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PetSellerWindow: public Ui_PetSellerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PET_SELLER_WINDOW_H
