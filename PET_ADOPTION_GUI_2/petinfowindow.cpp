#include "petinfowindow.h"
#include "ui_petinfowindow.h"
//#include "Packet.h"
#include <iostream>
#include <QButtonGroup>
#include <QAbstractButton>
using namespace std;
PetInfoWindow::PetInfoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PetInfoWindow)
{
    ui->setupUi(this);
    // Create a button group for the animal type radio buttons
    animalGroup = new QButtonGroup(this);
    animalGroup->addButton(ui->radioDogs);
    animalGroup->addButton(ui->radioCats);
    animalGroup->addButton(ui->radioBoth);

    // Create a button group for the vaccination status radio buttons
    vaccinationGroup = new QButtonGroup(this);
    vaccinationGroup->addButton(ui->radioYes);
    vaccinationGroup->addButton(ui->radioNo);
    vaccinationGroup->addButton(ui->radioSome);

    pushButtonCancel = findChild<QPushButton*>("pushButtonCancel");
    connect(pushButtonCancel, &QPushButton::clicked, this, &PetInfoWindow::cancelClicked);

    submitButton = findChild<QPushButton*>("pushButtonSubmit");
    connect(submitButton, &QPushButton::clicked, this, &PetInfoWindow::petInfoSubmitButtonClicked);
}

void PetInfoWindow::cancelClicked()
{
    // Implement cancel functionality here
    this->close();
}

PetInfoWindow::~PetInfoWindow()
{
    delete ui;
}

void PetInfoWindow::petInfoSubmitButtonClicked()
{
    QAbstractButton *animalButton = animalGroup->checkedButton();

    //collects for animal type info
    if (animalButton == ui->radioDogs)
    {
        // Packet pkt;
        // pkt.petInfo.animalType = 0;
        cout << "Dog is 0" << endl;
    }
    else if (animalButton == ui->radioCats)
    {
        // Packet pkt;
        // pkt.petInfo.animalType = 1;
        cout << "Cat is 1" << endl;
    }
    else if (animalButton == ui->radioBoth)
    {
        // Packet pkt;
        // pkt.petInfo.animalType = 2;
        cout << "Both is 2" << endl;
    }
    this->close();
}
