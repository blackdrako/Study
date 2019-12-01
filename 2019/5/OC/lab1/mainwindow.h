#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QTimer>
#include <windows.h>

#include "systeminfo.h"
#include "metrics.h"
#include "systemparams.h"
#include "colors.h"
#include "systemtime.h"
#include "otherapi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void pageChanged(int page);
    void signalOemToChar(QString value);

private slots:
    void showSystemInfo();
    void showMetrics();
    void showColors();
    void showSystemParams();
    void showSystemTime();
    void showOtherApi();
    void updateOtherApi();
    void updateMetrics();
    void updateColor3DDKSHADOW(QColor color);
    void updateColorACTIVECAPTION(QColor color);
    void updateColorBTNTEXT(QColor color);
    void updateColor3DDKSHADOW_old(QColor color);
    void updateColorACTIVECAPTION_old(QColor color);
    void updateColorBTNTEXT_old(QColor color);
    void buttonSetColor3DDKSHADOW();
    void buttonSetColorACTIVECAPTION();
    void buttonSetColorBTNTEXT();
    void buttonResetColor3DDKSHADOW();
    void buttonResetColorACTIVECAPTION();
    void buttonResetColorBTNTEXT();
    void buttonChooseColor3DDKSHADOW();
    void buttonChooseColorACTIVECAPTION();
    void buttonChooseColorBTNTEXT();
    void oemToChar();

private:
    Ui::MainWindow *ui;
    SystemParams *sp;
    Colors *color_3DDKSHADOW;
    Colors *color_ACTIVECAPTION;
    Colors *color_BTNTEXT;
    SystemTime *time;
    OtherAPI *api;
    void fillTableMetrics();
    void fillSystemInfo();
    void fillSystemParams();
};
#endif // MAINWINDOW_H
