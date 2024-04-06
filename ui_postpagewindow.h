/********************************************************************************
** Form generated from reading UI file 'postpagewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTPAGEWINDOW_H
#define UI_POSTPAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostPageWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *imageLabel1;
    QLabel *imageLabel2;
    QHBoxLayout *horizontalLayout;
    QLabel *captionLabel1;
    QLabel *captionLabel2;

    void setupUi(QMainWindow *PostPageWindow)
    {
        if (PostPageWindow->objectName().isEmpty())
            PostPageWindow->setObjectName("PostPageWindow");
        PostPageWindow->resize(800, 600);
        centralWidget = new QWidget(PostPageWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        imageLabel1 = new QLabel(centralWidget);
        imageLabel1->setObjectName("imageLabel1");
        imageLabel1->setMaximumSize(QSize(80, 50));
        imageLabel1->setScaledContents(true);

        gridLayout->addWidget(imageLabel1, 0, 0, 1, 1);

        imageLabel2 = new QLabel(centralWidget);
        imageLabel2->setObjectName("imageLabel2");
        imageLabel2->setMaximumSize(QSize(80, 50));
        imageLabel2->setScaledContents(true);

        gridLayout->addWidget(imageLabel2, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        captionLabel1 = new QLabel(centralWidget);
        captionLabel1->setObjectName("captionLabel1");

        horizontalLayout->addWidget(captionLabel1);

        captionLabel2 = new QLabel(centralWidget);
        captionLabel2->setObjectName("captionLabel2");

        horizontalLayout->addWidget(captionLabel2);


        verticalLayout->addLayout(horizontalLayout);

        PostPageWindow->setCentralWidget(centralWidget);

        retranslateUi(PostPageWindow);

        QMetaObject::connectSlotsByName(PostPageWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PostPageWindow)
    {
        PostPageWindow->setWindowTitle(QCoreApplication::translate("PostPageWindow", "Home", nullptr));
        imageLabel1->setText(QCoreApplication::translate("PostPageWindow", "Image 1", nullptr));
        imageLabel2->setText(QCoreApplication::translate("PostPageWindow", "Image 2", nullptr));
        captionLabel1->setText(QCoreApplication::translate("PostPageWindow", "Caption here...", nullptr));
        captionLabel2->setText(QCoreApplication::translate("PostPageWindow", "Caption here...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PostPageWindow: public Ui_PostPageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTPAGEWINDOW_H
