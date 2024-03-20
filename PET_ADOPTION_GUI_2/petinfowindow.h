#ifndef PETINFOWINDOW_H
#define PETINFOWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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

private:
    Ui::PetInfoWindow *ui;
    QPushButton *pushButtonCancel;
};

#endif // PETINFOWINDOW_H
