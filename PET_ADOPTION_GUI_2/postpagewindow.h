#ifndef POSTPAGEWINDOW_H
#define POSTPAGEWINDOW_H

#include <QMainWindow>

namespace Ui {
class PostPageWindow;
}

class PostPageWindow : public QMainWindow
{
    Q_OBJECT

public:
    PostPageWindow(QWidget *parent = nullptr);
    ~PostPageWindow();

private:
    Ui::PostPageWindow *ui;
};

#endif // POSTPAGEWINDOW_H
