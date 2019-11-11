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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox;
    QSlider *horizontalSlider;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_4;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox_5;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QSlider *horizontalSlider_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 450);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 380, 400));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(11, 2, 360, 121));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(40, 80, 311, 19));
        horizontalSlider = new QSlider(groupBox_3);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(80, 50, 160, 16));
        horizontalSlider->setValue(0);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(9);
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 47, 13));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 50, 47, 13));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(11, 129, 360, 71));
        groupBox_4->setMinimumSize(QSize(349, 0));
        checkBox_2 = new QCheckBox(groupBox_4);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(40, 20, 221, 19));
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(11, 199, 360, 161));
        checkBox_3 = new QCheckBox(groupBox_5);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(40, 30, 201, 19));
        checkBox_4 = new QCheckBox(groupBox_5);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(40, 80, 281, 19));
        checkBox_5 = new QCheckBox(groupBox_5);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(40, 130, 281, 24));
        horizontalSlider_2 = new QSlider(groupBox_5);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(80, 55, 160, 16));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider_2->sizePolicy().hasHeightForWidth());
        horizontalSlider_2->setSizePolicy(sizePolicy);
        horizontalSlider_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(16);
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 50, 47, 13));
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 55, 47, 13));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(11, 1, 349, 177));
        groupBox->setAutoFillBackground(false);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(11, 184, 349, 176));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(260, 150, 80, 21));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 81, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 50, 71, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 80, 61, 16));
        tabWidget->addTab(tab_2, QString());
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 420, 80, 21));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 420, 80, 21));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 420, 80, 21));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\241\320\262\320\276\320\271\321\201\321\202\320\262\320\260: \320\234\321\213\321\210\321\214", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\277\320\276\320\262\321\213\321\210\320\265\320\275\320\275\321\203\321\216 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\217", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\235\320\270\320\266\320\265", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\210\320\265", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\320\276\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\262 \320\264\320\270\320\260\320\273\320\276\320\263\320\276\320\262\320\276\320\274 \320\276\320\272\320\275\320\265", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "\320\235\320\260 \320\272\320\275\320\276\320\277\320\272\320\265, \320\262\321\213\320\261\320\270\321\200\320\260\320\265\320\274\320\276\320\271 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\222\320\270\320\264\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        checkBox_3->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214 \321\201\320\273\320\265\320\264 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\217 \320\274\321\213\321\210\320\270", nullptr));
        checkBox_4->setText(QApplication::translate("MainWindow", "\320\241\320\272\321\200\321\213\320\262\320\260\321\202\321\214 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 \320\262\320\276 \320\262\321\200\320\265\320\274\321\217 \320\262\320\262\320\276\320\264\320\260 \321\201 \320\272\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\321\213", nullptr));
        checkBox_5->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\276\320\267\320\275\320\260\321\207\320\270\321\202\321\214 \321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\217 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270\n"
"CTRL", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\275\320\265\320\265", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\200\320\276\321\207\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\217", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260:", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\241\320\262\320\276\320\271\321\201\321\202\320\262\320\260 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\241\320\262\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\230\320\267\320\263\320\276\321\202\320\276\320\262\320\270\321\202\320\265\320\273\321\214:</p></body></html>", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\240\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\320\265:</p></body></html>", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265:</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\236\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\320\232", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
