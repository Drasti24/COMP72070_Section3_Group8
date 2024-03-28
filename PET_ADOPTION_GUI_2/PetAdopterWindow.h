#ifndef PETADOPTERWINDOW_H
#define PETADOPTERWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class PetAdopterWindow; }
QT_END_NAMESPACE

class PetAdopterWindow : public QMainWindow
{
    Q_OBJECT

public:
    PetAdopterWindow(QWidget *parent = nullptr);
    ~PetAdopterWindow();

signals:
    void submitProfileData(const QString &firstName, const QString &lastName, const QString &userName, const QString &bio);

private slots:
    void cancelClicked(); // Declaration for the cancelClicked slot
    void submitButtonClicked();

private:
    Ui::PetAdopterWindow *ui;
    QPushButton *pushButtonCancel;
};

#endif // PETADOPTERWINDOW_H
