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

void PetAdopterProfileWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));

    if (!fileName.isEmpty()) {
        QPixmap originalImage(fileName);
        QSize newSize(1020, 560);
        QPixmap compressedImage = originalImage.scaled(newSize, Qt::IgnoreAspectRatio);
        ui->imageLabel->setPixmap(compressedImage);
        ui->imageLabel->setScaledContents(true);
    }
}

