#include "PetAdopterWindow.h"
#include "ui_PetAdopterWindow.h"
#include "PetAdopter.h"
#include "petadopterprofilewindow.h"
#include <iostream>
#include <QMessageBox> 
#include <QTimer>   
using namespace std;
PetAdopterWindow::PetAdopterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PetAdopterWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &PetAdopterWindow::cancelClicked);
    connect(ui->pushButtonSubmit, &QPushButton::clicked, this, &PetAdopterWindow::submitButtonClicked);
}

PetAdopterWindow::~PetAdopterWindow()
{
    delete ui;
}

void PetAdopterWindow::cancelClicked()
{
    // Implement cancel functionality here
    this->close();
}



/*YOU NEED TO RECEIVE VALIDATION FROM SERVER BEFORE MOVING FORWARD WITH THIS SUBMIT BUTTON*/
void PetAdopterWindow::submitButtonClicked()
{
    QString Fname = ui->lineEditFirstName->text();
    QString Lname = ui->lineEditLastName->text();
    QString Uname = ui->lineEditUsername->text();
    QString Pword = ui->lineEditPassword->text();
    QString bio = ui->lineEditBio->text();

    PetAdopter myPA(Fname.toStdString(), Lname.toStdString(), Uname.toStdString(), Pword.toStdString());
    cout << "Pet Adopter Info\n";
    cout << myPA.getFirstName() << endl;
    cout << myPA.getLastName() << endl;
    cout << myPA.getUsername() << endl;
    cout << myPA.getPassword()  << endl;

    // Display success message for 3 seconds
    QMessageBox successMsgBox;
    successMsgBox.setWindowTitle("Success");
    successMsgBox.setText("Information submitted successfully.");
    QTimer::singleShot(3000, &successMsgBox, &QMessageBox::close); // Close the message box after 3 seconds
    successMsgBox.exec();

    //emit submitProfileData(Fname,Lname,Uname,bio);
    emit valueSent(Uname, bio); //to profile window
    PetAdopterProfileWindow *adopterProfileWindow = new PetAdopterProfileWindow();
    adopterProfileWindow->show();
    this->close();
}
