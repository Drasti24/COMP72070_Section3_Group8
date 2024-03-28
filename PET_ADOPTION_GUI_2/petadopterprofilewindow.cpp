// #include "petadopterprofilewindow.h"
// #include "ui_petadopterprofilewindow.h"

// PetAdopterProfileWindow::PetAdopterProfileWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::PetAdopterProfileWindow)
// {
//     ui->setupUi(this);
// }

// PetAdopterProfileWindow::~PetAdopterProfileWindow()
// {
//     delete ui;
// }

// void PetAdopterProfileWindow::setProfileInfo(const QString& username, const QString& bio)
// {
//     ui->labelUsernameValue->setText(username);
//     ui->labelBioValue->setText(bio);
// }
// #include "petadopterprofilewindow.h"
// #include "ui_petadopterprofilewindow.h"
// #include <QFileDialog>

// PetAdopterProfileWindow::PetAdopterProfileWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::PetAdopterProfileWindow)
// {
//     ui->setupUi(this);

//     connect(ui->openImageButton, &QPushButton::clicked, this, &PetAdopterProfileWindow::openImage);
// }

// PetAdopterProfileWindow::~PetAdopterProfileWindow()
// {
//     delete ui;
// }

// void PetAdopterProfileWindow::openImage()
// {
//     QString fileName = QFileDialog::getOpenFileName(this,
//                                                     tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));

//     if (!fileName.isEmpty()) {
//         QPixmap image(fileName);
//         ui->imageLabel->setPixmap(image);
//         ui->imageLabel->setScaledContents(true);
//     }
// }

#include "petadopterprofilewindow.h"
#include "ui_petadopterprofilewindow.h"
#include <QFileDialog>
#include <QPixmap>

PetAdopterProfileWindow::PetAdopterProfileWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PetAdopterProfileWindow)
{
    ui->setupUi(this);

    connect(ui->openImageButton, &QPushButton::clicked, this, &PetAdopterProfileWindow::openImage);
}

PetAdopterProfileWindow::~PetAdopterProfileWindow()
{
    delete ui;
}

void PetAdopterProfileWindow::setProfileData(const QString &firstName, const QString &lastName, const QString &userName, const QString &bio)
{
    // If you add labels for the first name and last name, uncomment these lines and set their texts.
    // ui->labelFirstName->setText(firstName);
    // ui->labelLastName->setText(lastName);
    ui->labelUsernameValue->setText(userName);
    ui->labelBioValue->setText(bio);
}

void PetAdopterProfileWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));

    if (!fileName.isEmpty()) {
        QPixmap originalImage(fileName);
        QSize newSize(1020, 560); // This size should match the label or be dynamic based on some criteria.
        QPixmap scaledImage = originalImage.scaled(newSize, Qt::KeepAspectRatio);
        ui->imageLabel->setPixmap(scaledImage);
        ui->imageLabel->setScaledContents(true);
    }
}

