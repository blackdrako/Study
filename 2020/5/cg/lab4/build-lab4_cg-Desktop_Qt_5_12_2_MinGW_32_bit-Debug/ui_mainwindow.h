/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QWidget *tl;
    QWidget *tr;
    QWidget *bl;
    QWidget *br;
    QGridLayout *gridLayout_3;
    QRadioButton *free;
    QPushButton *zoomDec;
    QRadioButton *cabinet;
    QRadioButton *ortogonal;
    QPushButton *zoomInc;
    QRadioButton *central;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(716, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tl = new QWidget(centralwidget);
        tl->setObjectName(QString::fromUtf8("tl"));

        gridLayout->addWidget(tl, 0, 0, 1, 1);

        tr = new QWidget(centralwidget);
        tr->setObjectName(QString::fromUtf8("tr"));

        gridLayout->addWidget(tr, 0, 1, 1, 1);

        bl = new QWidget(centralwidget);
        bl->setObjectName(QString::fromUtf8("bl"));

        gridLayout->addWidget(bl, 2, 0, 1, 1);

        br = new QWidget(centralwidget);
        br->setObjectName(QString::fromUtf8("br"));

        gridLayout->addWidget(br, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        free = new QRadioButton(centralwidget);
        free->setObjectName(QString::fromUtf8("free"));

        gridLayout_3->addWidget(free, 0, 2, 1, 1);

        zoomDec = new QPushButton(centralwidget);
        zoomDec->setObjectName(QString::fromUtf8("zoomDec"));

        gridLayout_3->addWidget(zoomDec, 0, 5, 1, 1);

        cabinet = new QRadioButton(centralwidget);
        cabinet->setObjectName(QString::fromUtf8("cabinet"));

        gridLayout_3->addWidget(cabinet, 0, 1, 1, 1);

        ortogonal = new QRadioButton(centralwidget);
        ortogonal->setObjectName(QString::fromUtf8("ortogonal"));

        gridLayout_3->addWidget(ortogonal, 0, 3, 1, 1);

        zoomInc = new QPushButton(centralwidget);
        zoomInc->setObjectName(QString::fromUtf8("zoomInc"));

        gridLayout_3->addWidget(zoomInc, 0, 4, 1, 1);

        central = new QRadioButton(centralwidget);
        central->setObjectName(QString::fromUtf8("central"));

        gridLayout_3->addWidget(central, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        free->setText(QApplication::translate("MainWindow", "\320\241\320\262\320\276\320\261\320\276\320\264\320\275\320\260\321\217", nullptr));
        zoomDec->setText(QApplication::translate("MainWindow", "-", nullptr));
        cabinet->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\261\320\270\320\275\320\265\321\202\320\275\320\260\321\217", nullptr));
        ortogonal->setText(QApplication::translate("MainWindow", "\320\236\321\200\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\260\321\217", nullptr));
        zoomInc->setText(QApplication::translate("MainWindow", "+", nullptr));
        central->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
