/********************************************************************************
** Form generated from reading UI file 'petadopterprofilewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PETADOPTERPROFILEWINDOW_H
#define UI_PETADOPTERPROFILEWINDOW_H

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

class Ui_PetAdopterProfileWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *goToHomePage;
    QFormLayout *formLayout;
    QLabel *labelUsername;
    QLabel *emptyUnameLabel;
    QLabel *labelBio;
    QLabel *emptyBioLabel;
    QLabel *imageLabel;
    QPushButton *openImageButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *PetAdopterProfileWindow)
    {
        if (PetAdopterProfileWindow->objectName().isEmpty())
            PetAdopterProfileWindow->setObjectName("PetAdopterProfileWindow");
        PetAdopterProfileWindow->resize(800, 600);
        centralwidget = new QWidget(PetAdopterProfileWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        goToHomePage = new QPushButton(centralwidget);
        goToHomePage->setObjectName("goToHomePage");
        QFont font;
        font.setPointSize(10);
        goToHomePage->setFont(font);

        verticalLayout->addWidget(goToHomePage);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelUsername = new QLabel(centralwidget);
        labelUsername->setObjectName("labelUsername");
        labelUsername->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUsername);

        emptyUnameLabel = new QLabel(centralwidget);
        emptyUnameLabel->setObjectName("emptyUnameLabel");

        formLayout->setWidget(0, QFormLayout::FieldRole, emptyUnameLabel);

        labelBio = new QLabel(centralwidget);
        labelBio->setObjectName("labelBio");
        labelBio->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelBio);

        emptyBioLabel = new QLabel(centralwidget);
        emptyBioLabel->setObjectName("emptyBioLabel");

        formLayout->setWidget(1, QFormLayout::FieldRole, emptyBioLabel);

        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName("imageLabel");

        formLayout->setWidget(3, QFormLayout::SpanningRole, imageLabel);

        openImageButton = new QPushButton(centralwidget);
        openImageButton->setObjectName("openImageButton");
        openImageButton->setFont(font);

        formLayout->setWidget(2, QFormLayout::SpanningRole, openImageButton);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        PetAdopterProfileWindow->setCentralWidget(centralwidget);

        retranslateUi(PetAdopterProfileWindow);

        QMetaObject::connectSlotsByName(PetAdopterProfileWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PetAdopterProfileWindow)
    {
        PetAdopterProfileWindow->setWindowTitle(QCoreApplication::translate("PetAdopterProfileWindow", "Pet Adopter Profile", nullptr));
        goToHomePage->setText(QCoreApplication::translate("PetAdopterProfileWindow", "Go to Home Page", nullptr));
        labelUsername->setText(QCoreApplication::translate("PetAdopterProfileWindow", "Username:", nullptr));
        labelBio->setText(QCoreApplication::translate("PetAdopterProfileWindow", "Bio:", nullptr));
        openImageButton->setText(QCoreApplication::translate("PetAdopterProfileWindow", "Add Profile Picture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PetAdopterProfileWindow: public Ui_PetAdopterProfileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PETADOPTERPROFILEWINDOW_H
