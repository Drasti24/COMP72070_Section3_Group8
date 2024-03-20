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

private slots:
    void cancelClicked(); // Declaration for the cancelClicked slot

private:
    Ui::PetSellerWindow *ui;
     QPushButton *pushButtonCancel;
};

#endif // PET_SELLER_WINDOW_H
