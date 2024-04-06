/********************************************************************************
** Form generated from reading UI file 'petinfowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PETINFOWINDOW_H
#define UI_PETINFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PetInfoWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hboxLayout;
    QLabel *animalLabel;
    QRadioButton *radioDogs;
    QRadioButton *radioCats;
    QRadioButton *radioBoth;
    QHBoxLayout *hboxLayout1;
    QLabel *labelVaccination;
    QRadioButton *radioYes;
    QRadioButton *radioNo;
    QRadioButton *radioSome;
    QHBoxLayout *BoxLayoutAge;
    QLabel *labelAnimalAgeRange;
    QRadioButton *radio02years;
    QRadioButton *radio35years;
    QRadioButton *radioOver5years;
    QSpacerItem *verticalSpacer1;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonSubmit;

    void setupUi(QMainWindow *PetInfoWindow)
    {
        if (PetInfoWindow->objectName().isEmpty())
            PetInfoWindow->setObjectName("PetInfoWindow");
        PetInfoWindow->resize(800, 600);
        centralWidget = new QWidget(PetInfoWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        animalLabel = new QLabel(centralWidget);
        animalLabel->setObjectName("animalLabel");
        QFont font;
        font.setPointSize(10);
        animalLabel->setFont(font);

        hboxLayout->addWidget(animalLabel);

        radioDogs = new QRadioButton(centralWidget);
        radioDogs->setObjectName("radioDogs");
        radioDogs->setFont(font);

        hboxLayout->addWidget(radioDogs);

        radioCats = new QRadioButton(centralWidget);
        radioCats->setObjectName("radioCats");
        radioCats->setFont(font);

        hboxLayout->addWidget(radioCats);

        radioBoth = new QRadioButton(centralWidget);
        radioBoth->setObjectName("radioBoth");
        radioBoth->setFont(font);

        hboxLayout->addWidget(radioBoth);


        verticalLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        labelVaccination = new QLabel(centralWidget);
        labelVaccination->setObjectName("labelVaccination");
        labelVaccination->setFont(font);

        hboxLayout1->addWidget(labelVaccination);

        radioYes = new QRadioButton(centralWidget);
        radioYes->setObjectName("radioYes");
        radioYes->setFont(font);

        hboxLayout1->addWidget(radioYes);

        radioNo = new QRadioButton(centralWidget);
        radioNo->setObjectName("radioNo");
        radioNo->setFont(font);

        hboxLayout1->addWidget(radioNo);

        radioSome = new QRadioButton(centralWidget);
        radioSome->setObjectName("radioSome");
        radioSome->setFont(font);

        hboxLayout1->addWidget(radioSome);


        verticalLayout->addLayout(hboxLayout1);

        BoxLayoutAge = new QHBoxLayout();
        BoxLayoutAge->setObjectName("BoxLayoutAge");
        labelAnimalAgeRange = new QLabel(centralWidget);
        labelAnimalAgeRange->setObjectName("labelAnimalAgeRange");
        labelAnimalAgeRange->setFont(font);

        BoxLayoutAge->addWidget(labelAnimalAgeRange);

        radio02years = new QRadioButton(centralWidget);
        radio02years->setObjectName("radio02years");
        radio02years->setFont(font);

        BoxLayoutAge->addWidget(radio02years);

        radio35years = new QRadioButton(centralWidget);
        radio35years->setObjectName("radio35years");
        radio35years->setFont(font);

        BoxLayoutAge->addWidget(radio35years);

        radioOver5years = new QRadioButton(centralWidget);
        radioOver5years->setObjectName("radioOver5years");
        radioOver5years->setFont(font);

        BoxLayoutAge->addWidget(radioOver5years);


        verticalLayout->addLayout(BoxLayoutAge);

        verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer1);

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

        PetInfoWindow->setCentralWidget(centralWidget);

        retranslateUi(PetInfoWindow);

        QMetaObject::connectSlotsByName(PetInfoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PetInfoWindow)
    {
        PetInfoWindow->setWindowTitle(QCoreApplication::translate("PetInfoWindow", "Pet Info Login", nullptr));
        animalLabel->setText(QCoreApplication::translate("PetInfoWindow", "What animals do you sell?", nullptr));
        radioDogs->setText(QCoreApplication::translate("PetInfoWindow", "Dogs", nullptr));
        radioCats->setText(QCoreApplication::translate("PetInfoWindow", "Cats", nullptr));
        radioBoth->setText(QCoreApplication::translate("PetInfoWindow", "Both", nullptr));
        labelVaccination->setText(QCoreApplication::translate("PetInfoWindow", "Are they all vaccinated and allergy free?", nullptr));
        radioYes->setText(QCoreApplication::translate("PetInfoWindow", "Yes", nullptr));
        radioNo->setText(QCoreApplication::translate("PetInfoWindow", "No", nullptr));
        radioSome->setText(QCoreApplication::translate("PetInfoWindow", "Some", nullptr));
        labelAnimalAgeRange->setText(QCoreApplication::translate("PetInfoWindow", "How old are they? Select ONE", nullptr));
        radio02years->setText(QCoreApplication::translate("PetInfoWindow", "0 - 2 years", nullptr));
        radio35years->setText(QCoreApplication::translate("PetInfoWindow", "3 - 5 years", nullptr));
        radioOver5years->setText(QCoreApplication::translate("PetInfoWindow", "More than 5 years", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("PetInfoWindow", "Cancel", nullptr));
        pushButtonSubmit->setText(QCoreApplication::translate("PetInfoWindow", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PetInfoWindow: public Ui_PetInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PETINFOWINDOW_H
