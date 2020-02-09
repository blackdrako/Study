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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *line;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *tab_2;
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_11;
    QLineEdit *lineEdit_4;
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_12;
    QComboBox *comboBox_4;
    QCheckBox *checkBox_2;
    QWidget *tab_3;
    QPushButton *pushButton_6;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 580, 550));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(390, 170, 160, 25));
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 350, 160, 25));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 50, 55, 16));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(340, 120, 55, 16));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 270, 91, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 380, 281, 16));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 300, 231, 16));
        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(130, 270, 411, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(340, 80, 101, 16));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(340, 150, 55, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 550, 100));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(1);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(false);
        groupBox->setGeometry(QRect(20, 110, 360, 160));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setFlat(false);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 100, 122, 49));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_3->addWidget(lineEdit);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 263, 49));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(true);
        checkBox->setGeometry(QRect(30, 100, 140, 22));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setEnabled(false);
        groupBox_2->setGeometry(QRect(20, 310, 360, 160));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setLayoutDirection(Qt::LeftToRight);
        groupBox_2->setFlat(false);
        layoutWidget_6 = new QWidget(groupBox_2);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(20, 100, 122, 49));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_8->addWidget(label_11);

        lineEdit_4 = new QLineEdit(layoutWidget_6);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_8->addWidget(lineEdit_4);

        layoutWidget_7 = new QWidget(groupBox_2);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(20, 30, 263, 49));
        verticalLayout_9 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget_7);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_9->addWidget(label_12);

        comboBox_4 = new QComboBox(layoutWidget_7);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        verticalLayout_9->addWidget(comboBox_4);

        checkBox_2 = new QCheckBox(tab_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(30, 290, 140, 22));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(340, 230, 160, 25));
        layoutWidget2 = new QWidget(tab_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 20, 475, 118));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(40);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        tabWidget->addTab(tab_3, QString());
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(330, 570, 256, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);

        horizontalLayout->addWidget(pushButton_3);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(checkBox, SIGNAL(toggled(bool)), groupBox, SLOT(setChecked(bool)));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\264\320\260\321\202\321\203 \320\270 \320\262\321\200\320\265\320\274\321\217...", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\207\320\260\321\201\320\276\320\262\320\276\320\271 \320\277\320\276\321\217\321\201...", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\320\276\320\262\320\276\320\271 \320\277\320\276\321\217\321\201", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\321\205\320\276\320\264 \320\275\320\260 \320\267\320\270\320\274\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217 \320\270 \320\276\320\261\321\200\320\260\321\202\320\275\320\276 \320\276\321\202\320\274\320\265\320\275\320\265\320\275.", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p>(UTC 03:00) \320\234\320\276\321\201\320\272\320\262\320\260,\320\241\320\260\320\275\320\272\321\202-\320\237\320\265\321\202\320\265\321\200\320\261\321\203\321\200\320\263</p></body></html>", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "9 \321\204\320\265\320\262\321\200\320\260\320\273\321\217 2020.", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "12:38:47", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \321\207\320\260\321\201\321\213 \320\274\320\276\320\263\321\203\321\202 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214 \320\262\321\200\320\265\320\274\321\217 \320\264\320\273\321\217 \320\264\321\200\321\203\320\263\320\270\321\205 \321\207\320\260\321\201\320\276\320\262\321\213\321\205 \320\277\320\276\321\217\321\201\320\276\320\262. \320\247\321\202\320\276\320\261\321\213</p><p>\320\277\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\262\321\200\320\265\320\274\321\217 \320\275\320\260 \321\215\321\202\320\270\321\205 \321\207\320\260\321\201\320\260\321\205, \320\264\320\276\321\201\321\202\320\260\321\202\320\276\321\207\320\275\320\276 \321\211\320\265\320\273\320\272\320\275\321\203\321\202\321\214 \320\270\320\273\320\270 \320\277\321\200\320\276\321\201\321\202\320\276 \320\275\320\260\320\262\320\265"
                        "\321\201\321\202\320\270 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214</p><p>\320\274\321\213\321\210\320\270 \320\275\320\260 \321\207\320\260\321\201\321\213, \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\320\265\320\274\321\213\320\265 \320\275\320\260 \320\277\320\260\320\275\320\265\320\273\320\270 \320\267\320\260\320\264\320\260\321\207.</p></body></html>", nullptr));
        groupBox->setTitle(QString());
        label_8->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\260\320\265\320\274\320\276\320\265 \320\270\320\274\321\217:", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\213 1", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\207\320\260\321\201\320\276\320\262\320\276\320\271 \320\277\320\276\321\217\321\201:", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "(UTC +03:00) \320\234\320\276\321\201\320\272\320\262\320\260,\320\241\320\260\320\275\320\272\321\202-\320\237\320\265\321\202\320\265\321\200\320\261\321\203\321\200\320\263", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "(UTC +03:00) \320\235\320\260\320\271\321\200\320\276\320\261\320\270", nullptr));

        checkBox->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\215\321\202\320\270 \321\207\320\260\321\201\321\213", nullptr));
        groupBox_2->setTitle(QString());
        label_11->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\260\320\265\320\274\320\276\320\265 \320\270\320\274\321\217:", nullptr));
        lineEdit_4->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\213 1", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\207\320\260\321\201\320\276\320\262\320\276\320\271 \320\277\320\276\321\217\321\201:", nullptr));
        comboBox_4->setItemText(0, QApplication::translate("MainWindow", "(UTC +03:00) \320\234\320\276\321\201\320\272\320\262\320\260,\320\241\320\260\320\275\320\272\321\202-\320\237\320\265\321\202\320\265\321\200\320\261\321\203\321\200\320\263", nullptr));
        comboBox_4->setItemText(1, QApplication::translate("MainWindow", "(UTC +03:00) \320\235\320\260\320\271\321\200\320\276\320\261\320\270", nullptr));

        checkBox_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\215\321\202\320\270 \321\207\320\260\321\201\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \321\207\320\260\321\201\321\213", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213...", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\232\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\275 \320\275\320\260 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\321\203\321\216 \321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\270\320\267\320\260\321\206\320\270\321\216 \321\201 &quot;time.windows.com&quot;.</p><p><br/></p></body></html>", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\255\321\202\320\276\321\202 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\275 \320\275\320\260 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\321\203\321\216 \321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\270\320\267\320\260\321\206\320\270\321\216 \320\277\320\276 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\321\216.</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\277\320\276 \320\230\320\275\321\202\320\265\321\200\320\275\320\265\321\202\321\203", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\320\272", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
