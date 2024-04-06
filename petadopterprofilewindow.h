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

public slots:
    void receiveValue(QString& unameValue, QString& bioValue);
    //void setProfileData(const QString &userName, const QString &bio);
   // void updateProfile(const QString &firstName, const QString &lastName, const QString &userName, const QString &bio);

private slots:
    void openImage();
    void OpenHomePage();

private:
    Ui::PetAdopterProfileWindow *ui;
};

#endif // PETADOPTERPROFILEWINDOW_H
