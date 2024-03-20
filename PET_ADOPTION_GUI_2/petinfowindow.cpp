#include "petinfowindow.h"
#include "ui_petinfowindow.h"
#include <QButtonGroup>

PetInfoWindow::PetInfoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PetInfoWindow)
{
    ui->setupUi(this);
    // Create a button group for the animal type radio buttons
    QButtonGroup *animalGroup = new QButtonGroup(this);
    animalGroup->addButton(ui->radioDogs);
    animalGroup->addButton(ui->radioCats);
    animalGroup->addButton(ui->radioBoth);

    // Create a button group for the vaccination status radio buttons
    QButtonGroup *vaccinationGroup = new QButtonGroup(this);
    vaccinationGroup->addButton(ui->radioYes);
    vaccinationGroup->addButton(ui->radioNo);
    vaccinationGroup->addButton(ui->radioSome);

    pushButtonCancel = findChild<QPushButton*>("pushButtonCancel");
    connect(pushButtonCancel, &QPushButton::clicked, this, &PetInfoWindow::cancelClicked);

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
