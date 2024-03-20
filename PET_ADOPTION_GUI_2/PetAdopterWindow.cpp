#include "PetAdopterWindow.h"
#include "ui_PetAdopterWindow.h"

PetAdopterWindow::PetAdopterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PetAdopterWindow)
{
    ui->setupUi(this);

    pushButtonCancel = findChild<QPushButton*>("pushButtonCancel");
    connect(pushButtonCancel, &QPushButton::clicked, this, &PetAdopterWindow::cancelClicked);

    // pushButtonSubmit = findChild<QPushButton*>("pushButtonSubmit");
    // connect(pushButtonSubmit, &QPushButton::clicked,this, &MainWindow::submitButtonClicked);
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

// void MainWindow::submitButtonClicked()
// {
//     // Implement submit functionality here
//     // For example, validate input and proceed
// }
