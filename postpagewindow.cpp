#include "postpagewindow.h"
#include "ui_postpagewindow.h"

PostPageWindow::PostPageWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PostPageWindow)
{
    ui->setupUi(this);
    // QWidget *centralWidget = new QWidget(this);
    // setCentralWidget(centralWidget);
}

PostPageWindow::~PostPageWindow()
{
    delete ui;
}
