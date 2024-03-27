#ifndef COMMONLOGINWINDOW_H
#define COMMONLOGINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class CommonLoginWindow;
}

class CommonLoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CommonLoginWindow(QWidget *parent = nullptr);
    ~CommonLoginWindow();

private slots:
    void CancelButtonClicked();
    void SubmitButtonClicked();

private:
    Ui::CommonLoginWindow *ui;
    QPushButton *cancelButton;
    QPushButton *submitButton;
};

#endif // COMMONLOGINWINDOW_H
