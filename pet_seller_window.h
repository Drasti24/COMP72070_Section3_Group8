#ifndef PET_SELLER_WINDOW_H
#define PET_SELLER_WINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class PetSellerWindow; }
QT_END_NAMESPACE

class PetSellerWindow : public QMainWindow
{
    Q_OBJECT

public:
    PetSellerWindow(QWidget *parent = nullptr);
    ~PetSellerWindow();

signals:
    void submitSellerData(const QString &firstName, const QString &lastName, const QString &username,
                          const QString &password, const QString &businessLocation,
                          const QString &province, const QString &postalCode, const QString &phoneNumber);
private slots:
    void cancelClicked(); // Declaration for the cancelClicked slot
    void submitButtonClicked();

private:
    Ui::PetSellerWindow *ui;
    QPushButton *pushButtonCancel;
    QPushButton *submitButton;
};

#endif // PET_SELLER_WINDOW_H
