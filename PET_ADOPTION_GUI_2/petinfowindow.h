#ifndef PETINFOWINDOW_H
#define PETINFOWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QAbstractButton>

namespace Ui {
class PetInfoWindow;
}

class PetInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PetInfoWindow(QWidget *parent = nullptr);
    ~PetInfoWindow();


private slots:
    void cancelClicked(); // Declaration for the cancelClicked slot
    void petInfoSubmitButtonClicked();

private:
    Ui::PetInfoWindow *ui;
    QPushButton *pushButtonCancel;
    QPushButton *submitButton;
    QButtonGroup *animalGroup;
    QButtonGroup *vaccinationGroup;
    QButtonGroup *animalAgeGroup;
};

#endif // PETINFOWINDOW_H
