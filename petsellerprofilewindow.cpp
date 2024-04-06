#include "petsellerprofilewindow.h"
#include "ui_petsellerprofilewindow.h"
#include <QFileDialog>

PetSellerProfileWindow::PetSellerProfileWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PetSellerProfileWindow)
{
    ui->setupUi(this);

    connect(ui->profilePictureButton, &QPushButton::clicked, this, &PetSellerProfileWindow::openProfilePicture);
    connect(ui->postPictureButton, &QPushButton::clicked, this, &PetSellerProfileWindow::openPostPicture);
}

PetSellerProfileWindow::~PetSellerProfileWindow()
{
    delete ui;
}

void PetSellerProfileWindow::setProfileInfo(const QString& username, const QString& businessLocation, const QString& province)
{
    ui->labelUsernameValue->setText(username);
    ui->labelBusinessLocationValue->setText(businessLocation);
    ui->labelProvinceValue->setText(province);
}

void PetSellerProfileWindow::openProfilePicture()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Select Profile Picture"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));

    if (!fileName.isEmpty()) {
        // Process the selected profile picture file here
    }
}

void PetSellerProfileWindow::openPostPicture()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Select Post Picture"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));

    if (!fileName.isEmpty()) {
        // Process the selected post picture file here

    }
}

void PetSellerProfileWindow::updateProfile(const QString &username, const QString &businessLocation, const QString &province)
{
    // Set the text of the profile window's labels, etc.
    ui->labelUsernameValue->setText(username);
    ui->labelBusinessLocationValue->setText(businessLocation);
    ui->labelProvinceValue->setText(province);

    // ... other updates as needed ...
}
