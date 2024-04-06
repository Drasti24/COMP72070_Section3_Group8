#ifndef COMMONLOGINWINDOW_H
#define COMMONLOGINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTcpSocket>
#include "Packet.h"

namespace Ui {
class CommonLoginWindow;
}

class CommonLoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CommonLoginWindow(QWidget *parent = nullptr, QTcpSocket *socket = nullptr);
    ~CommonLoginWindow();
    void sendPacket(Packet& packet);

private slots:
    void CancelButtonClicked();
    void SubmitButtonClicked();

private:
    Ui::CommonLoginWindow *ui;
    QPushButton *cancelButton;
    QPushButton *submitButton;
    QTcpSocket *loginSocket;
};

#endif // COMMONLOGINWINDOW_H
