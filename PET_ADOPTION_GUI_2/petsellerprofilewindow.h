// #ifndef PETSELLERPROFILEWINDOW_H
// #define PETSELLERPROFILEWINDOW_H

// #include <QMainWindow>

// QT_BEGIN_NAMESPACE
// namespace Ui { class PetSellerProfileWindow; }
// QT_END_NAMESPACE

// class PetSellerProfileWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     PetSellerProfileWindow(QWidget *parent = nullptr);
//     ~PetSellerProfileWindow();

//     void setProfileInfo(const QString& username, const QString& businessLocation, const QString& province);

// private:
//     Ui::PetSellerProfileWindow *ui;
// };

// #endif // PETSELLERPROFILEWINDOW_H
#ifndef PETSELLERPROFILEWINDOW_H
#define PETSELLERPROFILEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PetSellerProfileWindow; }
QT_END_NAMESPACE

class PetSellerProfileWindow : public QMainWindow
{
    Q_OBJECT

public:
    PetSellerProfileWindow(QWidget *parent = nullptr);
    ~PetSellerProfileWindow();

public slots:
    void updateProfile(const QString &username, const QString &businessLocation, const QString &province);


    void setProfileInfo(const QString& username, const QString& businessLocation, const QString& province);

private slots:
    void openProfilePicture();
    void openPostPicture();

private:
    Ui::PetSellerProfileWindow *ui;
};

#endif // PETSELLERPROFILEWINDOW_H
