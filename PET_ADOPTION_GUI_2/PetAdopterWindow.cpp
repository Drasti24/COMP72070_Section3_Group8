#include "PetAdopterWindow.h"
#include "ui_PetAdopterWindow.h"
using namespace std;
PetAdopterWindow::PetAdopterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PetAdopterWindow)
{
    ui->setupUi(this);
    // No need to findChild as you have direct access to the ui elements
    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &PetAdopterWindow::cancelClicked);
    connect(ui->pushButtonSubmit, &QPushButton::clicked, this, &PetAdopterWindow::submitButtonClicked);
}

PetAdopterWindow::~PetAdopterWindow()
{
    delete ui;
}

void PetAdopterWindow::cancelClicked()
{
    this->close();
}

void PetAdopterWindow::submitButtonClicked()
{


    QString Fname = ui->lineEditFirstName->text();
    QString Lname = ui->lineEditLastName->text();
    QString Uname = ui->lineEditUsername->text();
    QString bio = ui->lineEditBio->text();

    emit submitProfileData(Fname,Lname,Uname,bio);

    this->close();
}

