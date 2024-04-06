#include "petinfowindow.h"
#include "ui_petinfowindow.h"
#include "petsellerprofilewindow.h"
#include "Packet.h"
#include <iostream>
#include <QButtonGroup>
#include <QAbstractButton>
#include <QMessageBox> 
#include <QTimer> 
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

    //Create button group for animal ages radio buttons
    animalAgeGroup = new QButtonGroup(this);
    animalAgeGroup->addButton(ui->radio02years);
    animalAgeGroup->addButton(ui->radio35years);
    animalAgeGroup->addButton(ui->radioOver5years);

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
    QAbstractButton *ageButton = animalAgeGroup->checkedButton();
    QAbstractButton *vacButton = vaccinationGroup->checkedButton();
    //collects for animal type info from radio buttons
    if (animalButton == ui->radioDogs)
    {
        Packet pkt;
        pkt.petInfo.animalType = 0;
        cout << "Seller has dog only inventory" << endl;
    }
    else if (animalButton == ui->radioCats)
    {
        Packet pkt;
        pkt.petInfo.animalType = 1;
        cout << "Seller has cat only inventory" << endl;
    }
    else if (animalButton == ui->radioBoth)
    {
        Packet pkt;
        pkt.petInfo.animalType = 2;
        cout << "Seller has both in inventory" << endl;
    }

    //collects vaccination info from radio buttons
    if(vacButton == ui->radioYes)
    {
        Packet pkt;
        pkt.petInfo.vaccinationStatus = 1; //{GET ACCURATE INFO FROM SALAH}
        cout << "They are all vaccinated" << endl;
    }
    else if(vacButton == ui->radioNo){
        Packet pkt;
        pkt.petInfo.vaccinationStatus = 1; //{GET ACCURATE INFO FROM SALAH}
        cout << "They are not vaccinated" << endl;
    }
    else if(vacButton == ui->radioSome){
        Packet pkt;
        pkt.petInfo.vaccinationStatus = 1; //{GET ACCURATE INFO FROM SALAH}
        cout << "Some are vaccinated" << endl;
    }

    //collects age info from radio buttons
    if(ageButton == ui->radio02years)
    {
        Packet pkt;
        pkt.petInfo.age = 02; //{GET ACCURATE INFO FROM SALAH}
        cout << "Their age is between 0 to 2 years" << endl;
    }
    else if(ageButton == ui->radio35years){
        Packet pkt;
        pkt.petInfo.age = 35; //{GET ACCURATE INFO FROM SALAH}
        cout << "Their age is between 3 to 5 years" << endl;
    }
    else if(ageButton == ui->radioOver5years){
        Packet pkt;
        pkt.petInfo.age = 5; //{GET ACCURATE INFO FROM SALAH}
        cout << "Their age is over 5 years" << endl;
    }

    // Display success message for 3 seconds
    QMessageBox successMsgBox;
    successMsgBox.setWindowTitle("Success");
    successMsgBox.setText("Information submitted successfully.");
    QTimer::singleShot(3000, &successMsgBox, &QMessageBox::close); // Close the message box after 3 seconds
    successMsgBox.exec();

    PetSellerProfileWindow *sellerProfileWindow = new PetSellerProfileWindow();
    sellerProfileWindow->show();
    this->close();
}
