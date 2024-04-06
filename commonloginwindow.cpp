#include "commonloginwindow.h"
#include "ui_commonloginwindow.h"
//will i see tjis change in github?
CommonLoginWindow::CommonLoginWindow(QWidget *parent, QTcpSocket *socket)
    : QMainWindow(parent)
    , ui(new Ui::CommonLoginWindow)
{
    ui->setupUi(this);
    loginSocket = socket; // Store the passed socket pointer

    // Connect cancel button signal to slot
    cancelButton = findChild<QPushButton*>("cancelButton");
    connect(cancelButton, &QPushButton::clicked, this, &CommonLoginWindow::CancelButtonClicked);

    // Connect submit button signal to slot
    submitButton = findChild<QPushButton*>("submitButton");
    connect(submitButton, &QPushButton::clicked, this, &CommonLoginWindow::SubmitButtonClicked);
}

CommonLoginWindow::~CommonLoginWindow()
{
    delete ui;
}

void CommonLoginWindow::sendPacket(Packet& packet)
{
    if (!socket) {
        qDebug() << "Socket is not initialized.";
        return;
    }

    // Convert the packet to QByteArray before sending
    QByteArray data(reinterpret_cast<const char*>(&packet), sizeof(packet));
    loginSocket->write(data);
}

void CommonLoginWindow::CancelButtonClicked()
{
    // Implement cancellation logic if needed
    this->close();
}

void CommonLoginWindow::SubmitButtonClicked()
{
    QString UName = ui->UNameLineEdit->text();
    QString Pword = ui->PwordLineEdit->text();

    if (!socket) {
        qDebug() << "Socket is not initialized.";
        return;
    }

    Packet pkt{UName.toStdString(), Pword.toStdString()};
    sendPacket(pkt);

    qDebug() << "Login username:" << UName;
    qDebug() << "Login password:" << Pword;

    this->close();
}
