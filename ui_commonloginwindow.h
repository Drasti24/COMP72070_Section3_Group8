/********************************************************************************
** Form generated from reading UI file 'commonloginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONLOGINWINDOW_H
#define UI_COMMONLOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommonLoginWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *UNameLabel;
    QLineEdit *UNameLineEdit;
    QLabel *PwordLabel;
    QLineEdit *PwordLineEdit;
    QPushButton *cancelPushButton;
    QPushButton *submitPushButton;

    void setupUi(QMainWindow *CommonLoginWindow)
    {
        if (CommonLoginWindow->objectName().isEmpty())
            CommonLoginWindow->setObjectName("CommonLoginWindow");
        CommonLoginWindow->resize(800, 600);
        QFont font;
        font.setPointSize(10);
        CommonLoginWindow->setFont(font);
        centralWidget = new QWidget(CommonLoginWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        UNameLabel = new QLabel(centralWidget);
        UNameLabel->setObjectName("UNameLabel");
        UNameLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, UNameLabel);

        UNameLineEdit = new QLineEdit(centralWidget);
        UNameLineEdit->setObjectName("UNameLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, UNameLineEdit);

        PwordLabel = new QLabel(centralWidget);
        PwordLabel->setObjectName("PwordLabel");
        PwordLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, PwordLabel);

        PwordLineEdit = new QLineEdit(centralWidget);
        PwordLineEdit->setObjectName("PwordLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, PwordLineEdit);


        verticalLayout->addLayout(formLayout);

        cancelPushButton = new QPushButton(centralWidget);
        cancelPushButton->setObjectName("cancelPushButton");

        verticalLayout->addWidget(cancelPushButton);

        submitPushButton = new QPushButton(centralWidget);
        submitPushButton->setObjectName("submitPushButton");
        submitPushButton->setFont(font);

        verticalLayout->addWidget(submitPushButton);

        CommonLoginWindow->setCentralWidget(centralWidget);

        retranslateUi(CommonLoginWindow);

        QMetaObject::connectSlotsByName(CommonLoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CommonLoginWindow)
    {
        CommonLoginWindow->setWindowTitle(QCoreApplication::translate("CommonLoginWindow", "Login", nullptr));
        UNameLabel->setText(QCoreApplication::translate("CommonLoginWindow", "Username:", nullptr));
        PwordLabel->setText(QCoreApplication::translate("CommonLoginWindow", "Password:", nullptr));
        cancelPushButton->setText(QCoreApplication::translate("CommonLoginWindow", "Cancel", nullptr));
        submitPushButton->setText(QCoreApplication::translate("CommonLoginWindow", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommonLoginWindow: public Ui_CommonLoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONLOGINWINDOW_H
