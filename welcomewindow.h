#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();


private slots:
    void OpenSellerSignUpPage();
    void OpenBuyerSignUpPage();
    void OpenLoginPage();

private:
    Ui::WelcomeWindow *ui;
    QPushButton *petSellerSignUp;
    QPushButton *petBuyerSignUp;
    QPushButton *welcomeLogin;
};

#endif // WELCOMEWINDOW_H
