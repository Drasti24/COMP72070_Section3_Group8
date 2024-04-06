#include "petadopterprofilewindow.h"
#include "ui_petadopterprofilewindow.h"
#include "postpagewindow.h"
#include <QFileDialog>

PetAdopterProfileWindow::PetAdopterProfileWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PetAdopterProfileWindow)
{
    ui->setupUi(this);

    connect(ui->openImageButton, &QPushButton::clicked, this, &PetAdopterProfileWindow::openImage);
    connect(ui->goToHomePage, &QPushButton::clicked, this, &PetAdopterProfileWindow::OpenHomePage);
}

PetAdopterProfileWindow::~PetAdopterProfileWindow()
{
    delete ui;
}

void PetAdopterProfileWindow::OpenHomePage() {
    PostPageWindow* myPosts = new PostPageWindow();
    myPosts->show();
    this->close();
}

void PetAdopterProfileWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));

    if (!fileName.isEmpty()) {
        QPixmap originalImage(fileName);
        QSize newSize(750, 560);
        QPixmap compressedImage = originalImage.scaled(newSize, Qt::IgnoreAspectRatio);
        ui->imageLabel->setPixmap(compressedImage);
        ui->imageLabel->setScaledContents(true);
    }
}

void PetAdopterProfileWindow::receiveValue(QString& uname, QString& bio) {
    ui->emptyUnameLabel->setText(uname);
    ui->emptyBioLabel->setText(bio);
}
//void PetAdopterProfileWindow::setProfileData(const QString &userName, const QString &bio)
//{
//    // If you add labels for the first name and last name, uncomment these lines and set their texts.
//    // ui->labelFirstName->setText(firstName);
//    // ui->labelLastName->setText(lastName);
//    ui->labelUsernameValue->setText(userName);
//    ui->labelBioValue->setText(bio);
//}
