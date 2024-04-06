#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "pet_seller_window.h"
#include "PetAdopterWindow.h"
#include "commonloginwindow.h"


WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    petSellerSignUp = findChild<QPushButton*>("petSellerButton");
    connect(petSellerSignUp, &QPushButton::clicked, this, &WelcomeWindow::OpenSellerSignUpPage);

    petBuyerSignUp = findChild<QPushButton*>("petBuyerButton");
    connect(petBuyerSignUp, &QPushButton::clicked, this, &WelcomeWindow::OpenBuyerSignUpPage);

    welcomeLogin = findChild<QPushButton*>("loginButton");
    connect(welcomeLogin, &QPushButton::clicked, this, &WelcomeWindow::OpenLoginPage);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::OpenSellerSignUpPage(){
    PetSellerWindow *petSellerSignUpWindow = new PetSellerWindow();
    petSellerSignUpWindow->show();
}

void WelcomeWindow::OpenBuyerSignUpPage(){
    PetAdopterWindow *petBuyerSignUpWindow = new PetAdopterWindow();
    petBuyerSignUpWindow->show();
}

void WelcomeWindow::OpenLoginPage(){
    CommonLoginWindow *loginWindow = new CommonLoginWindow(nullptr, socket);
    loginWindow->show();
}
