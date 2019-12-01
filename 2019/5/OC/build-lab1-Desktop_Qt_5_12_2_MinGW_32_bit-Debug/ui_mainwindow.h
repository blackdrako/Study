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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QCommandLinkButton *commandLinkSystemInfo;
    QCommandLinkButton *commandLinkMetrics;
    QCommandLinkButton *commandLinkSystemParams;
    QCommandLinkButton *commandLinkColors;
    QCommandLinkButton *commandLinkSystemTime;
    QCommandLinkButton *commandLinkOtherApi;
    QSpacerItem *verticalSpacer;
    QFrame *line_3;
    QStackedWidget *stackedWidget;
    QWidget *pageSystemInfo;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *labelComputerName;
    QLabel *label_3;
    QLabel *labelUserName;
    QFrame *line;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QLabel *labelSystemPath;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *labelWindowsPath;
    QLabel *labelTempPath;
    QFrame *line_2;
    QFormLayout *formLayout_4;
    QLabel *label_7;
    QLabel *labelVersion;
    QLabel *label_11;
    QLabel *labelBuild;
    QLabel *label_6;
    QLabel *labelPlatform;
    QLabel *label_9;
    QLabel *labelCSDVersion;
    QSpacerItem *verticalSpacer_2;
    QWidget *pageMetrics;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableMetrics;
    QWidget *pageSystemParams;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupGetters;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QLabel *labelAccessTimeOutOn;
    QLabel *label_12;
    QLabel *labelAccessOnOffFeedback;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *labelAccessTimeOut;
    QLabel *labelScreenReaderOn;
    QLabel *labelKeyboardPreffered;
    QLabel *labelScreenSaverRunning;
    QGroupBox *groupFilterKeys;
    QVBoxLayout *verticalLayout_6;
    QFormLayout *formLayout_5;
    QLabel *label_14;
    QComboBox *comboBoxFKFilterAvailable;
    QLabel *label_15;
    QComboBox *comboBoxFKClickOn;
    QLabel *label_10;
    QComboBox *comboBoxFKConfirmHotkey;
    QLabel *label_13;
    QComboBox *comboBoxFKIsOn;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QComboBox *comboBoxFKHotkeyActive;
    QComboBox *comboBoxFKHotkeySound;
    QComboBox *comboBoxFKIndicator;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QSpinBox *spinBoxFKWait;
    QSpinBox *spinBoxFKRepeat;
    QSpinBox *spinBoxFKBounce;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSetFK;
    QPushButton *pushButtonResetFK;
    QGroupBox *groupMinimizedMetrics;
    QVBoxLayout *verticalLayout_7;
    QFormLayout *formLayout_6;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QComboBox *comboBoxMMStart;
    QComboBox *comboBoxMMDirection;
    QSpinBox *spinBoxMMWidth;
    QSpinBox *spinBoxMMHorizontalGap;
    QSpinBox *spinBoxMMVerticalGap;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonSetMM;
    QPushButton *pushButtonResetMM;
    QSpacerItem *verticalSpacer_4;
    QWidget *pageColors;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_15;
    QPushButton *pushButtonChooseACTIVECAPTION;
    QPushButton *pushButtonSetACTIVECAPTION;
    QPushButton *pushButtonResetACTIVECAPTION;
    QVBoxLayout *verticalLayout_12;
    QPushButton *pushButtonChoose3DDKSHADOW;
    QPushButton *pushButtonSet3DDKSHADOW;
    QPushButton *pushButtonReset3DDKSHADOW;
    QLabel *label3DDKSHADOW_old;
    QLabel *labelBTNTEXT_old;
    QLabel *labelACTIVECAPTION_new;
    QLabel *labelACTIVECAPTION_old;
    QLabel *label3DDKSHADOW_new;
    QVBoxLayout *verticalLayout_13;
    QPushButton *pushButtonChooseBTNTEXT;
    QPushButton *pushButtonSetBTNTEXT;
    QPushButton *pushButtonResetBTNTEXT;
    QLabel *labelBTNTEXT_new;
    QSpacerItem *verticalSpacer_3;
    QWidget *pageTime;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QFormLayout *formLayout_7;
    QLabel *label_31;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelHour;
    QLabel *label_33;
    QLabel *labelMinute;
    QLabel *label_37;
    QLabel *labelSecond;
    QLabel *label_35;
    QLabel *labelMilliseconds;
    QSpacerItem *horizontalSpacer;
    QLabel *label_32;
    QLabel *labelYear;
    QLabel *label_34;
    QLabel *labelMonth;
    QLabel *label_36;
    QLabel *labelDay;
    QLabel *label_38;
    QLabel *labelDayOfWeek;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_9;
    QLabel *label_52;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelLocalHour;
    QLabel *label_47;
    QLabel *labelLocalMinute;
    QLabel *label_48;
    QLabel *labelLocalSecond;
    QLabel *label_49;
    QLabel *labelLocalMilliseconds;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelLocalYear;
    QLabel *labelLocalMonth;
    QLabel *labelLocalDay;
    QLabel *label_50;
    QLabel *labelLocalDayOfWeek;
    QLabel *label_55;
    QLabel *labelBias;
    QLabel *label_53;
    QLabel *label_54;
    QLabel *label_51;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_11;
    QLabel *labelDaylightActive;
    QGroupBox *groupStandard;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_46;
    QFormLayout *formLayout_10;
    QLabel *label_58;
    QLabel *labelTransitionStandardMonth;
    QLabel *label_60;
    QLabel *labelTransitionStandardDay;
    QGroupBox *groupDaylight;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_39;
    QFormLayout *formLayout_8;
    QLabel *label_42;
    QLabel *labelTransitionDalyightMonth;
    QLabel *label_44;
    QLabel *labelTransitionDalyightDay;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_11;
    QLabel *label_41;
    QLabel *label_43;
    QLabel *label_45;
    QLabel *label_57;
    QLabel *labelCalFormatShort;
    QLabel *labelCalFormatLong;
    QLabel *labelCalDayLong;
    QLabel *labelCalDayShort;
    QLabel *label_64;
    QLabel *label_65;
    QLabel *labelCalMonthLong;
    QLabel *labelCalMonthShort;
    QSpacerItem *verticalSpacer_5;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_17;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonPrev;
    QPushButton *pushButtonNext;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_9;
    QSpinBox *spinBoxCurrencyIn;
    QLabel *labelCurrencyOut;
    QGroupBox *groupBox_7;
    QFormLayout *formLayout_12;
    QLabel *label_40;
    QLabel *labelLastErrCode;
    QLabel *label_59;
    QLabel *labelLastErrMsg;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_7;
    QTextEdit *textSource;
    QPushButton *pushButtonOemToChar;
    QTextEdit *textDestination;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 778);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        commandLinkSystemInfo = new QCommandLinkButton(centralwidget);
        commandLinkSystemInfo->setObjectName(QString::fromUtf8("commandLinkSystemInfo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(commandLinkSystemInfo->sizePolicy().hasHeightForWidth());
        commandLinkSystemInfo->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(commandLinkSystemInfo);

        commandLinkMetrics = new QCommandLinkButton(centralwidget);
        commandLinkMetrics->setObjectName(QString::fromUtf8("commandLinkMetrics"));
        sizePolicy.setHeightForWidth(commandLinkMetrics->sizePolicy().hasHeightForWidth());
        commandLinkMetrics->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(commandLinkMetrics);

        commandLinkSystemParams = new QCommandLinkButton(centralwidget);
        commandLinkSystemParams->setObjectName(QString::fromUtf8("commandLinkSystemParams"));

        verticalLayout->addWidget(commandLinkSystemParams);

        commandLinkColors = new QCommandLinkButton(centralwidget);
        commandLinkColors->setObjectName(QString::fromUtf8("commandLinkColors"));

        verticalLayout->addWidget(commandLinkColors);

        commandLinkSystemTime = new QCommandLinkButton(centralwidget);
        commandLinkSystemTime->setObjectName(QString::fromUtf8("commandLinkSystemTime"));

        verticalLayout->addWidget(commandLinkSystemTime);

        commandLinkOtherApi = new QCommandLinkButton(centralwidget);
        commandLinkOtherApi->setObjectName(QString::fromUtf8("commandLinkOtherApi"));

        verticalLayout->addWidget(commandLinkOtherApi);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pageSystemInfo = new QWidget();
        pageSystemInfo->setObjectName(QString::fromUtf8("pageSystemInfo"));
        verticalLayout_2 = new QVBoxLayout(pageSystemInfo);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(pageSystemInfo);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(8);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        labelComputerName = new QLabel(pageSystemInfo);
        labelComputerName->setObjectName(QString::fromUtf8("labelComputerName"));
        labelComputerName->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, labelComputerName);

        label_3 = new QLabel(pageSystemInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        labelUserName = new QLabel(pageSystemInfo);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        labelUserName->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, labelUserName);


        verticalLayout_2->addLayout(formLayout);

        line = new QFrame(pageSystemInfo);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_5 = new QLabel(pageSystemInfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        labelSystemPath = new QLabel(pageSystemInfo);
        labelSystemPath->setObjectName(QString::fromUtf8("labelSystemPath"));
        labelSystemPath->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, labelSystemPath);

        label_2 = new QLabel(pageSystemInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_2);

        label_4 = new QLabel(pageSystemInfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_4);

        labelWindowsPath = new QLabel(pageSystemInfo);
        labelWindowsPath->setObjectName(QString::fromUtf8("labelWindowsPath"));
        labelWindowsPath->setFont(font);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, labelWindowsPath);

        labelTempPath = new QLabel(pageSystemInfo);
        labelTempPath->setObjectName(QString::fromUtf8("labelTempPath"));
        labelTempPath->setFont(font);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, labelTempPath);


        verticalLayout_2->addLayout(formLayout_3);

        line_2 = new QFrame(pageSystemInfo);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_7 = new QLabel(pageSystemInfo);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_7);

        labelVersion = new QLabel(pageSystemInfo);
        labelVersion->setObjectName(QString::fromUtf8("labelVersion"));
        labelVersion->setFont(font);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, labelVersion);

        label_11 = new QLabel(pageSystemInfo);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_11);

        labelBuild = new QLabel(pageSystemInfo);
        labelBuild->setObjectName(QString::fromUtf8("labelBuild"));
        labelBuild->setFont(font);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, labelBuild);

        label_6 = new QLabel(pageSystemInfo);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_6);

        labelPlatform = new QLabel(pageSystemInfo);
        labelPlatform->setObjectName(QString::fromUtf8("labelPlatform"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, labelPlatform);

        label_9 = new QLabel(pageSystemInfo);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_9);

        labelCSDVersion = new QLabel(pageSystemInfo);
        labelCSDVersion->setObjectName(QString::fromUtf8("labelCSDVersion"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, labelCSDVersion);


        verticalLayout_2->addLayout(formLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        stackedWidget->addWidget(pageSystemInfo);
        pageMetrics = new QWidget();
        pageMetrics->setObjectName(QString::fromUtf8("pageMetrics"));
        verticalLayout_3 = new QVBoxLayout(pageMetrics);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        scrollArea = new QScrollArea(pageMetrics);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 570, 699));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tableMetrics = new QTableWidget(scrollAreaWidgetContents);
        tableMetrics->setObjectName(QString::fromUtf8("tableMetrics"));
        tableMetrics->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_4->addWidget(tableMetrics);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        stackedWidget->addWidget(pageMetrics);
        pageSystemParams = new QWidget();
        pageSystemParams->setObjectName(QString::fromUtf8("pageSystemParams"));
        verticalLayout_5 = new QVBoxLayout(pageSystemParams);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupGetters = new QGroupBox(pageSystemParams);
        groupGetters->setObjectName(QString::fromUtf8("groupGetters"));
        formLayout_2 = new QFormLayout(groupGetters);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_8 = new QLabel(groupGetters);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_8);

        labelAccessTimeOutOn = new QLabel(groupGetters);
        labelAccessTimeOutOn->setObjectName(QString::fromUtf8("labelAccessTimeOutOn"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, labelAccessTimeOutOn);

        label_12 = new QLabel(groupGetters);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_12);

        labelAccessOnOffFeedback = new QLabel(groupGetters);
        labelAccessOnOffFeedback->setObjectName(QString::fromUtf8("labelAccessOnOffFeedback"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, labelAccessOnOffFeedback);

        label_18 = new QLabel(groupGetters);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_18);

        label_19 = new QLabel(groupGetters);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_19);

        label_20 = new QLabel(groupGetters);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_20);

        label_21 = new QLabel(groupGetters);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_21);

        labelAccessTimeOut = new QLabel(groupGetters);
        labelAccessTimeOut->setObjectName(QString::fromUtf8("labelAccessTimeOut"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, labelAccessTimeOut);

        labelScreenReaderOn = new QLabel(groupGetters);
        labelScreenReaderOn->setObjectName(QString::fromUtf8("labelScreenReaderOn"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, labelScreenReaderOn);

        labelKeyboardPreffered = new QLabel(groupGetters);
        labelKeyboardPreffered->setObjectName(QString::fromUtf8("labelKeyboardPreffered"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, labelKeyboardPreffered);

        labelScreenSaverRunning = new QLabel(groupGetters);
        labelScreenSaverRunning->setObjectName(QString::fromUtf8("labelScreenSaverRunning"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, labelScreenSaverRunning);


        verticalLayout_5->addWidget(groupGetters);

        groupFilterKeys = new QGroupBox(pageSystemParams);
        groupFilterKeys->setObjectName(QString::fromUtf8("groupFilterKeys"));
        verticalLayout_6 = new QVBoxLayout(groupFilterKeys);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_14 = new QLabel(groupFilterKeys);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_14);

        comboBoxFKFilterAvailable = new QComboBox(groupFilterKeys);
        comboBoxFKFilterAvailable->addItem(QString());
        comboBoxFKFilterAvailable->addItem(QString());
        comboBoxFKFilterAvailable->setObjectName(QString::fromUtf8("comboBoxFKFilterAvailable"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, comboBoxFKFilterAvailable);

        label_15 = new QLabel(groupFilterKeys);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_15);

        comboBoxFKClickOn = new QComboBox(groupFilterKeys);
        comboBoxFKClickOn->addItem(QString());
        comboBoxFKClickOn->addItem(QString());
        comboBoxFKClickOn->setObjectName(QString::fromUtf8("comboBoxFKClickOn"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, comboBoxFKClickOn);

        label_10 = new QLabel(groupFilterKeys);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_10);

        comboBoxFKConfirmHotkey = new QComboBox(groupFilterKeys);
        comboBoxFKConfirmHotkey->addItem(QString());
        comboBoxFKConfirmHotkey->addItem(QString());
        comboBoxFKConfirmHotkey->setObjectName(QString::fromUtf8("comboBoxFKConfirmHotkey"));

        formLayout_5->setWidget(3, QFormLayout::FieldRole, comboBoxFKConfirmHotkey);

        label_13 = new QLabel(groupFilterKeys);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_13);

        comboBoxFKIsOn = new QComboBox(groupFilterKeys);
        comboBoxFKIsOn->addItem(QString());
        comboBoxFKIsOn->addItem(QString());
        comboBoxFKIsOn->setObjectName(QString::fromUtf8("comboBoxFKIsOn"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, comboBoxFKIsOn);

        label_22 = new QLabel(groupFilterKeys);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, label_22);

        label_23 = new QLabel(groupFilterKeys);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        formLayout_5->setWidget(5, QFormLayout::LabelRole, label_23);

        label_24 = new QLabel(groupFilterKeys);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        formLayout_5->setWidget(6, QFormLayout::LabelRole, label_24);

        comboBoxFKHotkeyActive = new QComboBox(groupFilterKeys);
        comboBoxFKHotkeyActive->addItem(QString());
        comboBoxFKHotkeyActive->addItem(QString());
        comboBoxFKHotkeyActive->setObjectName(QString::fromUtf8("comboBoxFKHotkeyActive"));

        formLayout_5->setWidget(4, QFormLayout::FieldRole, comboBoxFKHotkeyActive);

        comboBoxFKHotkeySound = new QComboBox(groupFilterKeys);
        comboBoxFKHotkeySound->addItem(QString());
        comboBoxFKHotkeySound->addItem(QString());
        comboBoxFKHotkeySound->setObjectName(QString::fromUtf8("comboBoxFKHotkeySound"));

        formLayout_5->setWidget(5, QFormLayout::FieldRole, comboBoxFKHotkeySound);

        comboBoxFKIndicator = new QComboBox(groupFilterKeys);
        comboBoxFKIndicator->addItem(QString());
        comboBoxFKIndicator->addItem(QString());
        comboBoxFKIndicator->setObjectName(QString::fromUtf8("comboBoxFKIndicator"));

        formLayout_5->setWidget(6, QFormLayout::FieldRole, comboBoxFKIndicator);

        label_25 = new QLabel(groupFilterKeys);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        formLayout_5->setWidget(7, QFormLayout::LabelRole, label_25);

        label_26 = new QLabel(groupFilterKeys);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        formLayout_5->setWidget(8, QFormLayout::LabelRole, label_26);

        label_27 = new QLabel(groupFilterKeys);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        formLayout_5->setWidget(9, QFormLayout::LabelRole, label_27);

        spinBoxFKWait = new QSpinBox(groupFilterKeys);
        spinBoxFKWait->setObjectName(QString::fromUtf8("spinBoxFKWait"));
        spinBoxFKWait->setMaximum(10000);

        formLayout_5->setWidget(7, QFormLayout::FieldRole, spinBoxFKWait);

        spinBoxFKRepeat = new QSpinBox(groupFilterKeys);
        spinBoxFKRepeat->setObjectName(QString::fromUtf8("spinBoxFKRepeat"));
        spinBoxFKRepeat->setMaximum(10000);

        formLayout_5->setWidget(8, QFormLayout::FieldRole, spinBoxFKRepeat);

        spinBoxFKBounce = new QSpinBox(groupFilterKeys);
        spinBoxFKBounce->setObjectName(QString::fromUtf8("spinBoxFKBounce"));
        spinBoxFKBounce->setMaximum(10000);

        formLayout_5->setWidget(9, QFormLayout::FieldRole, spinBoxFKBounce);


        verticalLayout_6->addLayout(formLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButtonSetFK = new QPushButton(groupFilterKeys);
        pushButtonSetFK->setObjectName(QString::fromUtf8("pushButtonSetFK"));

        horizontalLayout_2->addWidget(pushButtonSetFK);

        pushButtonResetFK = new QPushButton(groupFilterKeys);
        pushButtonResetFK->setObjectName(QString::fromUtf8("pushButtonResetFK"));

        horizontalLayout_2->addWidget(pushButtonResetFK);


        verticalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout_5->addWidget(groupFilterKeys);

        groupMinimizedMetrics = new QGroupBox(pageSystemParams);
        groupMinimizedMetrics->setObjectName(QString::fromUtf8("groupMinimizedMetrics"));
        verticalLayout_7 = new QVBoxLayout(groupMinimizedMetrics);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        label_16 = new QLabel(groupMinimizedMetrics);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_16);

        label_17 = new QLabel(groupMinimizedMetrics);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_17);

        label_28 = new QLabel(groupMinimizedMetrics);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, label_28);

        label_29 = new QLabel(groupMinimizedMetrics);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        formLayout_6->setWidget(3, QFormLayout::LabelRole, label_29);

        label_30 = new QLabel(groupMinimizedMetrics);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        formLayout_6->setWidget(4, QFormLayout::LabelRole, label_30);

        comboBoxMMStart = new QComboBox(groupMinimizedMetrics);
        comboBoxMMStart->addItem(QString());
        comboBoxMMStart->addItem(QString());
        comboBoxMMStart->addItem(QString());
        comboBoxMMStart->addItem(QString());
        comboBoxMMStart->setObjectName(QString::fromUtf8("comboBoxMMStart"));

        formLayout_6->setWidget(3, QFormLayout::FieldRole, comboBoxMMStart);

        comboBoxMMDirection = new QComboBox(groupMinimizedMetrics);
        comboBoxMMDirection->addItem(QString());
        comboBoxMMDirection->addItem(QString());
        comboBoxMMDirection->addItem(QString());
        comboBoxMMDirection->addItem(QString());
        comboBoxMMDirection->addItem(QString());
        comboBoxMMDirection->setObjectName(QString::fromUtf8("comboBoxMMDirection"));

        formLayout_6->setWidget(4, QFormLayout::FieldRole, comboBoxMMDirection);

        spinBoxMMWidth = new QSpinBox(groupMinimizedMetrics);
        spinBoxMMWidth->setObjectName(QString::fromUtf8("spinBoxMMWidth"));
        spinBoxMMWidth->setMaximum(10000);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, spinBoxMMWidth);

        spinBoxMMHorizontalGap = new QSpinBox(groupMinimizedMetrics);
        spinBoxMMHorizontalGap->setObjectName(QString::fromUtf8("spinBoxMMHorizontalGap"));
        spinBoxMMHorizontalGap->setMaximum(10000);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, spinBoxMMHorizontalGap);

        spinBoxMMVerticalGap = new QSpinBox(groupMinimizedMetrics);
        spinBoxMMVerticalGap->setObjectName(QString::fromUtf8("spinBoxMMVerticalGap"));
        spinBoxMMVerticalGap->setMaximum(10000);

        formLayout_6->setWidget(2, QFormLayout::FieldRole, spinBoxMMVerticalGap);


        verticalLayout_7->addLayout(formLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButtonSetMM = new QPushButton(groupMinimizedMetrics);
        pushButtonSetMM->setObjectName(QString::fromUtf8("pushButtonSetMM"));

        horizontalLayout_3->addWidget(pushButtonSetMM);

        pushButtonResetMM = new QPushButton(groupMinimizedMetrics);
        pushButtonResetMM->setObjectName(QString::fromUtf8("pushButtonResetMM"));

        horizontalLayout_3->addWidget(pushButtonResetMM);


        verticalLayout_7->addLayout(horizontalLayout_3);


        verticalLayout_5->addWidget(groupMinimizedMetrics);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        stackedWidget->addWidget(pageSystemParams);
        pageColors = new QWidget();
        pageColors->setObjectName(QString::fromUtf8("pageColors"));
        gridLayout = new QGridLayout(pageColors);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        pushButtonChooseACTIVECAPTION = new QPushButton(pageColors);
        pushButtonChooseACTIVECAPTION->setObjectName(QString::fromUtf8("pushButtonChooseACTIVECAPTION"));

        verticalLayout_15->addWidget(pushButtonChooseACTIVECAPTION);

        pushButtonSetACTIVECAPTION = new QPushButton(pageColors);
        pushButtonSetACTIVECAPTION->setObjectName(QString::fromUtf8("pushButtonSetACTIVECAPTION"));

        verticalLayout_15->addWidget(pushButtonSetACTIVECAPTION);

        pushButtonResetACTIVECAPTION = new QPushButton(pageColors);
        pushButtonResetACTIVECAPTION->setObjectName(QString::fromUtf8("pushButtonResetACTIVECAPTION"));

        verticalLayout_15->addWidget(pushButtonResetACTIVECAPTION);


        gridLayout->addLayout(verticalLayout_15, 3, 0, 1, 1);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        pushButtonChoose3DDKSHADOW = new QPushButton(pageColors);
        pushButtonChoose3DDKSHADOW->setObjectName(QString::fromUtf8("pushButtonChoose3DDKSHADOW"));

        verticalLayout_12->addWidget(pushButtonChoose3DDKSHADOW);

        pushButtonSet3DDKSHADOW = new QPushButton(pageColors);
        pushButtonSet3DDKSHADOW->setObjectName(QString::fromUtf8("pushButtonSet3DDKSHADOW"));

        verticalLayout_12->addWidget(pushButtonSet3DDKSHADOW);

        pushButtonReset3DDKSHADOW = new QPushButton(pageColors);
        pushButtonReset3DDKSHADOW->setObjectName(QString::fromUtf8("pushButtonReset3DDKSHADOW"));

        verticalLayout_12->addWidget(pushButtonReset3DDKSHADOW);


        gridLayout->addLayout(verticalLayout_12, 0, 0, 1, 1);

        label3DDKSHADOW_old = new QLabel(pageColors);
        label3DDKSHADOW_old->setObjectName(QString::fromUtf8("label3DDKSHADOW_old"));
        label3DDKSHADOW_old->setAutoFillBackground(true);

        gridLayout->addWidget(label3DDKSHADOW_old, 0, 1, 1, 1);

        labelBTNTEXT_old = new QLabel(pageColors);
        labelBTNTEXT_old->setObjectName(QString::fromUtf8("labelBTNTEXT_old"));
        labelBTNTEXT_old->setAutoFillBackground(true);

        gridLayout->addWidget(labelBTNTEXT_old, 1, 1, 1, 1);

        labelACTIVECAPTION_new = new QLabel(pageColors);
        labelACTIVECAPTION_new->setObjectName(QString::fromUtf8("labelACTIVECAPTION_new"));
        labelACTIVECAPTION_new->setAutoFillBackground(true);

        gridLayout->addWidget(labelACTIVECAPTION_new, 3, 2, 1, 1);

        labelACTIVECAPTION_old = new QLabel(pageColors);
        labelACTIVECAPTION_old->setObjectName(QString::fromUtf8("labelACTIVECAPTION_old"));
        labelACTIVECAPTION_old->setAutoFillBackground(true);

        gridLayout->addWidget(labelACTIVECAPTION_old, 3, 1, 1, 1);

        label3DDKSHADOW_new = new QLabel(pageColors);
        label3DDKSHADOW_new->setObjectName(QString::fromUtf8("label3DDKSHADOW_new"));
        label3DDKSHADOW_new->setAutoFillBackground(true);

        gridLayout->addWidget(label3DDKSHADOW_new, 0, 2, 1, 1);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        pushButtonChooseBTNTEXT = new QPushButton(pageColors);
        pushButtonChooseBTNTEXT->setObjectName(QString::fromUtf8("pushButtonChooseBTNTEXT"));

        verticalLayout_13->addWidget(pushButtonChooseBTNTEXT);

        pushButtonSetBTNTEXT = new QPushButton(pageColors);
        pushButtonSetBTNTEXT->setObjectName(QString::fromUtf8("pushButtonSetBTNTEXT"));

        verticalLayout_13->addWidget(pushButtonSetBTNTEXT);

        pushButtonResetBTNTEXT = new QPushButton(pageColors);
        pushButtonResetBTNTEXT->setObjectName(QString::fromUtf8("pushButtonResetBTNTEXT"));

        verticalLayout_13->addWidget(pushButtonResetBTNTEXT);


        gridLayout->addLayout(verticalLayout_13, 1, 0, 1, 1);

        labelBTNTEXT_new = new QLabel(pageColors);
        labelBTNTEXT_new->setObjectName(QString::fromUtf8("labelBTNTEXT_new"));
        labelBTNTEXT_new->setAutoFillBackground(true);

        gridLayout->addWidget(labelBTNTEXT_new, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 0, 1, 1);

        stackedWidget->addWidget(pageColors);
        pageTime = new QWidget();
        pageTime->setObjectName(QString::fromUtf8("pageTime"));
        verticalLayout_8 = new QVBoxLayout(pageTime);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        groupBox = new QGroupBox(pageTime);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_31 = new QLabel(groupBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_31);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelHour = new QLabel(groupBox);
        labelHour->setObjectName(QString::fromUtf8("labelHour"));

        horizontalLayout_6->addWidget(labelHour);

        label_33 = new QLabel(groupBox);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_33);

        labelMinute = new QLabel(groupBox);
        labelMinute->setObjectName(QString::fromUtf8("labelMinute"));

        horizontalLayout_6->addWidget(labelMinute);

        label_37 = new QLabel(groupBox);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        sizePolicy1.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_37);

        labelSecond = new QLabel(groupBox);
        labelSecond->setObjectName(QString::fromUtf8("labelSecond"));

        horizontalLayout_6->addWidget(labelSecond);

        label_35 = new QLabel(groupBox);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        sizePolicy1.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_35);

        labelMilliseconds = new QLabel(groupBox);
        labelMilliseconds->setObjectName(QString::fromUtf8("labelMilliseconds"));

        horizontalLayout_6->addWidget(labelMilliseconds);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        formLayout_7->setLayout(0, QFormLayout::FieldRole, horizontalLayout_6);

        label_32 = new QLabel(groupBox);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        formLayout_7->setWidget(1, QFormLayout::LabelRole, label_32);

        labelYear = new QLabel(groupBox);
        labelYear->setObjectName(QString::fromUtf8("labelYear"));

        formLayout_7->setWidget(1, QFormLayout::FieldRole, labelYear);

        label_34 = new QLabel(groupBox);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        formLayout_7->setWidget(2, QFormLayout::LabelRole, label_34);

        labelMonth = new QLabel(groupBox);
        labelMonth->setObjectName(QString::fromUtf8("labelMonth"));

        formLayout_7->setWidget(2, QFormLayout::FieldRole, labelMonth);

        label_36 = new QLabel(groupBox);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        formLayout_7->setWidget(3, QFormLayout::LabelRole, label_36);

        labelDay = new QLabel(groupBox);
        labelDay->setObjectName(QString::fromUtf8("labelDay"));

        formLayout_7->setWidget(3, QFormLayout::FieldRole, labelDay);

        label_38 = new QLabel(groupBox);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        formLayout_7->setWidget(4, QFormLayout::LabelRole, label_38);

        labelDayOfWeek = new QLabel(groupBox);
        labelDayOfWeek->setObjectName(QString::fromUtf8("labelDayOfWeek"));

        formLayout_7->setWidget(4, QFormLayout::FieldRole, labelDayOfWeek);


        horizontalLayout_5->addLayout(formLayout_7);


        verticalLayout_8->addWidget(groupBox);

        groupBox_2 = new QGroupBox(pageTime);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_9 = new QFormLayout(groupBox_2);
        formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
        label_52 = new QLabel(groupBox_2);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        formLayout_9->setWidget(1, QFormLayout::LabelRole, label_52);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        labelLocalHour = new QLabel(groupBox_2);
        labelLocalHour->setObjectName(QString::fromUtf8("labelLocalHour"));

        horizontalLayout_8->addWidget(labelLocalHour);

        label_47 = new QLabel(groupBox_2);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        sizePolicy1.setHeightForWidth(label_47->sizePolicy().hasHeightForWidth());
        label_47->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(label_47);

        labelLocalMinute = new QLabel(groupBox_2);
        labelLocalMinute->setObjectName(QString::fromUtf8("labelLocalMinute"));

        horizontalLayout_8->addWidget(labelLocalMinute);

        label_48 = new QLabel(groupBox_2);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        sizePolicy1.setHeightForWidth(label_48->sizePolicy().hasHeightForWidth());
        label_48->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(label_48);

        labelLocalSecond = new QLabel(groupBox_2);
        labelLocalSecond->setObjectName(QString::fromUtf8("labelLocalSecond"));

        horizontalLayout_8->addWidget(labelLocalSecond);

        label_49 = new QLabel(groupBox_2);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        sizePolicy1.setHeightForWidth(label_49->sizePolicy().hasHeightForWidth());
        label_49->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(label_49);

        labelLocalMilliseconds = new QLabel(groupBox_2);
        labelLocalMilliseconds->setObjectName(QString::fromUtf8("labelLocalMilliseconds"));

        horizontalLayout_8->addWidget(labelLocalMilliseconds);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        formLayout_9->setLayout(1, QFormLayout::FieldRole, horizontalLayout_8);

        labelLocalYear = new QLabel(groupBox_2);
        labelLocalYear->setObjectName(QString::fromUtf8("labelLocalYear"));

        formLayout_9->setWidget(2, QFormLayout::FieldRole, labelLocalYear);

        labelLocalMonth = new QLabel(groupBox_2);
        labelLocalMonth->setObjectName(QString::fromUtf8("labelLocalMonth"));

        formLayout_9->setWidget(3, QFormLayout::FieldRole, labelLocalMonth);

        labelLocalDay = new QLabel(groupBox_2);
        labelLocalDay->setObjectName(QString::fromUtf8("labelLocalDay"));

        formLayout_9->setWidget(4, QFormLayout::FieldRole, labelLocalDay);

        label_50 = new QLabel(groupBox_2);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        formLayout_9->setWidget(5, QFormLayout::LabelRole, label_50);

        labelLocalDayOfWeek = new QLabel(groupBox_2);
        labelLocalDayOfWeek->setObjectName(QString::fromUtf8("labelLocalDayOfWeek"));

        formLayout_9->setWidget(5, QFormLayout::FieldRole, labelLocalDayOfWeek);

        label_55 = new QLabel(groupBox_2);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        formLayout_9->setWidget(0, QFormLayout::LabelRole, label_55);

        labelBias = new QLabel(groupBox_2);
        labelBias->setObjectName(QString::fromUtf8("labelBias"));

        formLayout_9->setWidget(0, QFormLayout::FieldRole, labelBias);

        label_53 = new QLabel(groupBox_2);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        formLayout_9->setWidget(4, QFormLayout::LabelRole, label_53);

        label_54 = new QLabel(groupBox_2);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        formLayout_9->setWidget(3, QFormLayout::LabelRole, label_54);

        label_51 = new QLabel(groupBox_2);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        formLayout_9->setWidget(2, QFormLayout::LabelRole, label_51);


        verticalLayout_8->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(pageTime);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_11 = new QVBoxLayout(groupBox_4);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        labelDaylightActive = new QLabel(groupBox_4);
        labelDaylightActive->setObjectName(QString::fromUtf8("labelDaylightActive"));

        verticalLayout_11->addWidget(labelDaylightActive);

        groupStandard = new QGroupBox(groupBox_4);
        groupStandard->setObjectName(QString::fromUtf8("groupStandard"));
        verticalLayout_14 = new QVBoxLayout(groupStandard);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_46 = new QLabel(groupStandard);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        verticalLayout_9->addWidget(label_46);

        formLayout_10 = new QFormLayout();
        formLayout_10->setObjectName(QString::fromUtf8("formLayout_10"));
        label_58 = new QLabel(groupStandard);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        formLayout_10->setWidget(0, QFormLayout::LabelRole, label_58);

        labelTransitionStandardMonth = new QLabel(groupStandard);
        labelTransitionStandardMonth->setObjectName(QString::fromUtf8("labelTransitionStandardMonth"));

        formLayout_10->setWidget(0, QFormLayout::FieldRole, labelTransitionStandardMonth);

        label_60 = new QLabel(groupStandard);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        formLayout_10->setWidget(1, QFormLayout::LabelRole, label_60);

        labelTransitionStandardDay = new QLabel(groupStandard);
        labelTransitionStandardDay->setObjectName(QString::fromUtf8("labelTransitionStandardDay"));

        formLayout_10->setWidget(1, QFormLayout::FieldRole, labelTransitionStandardDay);


        verticalLayout_9->addLayout(formLayout_10);


        verticalLayout_14->addLayout(verticalLayout_9);


        verticalLayout_11->addWidget(groupStandard);

        groupDaylight = new QGroupBox(groupBox_4);
        groupDaylight->setObjectName(QString::fromUtf8("groupDaylight"));
        verticalLayout_16 = new QVBoxLayout(groupDaylight);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_39 = new QLabel(groupDaylight);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        verticalLayout_10->addWidget(label_39);

        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        label_42 = new QLabel(groupDaylight);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        formLayout_8->setWidget(0, QFormLayout::LabelRole, label_42);

        labelTransitionDalyightMonth = new QLabel(groupDaylight);
        labelTransitionDalyightMonth->setObjectName(QString::fromUtf8("labelTransitionDalyightMonth"));

        formLayout_8->setWidget(0, QFormLayout::FieldRole, labelTransitionDalyightMonth);

        label_44 = new QLabel(groupDaylight);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        formLayout_8->setWidget(1, QFormLayout::LabelRole, label_44);

        labelTransitionDalyightDay = new QLabel(groupDaylight);
        labelTransitionDalyightDay->setObjectName(QString::fromUtf8("labelTransitionDalyightDay"));

        formLayout_8->setWidget(1, QFormLayout::FieldRole, labelTransitionDalyightDay);


        verticalLayout_10->addLayout(formLayout_8);


        verticalLayout_16->addLayout(verticalLayout_10);


        verticalLayout_11->addWidget(groupDaylight);


        verticalLayout_8->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(pageTime);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        formLayout_11 = new QFormLayout(groupBox_3);
        formLayout_11->setObjectName(QString::fromUtf8("formLayout_11"));
        label_41 = new QLabel(groupBox_3);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        formLayout_11->setWidget(0, QFormLayout::LabelRole, label_41);

        label_43 = new QLabel(groupBox_3);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        formLayout_11->setWidget(1, QFormLayout::LabelRole, label_43);

        label_45 = new QLabel(groupBox_3);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        formLayout_11->setWidget(2, QFormLayout::LabelRole, label_45);

        label_57 = new QLabel(groupBox_3);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        formLayout_11->setWidget(3, QFormLayout::LabelRole, label_57);

        labelCalFormatShort = new QLabel(groupBox_3);
        labelCalFormatShort->setObjectName(QString::fromUtf8("labelCalFormatShort"));

        formLayout_11->setWidget(0, QFormLayout::FieldRole, labelCalFormatShort);

        labelCalFormatLong = new QLabel(groupBox_3);
        labelCalFormatLong->setObjectName(QString::fromUtf8("labelCalFormatLong"));

        formLayout_11->setWidget(1, QFormLayout::FieldRole, labelCalFormatLong);

        labelCalDayLong = new QLabel(groupBox_3);
        labelCalDayLong->setObjectName(QString::fromUtf8("labelCalDayLong"));

        formLayout_11->setWidget(2, QFormLayout::FieldRole, labelCalDayLong);

        labelCalDayShort = new QLabel(groupBox_3);
        labelCalDayShort->setObjectName(QString::fromUtf8("labelCalDayShort"));

        formLayout_11->setWidget(3, QFormLayout::FieldRole, labelCalDayShort);

        label_64 = new QLabel(groupBox_3);
        label_64->setObjectName(QString::fromUtf8("label_64"));

        formLayout_11->setWidget(4, QFormLayout::LabelRole, label_64);

        label_65 = new QLabel(groupBox_3);
        label_65->setObjectName(QString::fromUtf8("label_65"));

        formLayout_11->setWidget(5, QFormLayout::LabelRole, label_65);

        labelCalMonthLong = new QLabel(groupBox_3);
        labelCalMonthLong->setObjectName(QString::fromUtf8("labelCalMonthLong"));

        formLayout_11->setWidget(4, QFormLayout::FieldRole, labelCalMonthLong);

        labelCalMonthShort = new QLabel(groupBox_3);
        labelCalMonthShort->setObjectName(QString::fromUtf8("labelCalMonthShort"));

        formLayout_11->setWidget(5, QFormLayout::FieldRole, labelCalMonthShort);


        verticalLayout_8->addWidget(groupBox_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_5);

        stackedWidget->addWidget(pageTime);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_17 = new QVBoxLayout(page_2);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        groupBox_5 = new QGroupBox(page_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButtonPrev = new QPushButton(groupBox_5);
        pushButtonPrev->setObjectName(QString::fromUtf8("pushButtonPrev"));

        horizontalLayout_4->addWidget(pushButtonPrev);

        pushButtonNext = new QPushButton(groupBox_5);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));

        horizontalLayout_4->addWidget(pushButtonNext);


        verticalLayout_17->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(page_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        spinBoxCurrencyIn = new QSpinBox(groupBox_6);
        spinBoxCurrencyIn->setObjectName(QString::fromUtf8("spinBoxCurrencyIn"));

        horizontalLayout_9->addWidget(spinBoxCurrencyIn);

        labelCurrencyOut = new QLabel(groupBox_6);
        labelCurrencyOut->setObjectName(QString::fromUtf8("labelCurrencyOut"));

        horizontalLayout_9->addWidget(labelCurrencyOut);


        verticalLayout_17->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(page_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        formLayout_12 = new QFormLayout(groupBox_7);
        formLayout_12->setObjectName(QString::fromUtf8("formLayout_12"));
        label_40 = new QLabel(groupBox_7);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        formLayout_12->setWidget(0, QFormLayout::LabelRole, label_40);

        labelLastErrCode = new QLabel(groupBox_7);
        labelLastErrCode->setObjectName(QString::fromUtf8("labelLastErrCode"));

        formLayout_12->setWidget(0, QFormLayout::FieldRole, labelLastErrCode);

        label_59 = new QLabel(groupBox_7);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        formLayout_12->setWidget(1, QFormLayout::LabelRole, label_59);

        labelLastErrMsg = new QLabel(groupBox_7);
        labelLastErrMsg->setObjectName(QString::fromUtf8("labelLastErrMsg"));

        formLayout_12->setWidget(1, QFormLayout::FieldRole, labelLastErrMsg);


        verticalLayout_17->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(page_2);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_8);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        textSource = new QTextEdit(groupBox_8);
        textSource->setObjectName(QString::fromUtf8("textSource"));

        horizontalLayout_7->addWidget(textSource);

        pushButtonOemToChar = new QPushButton(groupBox_8);
        pushButtonOemToChar->setObjectName(QString::fromUtf8("pushButtonOemToChar"));

        horizontalLayout_7->addWidget(pushButtonOemToChar);

        textDestination = new QTextEdit(groupBox_8);
        textDestination->setObjectName(QString::fromUtf8("textDestination"));

        horizontalLayout_7->addWidget(textDestination);


        verticalLayout_17->addWidget(groupBox_8);

        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(commandLinkSystemInfo, SIGNAL(clicked()), MainWindow, SLOT(showSystemInfo()));
        QObject::connect(commandLinkMetrics, SIGNAL(clicked()), MainWindow, SLOT(showMetrics()));
        QObject::connect(commandLinkColors, SIGNAL(clicked()), MainWindow, SLOT(showColors()));
        QObject::connect(MainWindow, SIGNAL(pageChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(commandLinkSystemParams, SIGNAL(clicked()), MainWindow, SLOT(showSystemParams()));
        QObject::connect(commandLinkSystemTime, SIGNAL(clicked()), MainWindow, SLOT(showSystemTime()));
        QObject::connect(commandLinkOtherApi, SIGNAL(clicked()), MainWindow, SLOT(showOtherApi()));

        stackedWidget->setCurrentIndex(0);
        comboBoxFKFilterAvailable->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 \342\204\2261", nullptr));
        commandLinkSystemInfo->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\201\320\270\321\201\321\202\320\265\320\274\320\265", nullptr));
        commandLinkMetrics->setText(QApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\275\321\213\320\265 \320\274\320\265\321\202\321\200\320\270\320\272\320\270", nullptr));
        commandLinkSystemParams->setText(QApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\275\321\213\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        commandLinkColors->setText(QApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\275\321\213\320\265 \321\206\320\262\320\265\321\202\320\260", nullptr));
        commandLinkSystemTime->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        commandLinkOtherApi->setText(QApplication::translate("MainWindow", "\320\224\321\200\321\203\320\263\320\270\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\260", nullptr));
        labelComputerName->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        labelUserName->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \321\201\320\270\321\201\321\202\320\265\320\274\320\275\320\276\320\271 \320\277\320\260\320\277\320\272\320\265", nullptr));
        labelSystemPath->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \320\277\320\260\320\277\320\272\320\265 Windows", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \320\277\320\260\320\277\320\272\320\265 temp", nullptr));
        labelWindowsPath->setText(QString());
        labelTempPath->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\201\320\270\321\217 \320\236\320\241", nullptr));
        labelVersion->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "\320\241\320\261\320\276\321\200\320\272\320\260", nullptr));
        labelBuild->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "\320\237\320\273\320\260\321\202\321\204\320\276\321\200\320\274\320\260", nullptr));
        labelPlatform->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\276", nullptr));
        labelCSDVersion->setText(QString());
        groupGetters->setTitle(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\320\275\321\213\321\205 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \320\262\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\321\213\321\205 \320\262\320\276\320\267\320\274\320\276\320\266\320\275\320\276\321\201\321\202\320\265\320\271", nullptr));
        labelAccessTimeOutOn->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "\320\241\320\270\320\263\320\275\320\260\320\273 \320\276 \320\262\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\270/\320\262\321\213\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\270 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\321\213\321\205 \320\262\320\276\320\267\320\274\320\276\320\266\320\275\320\276\321\201\321\202\320\265\320\271", nullptr));
        labelAccessOnOffFeedback->setText(QString());
        label_18->setText(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\265\320\275\320\260 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 \321\207\321\202\320\265\320\275\320\270\321\217 \321\201 \321\215\320\272\321\200\320\260\320\275\320\260", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\320\277\320\276\321\207\321\202\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\265 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276 \320\262\320\262\320\276\320\264\320\260 - \320\272\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\320\260", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\211\320\265\320\275\320\260 \321\215\320\272\321\200\320\260\320\275\320\275\320\260\321\217 \320\267\320\260\321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\320\236\320\266\320\270\320\264\320\260\320\275\320\270\320\265 \320\277\320\265\321\200\320\265\320\264 \320\262\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265\320\274 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\321\213\321\205 \320\262\320\276\320\267\320\274\320\276\320\266\320\275\320\276\321\201\321\202\320\265\320\271", nullptr));
        labelAccessTimeOut->setText(QString());
        labelScreenReaderOn->setText(QString());
        labelKeyboardPreffered->setText(QString());
        labelScreenSaverRunning->setText(QString());
        groupFilterKeys->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\321\217 \320\272\320\273\320\260\320\262\320\270\321\210", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217 \320\264\320\276\321\201\321\202\321\203\320\277\320\275\320\260", nullptr));
        comboBoxFKFilterAvailable->setItemText(0, QApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        comboBoxFKFilterAvailable->setItemText(1, QApplication::translate("MainWindow", "\320\224\320\260", nullptr));

        label_15->setText(QApplication::translate("MainWindow", "\320\227\320\262\321\203\320\272 \320\275\320\260\320\266\320\260\321\202\320\270\321\217 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", nullptr));
        comboBoxFKClickOn->setItemText(0, QApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        comboBoxFKClickOn->setItemText(1, QApplication::translate("MainWindow", "\320\224\320\260", nullptr));

        label_10->setText(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\321\210\320\270\320\262\320\260\321\202\321\214 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 \320\263\320\276\321\200\321\217\321\207\320\265\320\271 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", nullptr));
        comboBoxFKConfirmHotkey->setItemText(0, QApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        comboBoxFKConfirmHotkey->setItemText(1, QApplication::translate("MainWindow", "\320\224\320\260", nullptr));

        label_13->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217 \320\262\320\272\320\273\321\216\321\207\320\265\320\275\320\260", nullptr));
        comboBoxFKIsOn->setItemText(0, QApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        comboBoxFKIsOn->setItemText(1, QApplication::translate("MainWindow", "\320\224\320\260", nullptr));

        label_22->setText(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270 \320\277\321\200\320\270 \321\203\320\264\320\265\321\200\320\266\320\260\320\275\320\270\320\270 Right Shift", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\263\321\200\321\213\320\262\320\260\321\202\321\214 \320\267\320\262\321\203\320\272 \320\277\321\200\320\270 \320\262\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\270/\320\276\321\202\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\270", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200 \320\260\320\272\321\202\320\270\320\262\320\275\320\276\321\201\321\202\320\270 \321\204\321\203\320\275\320\272\320\270\320\270", nullptr));
        comboBoxFKHotkeyActive->setItemText(0, QApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        comboBoxFKHotkeyActive->setItemText(1, QApplication::translate("MainWindow", "\320\224\320\260", nullptr));

        comboBoxFKHotkeySound->setItemText(0, QApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        comboBoxFKHotkeySound->setItemText(1, QApplication::translate("MainWindow", "\320\224\320\260", nullptr));

        comboBoxFKIndicator->setItemText(0, QApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        comboBoxFKIndicator->setItemText(1, QApplication::translate("MainWindow", "\320\224\320\260", nullptr));

        label_25->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\264\320\273\321\217 \321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\262\320\260\320\275\320\270\321\217 \320\275\320\260\320\266\320\260\321\202\320\270\321\217", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260 \320\277\320\276\320\262\321\202\320\276\321\200\320\265\320\275\320\270\321\217", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\203\320\267\320\260 \320\274\320\265\320\266\320\264\321\203 \320\275\320\260\320\266\320\260\321\202\320\270\321\217\320\274\320\270", nullptr));
        pushButtonSetFK->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pushButtonResetFK->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        groupMinimizedMetrics->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\274\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \321\200\320\260\320\267\320\274\320\265\321\200\320\260 \320\276\320\272\320\276\320\275", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\210\320\270\321\200\320\270\320\275\320\260", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\223\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\213\320\271 \320\277\321\200\320\276\320\274\320\265\320\266\321\203\321\202\320\276\320\272", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\202\320\270\320\260\320\273\321\214\320\275\321\213\320\271 \320\277\321\200\320\276\320\274\320\265\320\266\321\203\321\202\320\276\320\272", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\321\217 \320\264\320\273\321\217 \321\203\320\277\320\276\321\200\321\217\320\264\320\276\321\207\320\270\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\203\320\277\320\276\321\200\321\217\320\264\320\276\321\207\320\270\320\262\320\260\320\275\320\270\321\217", nullptr));
        comboBoxMMStart->setItemText(0, QApplication::translate("MainWindow", "\320\241\320\275\320\270\320\267\321\203 \321\201\320\273\320\265\320\262\320\260", nullptr));
        comboBoxMMStart->setItemText(1, QApplication::translate("MainWindow", "\320\241\320\275\320\270\320\267\321\203 \321\201\320\277\321\200\320\260\320\262\320\260", nullptr));
        comboBoxMMStart->setItemText(2, QApplication::translate("MainWindow", "\320\241\320\262\320\265\321\200\321\205\321\203 \321\201\320\273\320\265\320\262\320\260", nullptr));
        comboBoxMMStart->setItemText(3, QApplication::translate("MainWindow", "\320\241\320\262\320\265\321\200\321\205\321\203 \321\201\320\277\321\200\320\260\320\262\320\260", nullptr));

        comboBoxMMDirection->setItemText(0, QApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
        comboBoxMMDirection->setItemText(1, QApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
        comboBoxMMDirection->setItemText(2, QApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
        comboBoxMMDirection->setItemText(3, QApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
        comboBoxMMDirection->setItemText(4, QApplication::translate("MainWindow", "\320\241\320\272\321\200\321\213\321\202\321\214", nullptr));

        pushButtonSetMM->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pushButtonResetMM->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        pushButtonChooseACTIVECAPTION->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        pushButtonSetACTIVECAPTION->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pushButtonResetACTIVECAPTION->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        pushButtonChoose3DDKSHADOW->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        pushButtonSet3DDKSHADOW->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pushButtonReset3DDKSHADOW->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        label3DDKSHADOW_old->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\213\320\271 \321\206\320\262\320\265\321\202 3DDKSHADOW", nullptr));
        labelBTNTEXT_old->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\213\320\271 \321\206\320\262\320\265\321\202 BTNTEXT", nullptr));
        labelACTIVECAPTION_new->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\206\320\262\320\265\321\202 ACTIVECAPTION", nullptr));
        labelACTIVECAPTION_old->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\213\320\271 \321\206\320\262\320\265\321\202 ACTIVECAPTION", nullptr));
        label3DDKSHADOW_new->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\206\320\262\320\265\321\202 3DDKSHADOW", nullptr));
        pushButtonChooseBTNTEXT->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        pushButtonSetBTNTEXT->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pushButtonResetBTNTEXT->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        labelBTNTEXT_new->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\206\320\262\320\265\321\202 BTNTEXT", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 (\320\262 UTC)", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\262\321\200\320\265\320\274\321\217:", nullptr));
        labelHour->setText(QString());
        label_33->setText(QApplication::translate("MainWindow", ":", nullptr));
        labelMinute->setText(QString());
        label_37->setText(QApplication::translate("MainWindow", ":", nullptr));
        labelSecond->setText(QString());
        label_35->setText(QApplication::translate("MainWindow", ":", nullptr));
        labelMilliseconds->setText(QString());
        label_32->setText(QApplication::translate("MainWindow", "\320\223\320\276\320\264", nullptr));
        labelYear->setText(QString());
        label_34->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        labelMonth->setText(QString());
        label_36->setText(QApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276", nullptr));
        labelDay->setText(QString());
        label_38->setText(QApplication::translate("MainWindow", "\320\224\320\265\320\275\321\214 \320\275\320\265\320\264\320\265\320\273\320\270", nullptr));
        labelDayOfWeek->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\233\320\276\320\272\320\260\320\273\321\214\320\275\320\276\320\265 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_52->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\262\321\200\320\265\320\274\321\217:", nullptr));
        labelLocalHour->setText(QString());
        label_47->setText(QApplication::translate("MainWindow", ":", nullptr));
        labelLocalMinute->setText(QString());
        label_48->setText(QApplication::translate("MainWindow", ":", nullptr));
        labelLocalSecond->setText(QString());
        label_49->setText(QApplication::translate("MainWindow", ":", nullptr));
        labelLocalMilliseconds->setText(QString());
        labelLocalYear->setText(QString());
        labelLocalMonth->setText(QString());
        labelLocalDay->setText(QString());
        label_50->setText(QApplication::translate("MainWindow", "\320\224\320\265\320\275\321\214 \320\275\320\265\320\264\320\265\320\273\320\270", nullptr));
        labelLocalDayOfWeek->setText(QString());
        label_55->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\276 UTC (\320\262 \320\274\320\270\320\275\321\203\321\202\320\260\321\205):", nullptr));
        labelBias->setText(QString());
        label_53->setText(QApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276", nullptr));
        label_54->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        label_51->setText(QApplication::translate("MainWindow", "\320\223\320\276\320\264", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\321\205\320\276\320\264 \320\275\320\260 \320\273\320\265\321\202\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217", nullptr));
        labelDaylightActive->setText(QString());
        groupStandard->setTitle(QString());
        label_46->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\277\320\265\321\200\320\265\320\262\320\276\320\264\320\260 \320\275\320\260 \320\267\320\270\320\274\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_58->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        labelTransitionStandardMonth->setText(QString());
        label_60->setText(QApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276", nullptr));
        labelTransitionStandardDay->setText(QString());
        groupDaylight->setTitle(QString());
        label_39->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\277\320\265\321\200\320\265\320\262\320\276\320\264\320\260 \320\275\320\260 \320\273\320\265\321\202\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_42->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        labelTransitionDalyightMonth->setText(QString());
        label_44->setText(QApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276", nullptr));
        labelTransitionDalyightDay->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\265\320\275\320\264\320\260\321\200\321\214", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\200\320\276\321\202\320\272\320\270\320\271 \321\204\320\276\321\200\320\274\320\260\321\202 \320\264\320\260\321\202\321\213", nullptr));
        label_43->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\275\321\213\320\271 \321\204\320\276\321\200\320\274\320\260\321\202 \320\264\320\260\321\202\321\213", nullptr));
        label_45->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\264\320\275\321\217 \320\275\320\265\320\264\320\265\320\273\320\270", nullptr));
        label_57->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\272\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\264\320\275\321\217 \320\275\320\265\320\264\320\265\320\273\320\270", nullptr));
        labelCalFormatShort->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelCalFormatLong->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelCalDayLong->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelCalDayShort->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_64->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\265\321\201\321\217\321\206\320\260", nullptr));
        label_65->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\272\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\274\320\265\321\201\321\217\321\206\320\260", nullptr));
        labelCalMonthLong->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelCalMonthShort->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\240\320\260\321\201\320\272\320\273\320\260\320\264\320\272\320\260 \320\272\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\321\213", nullptr));
        pushButtonPrev->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\260\321\217", nullptr));
        pushButtonNext->setText(QApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\260\321\217", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\262\320\260\320\273\321\216\321\202\321\213", nullptr));
        labelCurrencyOut->setText(QString());
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\273\320\265\320\264\320\275\321\217\321\217 \320\276\321\210\320\270\320\261\320\272\320\260", nullptr));
        label_40->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\264 \320\276\321\210\320\270\320\261\320\272\320\270", nullptr));
        labelLastErrCode->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_59->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \320\276\320\261 \320\276\321\210\320\270\320\261\320\272\320\265", nullptr));
        labelLastErrMsg->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\262\320\276\320\264 \320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\276\320\272", nullptr));
        pushButtonOemToChar->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
