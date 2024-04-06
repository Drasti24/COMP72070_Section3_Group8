/********************************************************************************
** Form generated from reading UI file 'welcomewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *welcomeLabel;
    QLabel *createAccountLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *petSellerButton;
    QPushButton *petBuyerButton;
    QLabel *alreadyHaveAccountLabel;
    QPushButton *loginButton;

    void setupUi(QMainWindow *WelcomeWindow)
    {
        if (WelcomeWindow->objectName().isEmpty())
            WelcomeWindow->setObjectName("WelcomeWindow");
        WelcomeWindow->resize(200, 200);
        centralwidget = new QWidget(WelcomeWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        welcomeLabel = new QLabel(centralwidget);
        welcomeLabel->setObjectName("welcomeLabel");
        QFont font;
        font.setPointSize(24);
        welcomeLabel->setFont(font);
        welcomeLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(welcomeLabel);

        createAccountLabel = new QLabel(centralwidget);
        createAccountLabel->setObjectName("createAccountLabel");
        QFont font1;
        font1.setPointSize(12);
        createAccountLabel->setFont(font1);
        createAccountLabel->setAlignment(Qt::AlignHCenter);

        verticalLayout->addWidget(createAccountLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        petSellerButton = new QPushButton(centralwidget);
        petSellerButton->setObjectName("petSellerButton");
        QFont font2;
        font2.setPointSize(10);
        petSellerButton->setFont(font2);

        horizontalLayout->addWidget(petSellerButton);

        petBuyerButton = new QPushButton(centralwidget);
        petBuyerButton->setObjectName("petBuyerButton");
        petBuyerButton->setFont(font2);

        horizontalLayout->addWidget(petBuyerButton);


        verticalLayout->addLayout(horizontalLayout);

        alreadyHaveAccountLabel = new QLabel(centralwidget);
        alreadyHaveAccountLabel->setObjectName("alreadyHaveAccountLabel");
        alreadyHaveAccountLabel->setFont(font1);
        alreadyHaveAccountLabel->setAlignment(Qt::AlignHCenter);

        verticalLayout->addWidget(alreadyHaveAccountLabel);

        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy);
        loginButton->setFont(font2);

        verticalLayout->addWidget(loginButton);

        WelcomeWindow->setCentralWidget(centralwidget);

        retranslateUi(WelcomeWindow);

        QMetaObject::connectSlotsByName(WelcomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WelcomeWindow)
    {
        WelcomeWindow->setWindowTitle(QCoreApplication::translate("WelcomeWindow", "Welcome to PetFindsHome", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("WelcomeWindow", "Welcome to PetFindsHome", nullptr));
        createAccountLabel->setText(QCoreApplication::translate("WelcomeWindow", "Create a new account", nullptr));
        petSellerButton->setText(QCoreApplication::translate("WelcomeWindow", "Sign Up as Pet Seller/Organization", nullptr));
        petBuyerButton->setText(QCoreApplication::translate("WelcomeWindow", "Sign Up as Pet Buyer", nullptr));
        alreadyHaveAccountLabel->setText(QCoreApplication::translate("WelcomeWindow", "Already have an account?", nullptr));
        loginButton->setText(QCoreApplication::translate("WelcomeWindow", "Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindow: public Ui_WelcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
