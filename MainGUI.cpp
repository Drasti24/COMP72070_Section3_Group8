#include "welcomewindow.h"
#include <QTcpSocket>
#include <QApplication>
#include "Packet.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Initialize QApplication for GUI.

    socket->connectToHost("127.0.0.1", 27000);

    qDebug() << "Connected to server!";

    WelcomeWindow welcome;
    welcome.show(); // Show the GUI window.

    QByteArray response = socket->readAll();
    qDebug() << "Server response:" << response;
    //socket.close();

    return a.exec(); // Start the main event loop for the application.
}
