/********************************************************************************
** Form generated from reading UI file 'PetAdopterWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PETADOPTERWINDOW_H
#define UI_PETADOPTERWINDOW_H

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

class Ui_PetAdopterWindow
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
    QLabel *label;
    QLineEdit *lineEditBio;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonSubmit;

    void setupUi(QMainWindow *PetAdopterWindow)
    {
        if (PetAdopterWindow->objectName().isEmpty())
            PetAdopterWindow->setObjectName("PetAdopterWindow");
        PetAdopterWindow->resize(800, 600);
        centralWidget = new QWidget(PetAdopterWindow);
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

        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        lineEditBio = new QLineEdit(centralWidget);
        lineEditBio->setObjectName("lineEditBio");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditBio);


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

        PetAdopterWindow->setCentralWidget(centralWidget);

        retranslateUi(PetAdopterWindow);

        QMetaObject::connectSlotsByName(PetAdopterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PetAdopterWindow)
    {
        PetAdopterWindow->setWindowTitle(QCoreApplication::translate("PetAdopterWindow", "Pet Adopter SignUp", nullptr));
        labelFirstName->setText(QCoreApplication::translate("PetAdopterWindow", "First Name:", nullptr));
        labelLastName->setText(QCoreApplication::translate("PetAdopterWindow", "Last Name:", nullptr));
        labelUsername->setText(QCoreApplication::translate("PetAdopterWindow", "Username:", nullptr));
        labelPassword->setText(QCoreApplication::translate("PetAdopterWindow", "Password:", nullptr));
        label->setText(QCoreApplication::translate("PetAdopterWindow", "Bio", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("PetAdopterWindow", "Cancel", nullptr));
        pushButtonSubmit->setText(QCoreApplication::translate("PetAdopterWindow", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PetAdopterWindow: public Ui_PetAdopterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PETADOPTERWINDOW_H
