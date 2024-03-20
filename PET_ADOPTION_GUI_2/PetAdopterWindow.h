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

private slots:
    void cancelClicked(); // Declaration for the cancelClicked slot

private:
    Ui::PetAdopterWindow *ui;
    QPushButton *pushButtonCancel;
};

#endif // PETADOPTERWINDOW_H
