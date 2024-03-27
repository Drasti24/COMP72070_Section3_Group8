#include "commonloginwindow.h"
#include "ui_commonloginwindow.h"
#include <iostream>
//#include "Packet.h"
using namespace std;
CommonLoginWindow::CommonLoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CommonLoginWindow)
{
    ui->setupUi(this);

    cancelButton = findChild<QPushButton*>("cancelPushButton");
    connect(cancelButton, &QPushButton::clicked, this, &CommonLoginWindow::CancelButtonClicked);

    submitButton = findChild<QPushButton*>("submitPushButton");
    connect(submitButton, &QPushButton::clicked, this, &CommonLoginWindow::SubmitButtonClicked);
}

CommonLoginWindow::~CommonLoginWindow()
{
    delete ui;
}

void CommonLoginWindow::CancelButtonClicked(){
    this->close();
}

void CommonLoginWindow::SubmitButtonClicked(){
    QString UName = ui->UNameLineEdit->text();
    QString Pword = ui->PwordLineEdit->text();

    //Packet pkt;
    //pkt.loginInfo.username = UName.toStdString();
    //pkt.loginInfo.hashedPassword = Pword.toStdString();

    cout << "Login username: "<<UName.toStdString() << endl;
    cout << "Login password: " <<Pword.toStdString() << endl;
    this->close();
}
