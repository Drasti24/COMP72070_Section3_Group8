// #ifndef PETADOPTERPROFILEWINDOW_H
// #define PETADOPTERPROFILEWINDOW_H

// #include <QMainWindow>

// QT_BEGIN_NAMESPACE
// namespace Ui { class PetAdopterProfileWindow; }
// QT_END_NAMESPACE

// class PetAdopterProfileWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     PetAdopterProfileWindow(QWidget *parent = nullptr);
//     ~PetAdopterProfileWindow();

//     void setProfileInfo(const QString& username, const QString& bio);

// private:
//     Ui::PetAdopterProfileWindow *ui;
// };

// #endif // PETADOPTERPROFILEWINDOW_H
#ifndef PETADOPTERPROFILEWINDOW_H
#define PETADOPTERPROFILEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PetAdopterProfileWindow; }
QT_END_NAMESPACE

class PetAdopterProfileWindow : public QMainWindow
{
    Q_OBJECT

public:
    PetAdopterProfileWindow(QWidget *parent = nullptr);
    ~PetAdopterProfileWindow();

private slots:
    void openImage();

private:
    Ui::PetAdopterProfileWindow *ui;
};

#endif // PETADOPTERPROFILEWINDOW_H
