#include "pet_seller_window.h"
#include "ui_pet_seller_window.h"

PetSellerWindow::PetSellerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PetSellerWindow)
{
    ui->setupUi(this);

    pushButtonCancel = findChild<QPushButton*>("pushButtonCancel");
    connect(pushButtonCancel, &QPushButton::clicked, this, &PetSellerWindow::cancelClicked);
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
