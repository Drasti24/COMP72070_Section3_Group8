#include "pet_seller_window.h"
#include "ui_pet_seller_window.h"
#include "PetSeller.h"
#include <iostream>
using namespace std;

PetSellerWindow::PetSellerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PetSellerWindow)
{
    ui->setupUi(this);

    pushButtonCancel = findChild<QPushButton*>("pushButtonCancel");
    connect(pushButtonCancel, &QPushButton::clicked, this, &PetSellerWindow::cancelClicked);

    submitButton = findChild<QPushButton*>("pushButtonSubmit");
    connect(submitButton, &QPushButton::clicked, this, &PetSellerWindow::submitButtonClicked);
}

PetSellerWindow::~PetSellerWindow()
{
    delete ui;
}

void PetSellerWindow::cancelClicked()
{
    // Implement cancel functionality here
    this->close();
}

void PetSellerWindow::submitButtonClicked()
{
    QString Fname = ui->lineEditFirstName->text();
    QString Lname = ui->lineEditLastName->text();
    QString Uname = ui->lineEditUsername->text();
    QString Pword = ui->lineEditPassword->text();
    QString BLoc =  ui->lineEditBusinessAddress->text();
    QString Prvc =  ui->lineEditProvince->text();
    QString PCode = ui->lineEditPostalCode->text();
    QString PNum =  ui->lineEditPhoneNumber->text();

    emit submitSellerData(Fname, Lname, Uname, Pword, BLoc, Prvc, PCode, PNum);

    PetSeller myPS(Fname.toStdString(), Lname.toStdString(), Uname.toStdString(), Pword.toStdString(),
                   BLoc.toStdString(), Prvc.toStdString(), PCode.toStdString(), PNum.toStdString());

    cout << myPS.getFirstName() << endl;
    cout << myPS.getLastName() << endl;
    cout << myPS.getUsername() << endl;
    cout << myPS.getPassword()  << endl;
    cout << myPS.getBusinessLocation() << endl;
    cout << myPS.getProvince() << endl;
    cout << myPS.getPostalCode() << endl;
    this->close();
}
