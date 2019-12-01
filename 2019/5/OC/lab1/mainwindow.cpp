#include "mainwindow.h"
#include "ui_mainwindow.h"

// Номера страниц, на которых находятся настройки
#define INDEX_SYSTEM_INFO   0
#define INDEX_METRICS       1
#define INDEX_SYSTEM_PARAMS 2
#define INDEX_COLORS        3
#define INDEX_SYSTEM_TIME   4
#define INDEX_OTHER_API     5

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi((QMainWindow *)this);
    fillSystemInfo();
    fillTableMetrics();
    time = new SystemTime();
    api = new OtherAPI();
    sp = new SystemParams();
    color_3DDKSHADOW = new Colors(COLOR_3DDKSHADOW);
    color_ACTIVECAPTION = new Colors(COLOR_ACTIVECAPTION);
    color_BTNTEXT = new Colors(COLOR_BTNTEXT);
    QTimer *timer = new QTimer(this);

    QObject::connect(timer, &QTimer::timeout, time, &SystemTime::updateTime);
    QObject::connect(timer, &QTimer::timeout, time, &SystemTime::updateTimeZone);

    // Сигнал -> слот
    // Системные параметры, сигналы устанавливают значение в полях
    QObject::connect(sp, &SystemParams::signalSetFKIsOn,                  ui->comboBoxFKIsOn,             &QComboBox::setCurrentIndex);
    QObject::connect(sp, &SystemParams::signalSetFKClickOn,               ui->comboBoxFKClickOn,          &QComboBox::setCurrentIndex);
    QObject::connect(sp, &SystemParams::signalSetFKIndicator,             ui->comboBoxFKIndicator,        &QComboBox::setCurrentIndex);
    QObject::connect(sp, &SystemParams::signalSetFKHotkeySound,           ui->comboBoxFKHotkeySound,      &QComboBox::setCurrentIndex);
    QObject::connect(sp, &SystemParams::signalSetFKHotkeyActive,          ui->comboBoxFKHotkeyActive,     &QComboBox::setCurrentIndex);
    QObject::connect(sp, &SystemParams::signalSetFKConfirmHotkey,         ui->comboBoxFKConfirmHotkey,    &QComboBox::setCurrentIndex);
    QObject::connect(sp, &SystemParams::signalSetFKFilterAvailable,       ui->comboBoxFKFilterAvailable,  &QComboBox::setCurrentIndex);
    QObject::connect(sp, &SystemParams::signalSetMMStart,                 ui->comboBoxMMStart,            &QComboBox::setCurrentIndex);
    QObject::connect(sp, &SystemParams::signalSetMMDirection,             ui->comboBoxMMDirection,        &QComboBox::setCurrentIndex);
    QObject::connect(sp, &SystemParams::signalSetFKWait,                  ui->spinBoxFKWait,              &QSpinBox::setValue);
    QObject::connect(sp, &SystemParams::signalSetFKBounce,                ui->spinBoxFKBounce,            &QSpinBox::setValue);
    QObject::connect(sp, &SystemParams::signalSetFKRepeat,                ui->spinBoxFKRepeat,            &QSpinBox::setValue);
    QObject::connect(sp, &SystemParams::signalSetFKWait,                  ui->spinBoxFKWait,              &QSpinBox::setValue);
    QObject::connect(sp, &SystemParams::signalSetMMWidth,                 ui->spinBoxMMWidth,             &QSpinBox::setValue);
    QObject::connect(sp, &SystemParams::signalSetMMVerticalGap,           ui->spinBoxMMVerticalGap,       &QSpinBox::setValue);
    QObject::connect(sp, &SystemParams::signalSetMMHorizontalGap,         ui->spinBoxMMHorizontalGap,     &QSpinBox::setValue);
    QObject::connect(sp, &SystemParams::signalSetAccessTimeOutOn,         ui->labelAccessTimeOutOn,       &QLabel::setText);
    QObject::connect(sp, &SystemParams::signalSetAccessTimeout,           ui->labelAccessTimeOut,         &QLabel::setText);
    QObject::connect(sp, &SystemParams::signalSetAccessOnOffFeedback,     ui->labelAccessOnOffFeedback,   &QLabel::setText);
    QObject::connect(sp, &SystemParams::signalSetScreenReaderOn,          ui->labelScreenReaderOn,        &QLabel::setText);
    QObject::connect(sp, &SystemParams::signalSetKeyboardPrefferred,      ui->labelKeyboardPreffered,     &QLabel::setText);
    QObject::connect(sp, &SystemParams::signalSetScreenSaverRunning,      ui->labelScreenSaverRunning,    &QLabel::setText);

    // Системные параметры, из полей получаем новые значения
    QObject::connect(ui->comboBoxFKIsOn,            QOverload<int>::of(&QComboBox::currentIndexChanged), sp, &SystemParams::setFKIsOn);
    QObject::connect(ui->comboBoxFKClickOn,         QOverload<int>::of(&QComboBox::currentIndexChanged), sp, &SystemParams::setFKClickOn);
    QObject::connect(ui->comboBoxFKIndicator,       QOverload<int>::of(&QComboBox::currentIndexChanged), sp, &SystemParams::setFKIndicator);
    QObject::connect(ui->comboBoxFKHotkeySound,     QOverload<int>::of(&QComboBox::currentIndexChanged), sp, &SystemParams::setFKHotkeySound);
    QObject::connect(ui->comboBoxFKHotkeyActive,    QOverload<int>::of(&QComboBox::currentIndexChanged), sp, &SystemParams::setFKHotkeyActive);
    QObject::connect(ui->comboBoxFKConfirmHotkey,   QOverload<int>::of(&QComboBox::currentIndexChanged), sp, &SystemParams::setFKConfirmHotkey);
    QObject::connect(ui->comboBoxFKFilterAvailable, QOverload<int>::of(&QComboBox::currentIndexChanged), sp, &SystemParams::setFKFilterAvailable);
    QObject::connect(ui->comboBoxMMStart,           QOverload<int>::of(&QComboBox::currentIndexChanged), sp, QOverload<int>::of(&SystemParams::setMMStart));
    QObject::connect(ui->comboBoxMMDirection,       QOverload<int>::of(&QComboBox::currentIndexChanged), sp, QOverload<int>::of(&SystemParams::setMMDirection));
    QObject::connect(ui->spinBoxFKWait,             QOverload<int>::of(&QSpinBox::valueChanged), sp, &SystemParams::setFKWait);
    QObject::connect(ui->spinBoxFKBounce,           QOverload<int>::of(&QSpinBox::valueChanged), sp, &SystemParams::setFKBounce);
    QObject::connect(ui->spinBoxFKRepeat,           QOverload<int>::of(&QSpinBox::valueChanged), sp, &SystemParams::setFKRepeat);
    QObject::connect(ui->spinBoxFKWait,             QOverload<int>::of(&QSpinBox::valueChanged), sp, &SystemParams::setFKWait);
    QObject::connect(ui->spinBoxMMWidth,            QOverload<int>::of(&QSpinBox::valueChanged), sp, &SystemParams::setMMWidth);
    QObject::connect(ui->spinBoxMMVerticalGap,      QOverload<int>::of(&QSpinBox::valueChanged), sp, &SystemParams::setMMVerticalGap);
    QObject::connect(ui->spinBoxMMHorizontalGap,    QOverload<int>::of(&QSpinBox::valueChanged), sp, &SystemParams::setMMHorizontalGap);
    QObject::connect(ui->pushButtonSetFK,           &QPushButton::clicked, sp, &SystemParams::setFK);
    QObject::connect(ui->pushButtonResetFK,         &QPushButton::clicked, sp, &SystemParams::resetFK);
    QObject::connect(ui->pushButtonSetMM,           &QPushButton::clicked, sp, &SystemParams::setMM);
    QObject::connect(ui->pushButtonResetMM,         &QPushButton::clicked, sp, &SystemParams::resetMM);

    // Цвета, при изменении цвета изменится цвет label'а
    QObject::connect(color_3DDKSHADOW,      &Colors::colorChanged, this, &MainWindow::updateColor3DDKSHADOW_old);
    QObject::connect(color_BTNTEXT,         &Colors::colorChanged, this, &MainWindow::updateColorBTNTEXT_old);
    QObject::connect(color_ACTIVECAPTION,   &Colors::colorChanged, this, &MainWindow::updateColorACTIVECAPTION_old);

    // Получим старые цвета
    color_BTNTEXT->updateColor();
    color_3DDKSHADOW->updateColor();
    color_ACTIVECAPTION->updateColor();

    // Теперь отсоединим от старых, и будем работать только с новыми
    QObject::disconnect(color_3DDKSHADOW,   &Colors::colorChanged, this, &MainWindow::updateColor3DDKSHADOW_old);
    QObject::disconnect(color_BTNTEXT,      &Colors::colorChanged, this, &MainWindow::updateColorBTNTEXT_old);
    QObject::disconnect(color_ACTIVECAPTION,&Colors::colorChanged, this, &MainWindow::updateColorACTIVECAPTION_old);

    QObject::connect(color_3DDKSHADOW,      &Colors::colorChanged, this, &MainWindow::updateColor3DDKSHADOW);
    QObject::connect(color_BTNTEXT,         &Colors::colorChanged, this, &MainWindow::updateColorBTNTEXT);
    QObject::connect(color_ACTIVECAPTION,   &Colors::colorChanged, this, &MainWindow::updateColorACTIVECAPTION);

    color_BTNTEXT->updateColor();
    color_3DDKSHADOW->updateColor();
    color_ACTIVECAPTION->updateColor();

    // Установка, сброс, выбор цвета по кнопке
    QObject::connect(ui->pushButtonSetBTNTEXT,          &QPushButton::clicked, this, &MainWindow::buttonSetColorBTNTEXT);
    QObject::connect(ui->pushButtonSetACTIVECAPTION,    &QPushButton::clicked, this, &MainWindow::buttonSetColorACTIVECAPTION);
    QObject::connect(ui->pushButtonSet3DDKSHADOW,       &QPushButton::clicked, this, &MainWindow::buttonSetColor3DDKSHADOW);
    QObject::connect(ui->pushButtonResetBTNTEXT,        &QPushButton::clicked, this, &MainWindow::buttonResetColorBTNTEXT);
    QObject::connect(ui->pushButtonResetACTIVECAPTION,  &QPushButton::clicked, this, &MainWindow::buttonResetColorACTIVECAPTION);
    QObject::connect(ui->pushButtonReset3DDKSHADOW,     &QPushButton::clicked, this, &MainWindow::buttonResetColor3DDKSHADOW);
    QObject::connect(ui->pushButtonChooseBTNTEXT,       &QPushButton::clicked, this, &MainWindow::buttonChooseColorBTNTEXT);
    QObject::connect(ui->pushButtonChooseACTIVECAPTION, &QPushButton::clicked, this, &MainWindow::buttonChooseColorACTIVECAPTION);
    QObject::connect(ui->pushButtonChoose3DDKSHADOW,    &QPushButton::clicked, this, &MainWindow::buttonChooseColor3DDKSHADOW);
    // При закрытии окна восстановим старые цвета
    QObject::connect(this, &QMainWindow::destroyed, this, &MainWindow::buttonResetColorBTNTEXT);
    QObject::connect(this, &QMainWindow::destroyed, this, &MainWindow::buttonResetColorACTIVECAPTION);
    QObject::connect(this, &QMainWindow::destroyed, this, &MainWindow::buttonResetColor3DDKSHADOW);
    // Получение времени
    QObject::connect(time, &SystemTime::signalSetYear,          ui->labelYear, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetMonth,         ui->labelMonth, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetDay,           ui->labelDay, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetDayOfWeek,     ui->labelDayOfWeek, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetHour,          ui->labelHour, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetMinute,        ui->labelMinute, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetSecond,        ui->labelSecond, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetMilliseconds,  ui->labelMilliseconds, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetLocalYear,     ui->labelLocalYear, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetLocalMonth,    ui->labelLocalMonth, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetLocalDay,      ui->labelLocalDay, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetLocalDayOfWeek, ui->labelLocalDayOfWeek, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetLocalHour,     ui->labelLocalHour, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetLocalMinute,   ui->labelLocalMinute, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetLocalSecond,   ui->labelLocalSecond, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetLocalMilliseconds, ui->labelLocalMilliseconds, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalDayLightStatus,   ui->labelDaylightActive, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalHideTransitions,  ui->groupStandard, &QLabel::hide);
    QObject::connect(time, &SystemTime::signalHideTransitions,  ui->groupDaylight, &QLabel::hide);
    QObject::connect(time, &SystemTime::signalShowTransitions,  ui->groupStandard, &QLabel::show);
    QObject::connect(time, &SystemTime::signalShowTransitions,  ui->groupDaylight, &QLabel::show);
    QObject::connect(time, &SystemTime::signalSetTransitionDaylightMonth,   ui->labelTransitionDalyightMonth, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetTransitionDaylightDay,     ui->labelTransitionDalyightDay, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetTransitionStandardMonth,   ui->labelTransitionStandardMonth, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetTransitionStandardDay,     ui->labelTransitionStandardDay, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetCalDayLong,    ui->labelCalDayLong, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetCalDayShort,   ui->labelCalDayShort, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetCalMonthLong,  ui->labelCalMonthLong, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetCalMonthShort, ui->labelCalMonthShort, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetCalFormatLong, ui->labelCalFormatLong, &QLabel::setText);
    QObject::connect(time, &SystemTime::signalSetCalFormatShort, ui->labelCalFormatShort, &QLabel::setText);
    // Другие API - последняя ошибка, валюта, кодировка, раскладка
    QObject::connect(api, &OtherAPI::signalSetLastErrCode,  ui->labelLastErrCode, &QLabel::setText);
    QObject::connect(api, &OtherAPI::signalSetLastErrMsg,   ui->labelLastErrMsg, &QLabel::setText);
    QObject::connect(api, &OtherAPI::signalSetCurrency,     ui->labelCurrencyOut, &QLabel::setText);
    QObject::connect(ui->spinBoxCurrencyIn, QOverload<int>::of(&QSpinBox::valueChanged), api, &OtherAPI::updateCurrency);
    QObject::connect(ui->pushButtonNext,        &QPushButton::clicked, api,     &OtherAPI::switchKBNext);
    QObject::connect(ui->pushButtonPrev,        &QPushButton::clicked, api,     &OtherAPI::switchKBPrev);
    QObject::connect(ui->pushButtonOemToChar,   &QPushButton::clicked, this,    &MainWindow::oemToChar);
    QObject::connect(this,  &MainWindow::signalOemToChar,   api,                    &OtherAPI::oemToCharIn);
    QObject::connect(api,   &OtherAPI::oemToCharOut,        ui->textDestination,    &QTextEdit::setText);

    sp->updateData();
    time->updateCalendarInfo();
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Показать страницы с информацией
void MainWindow::showSystemInfo(){
    emit pageChanged(INDEX_SYSTEM_INFO);
}

void MainWindow::showMetrics(){
    updateMetrics();
    emit pageChanged(INDEX_METRICS);
}

void MainWindow::showSystemParams(){
    emit pageChanged(INDEX_SYSTEM_PARAMS);
}

void MainWindow::showColors(){
    emit pageChanged(INDEX_COLORS);
}

void MainWindow::showSystemTime(){
    emit pageChanged(INDEX_SYSTEM_TIME);
}

void MainWindow::showOtherApi(){
    updateOtherApi();
    emit pageChanged(INDEX_OTHER_API);
}

// Обновить данные
void MainWindow::updateOtherApi(){
    api->updateError();
}

void MainWindow::updateMetrics(){
    fillTableMetrics();
}

// Получение цвета, который будет видно на фоне цвета original
QColor complementColor(QColor original){
    if (original.hslSaturation() > 90){
        return QColor(0, 0, 0);
    }else{
        return QColor(255, 255, 255);
    }
}

// Установка/сброс цветов
void MainWindow::updateColor3DDKSHADOW(QColor color){
    QPalette palette = QGuiApplication::palette();
    palette.setColor(QPalette::Background, color);
    palette.setColor(QPalette::Foreground, complementColor(color));
    ui->label3DDKSHADOW_new->setAutoFillBackground(true);
    ui->label3DDKSHADOW_new->setPalette(palette);
}

void MainWindow::updateColorACTIVECAPTION(QColor color){
    QPalette palette = QGuiApplication::palette();
    palette.setColor(QPalette::Background, color);
    palette.setColor(QPalette::Foreground, complementColor(color));
    ui->labelACTIVECAPTION_new->setAutoFillBackground(true);
    ui->labelACTIVECAPTION_new->setPalette(palette);
}

void MainWindow::updateColorBTNTEXT(QColor color){
    QPalette palette = QGuiApplication::palette();
    palette.setColor(QPalette::Background, color);
    palette.setColor(QPalette::Foreground, complementColor(color));
    ui->labelBTNTEXT_new->setAutoFillBackground(true);
    ui->labelBTNTEXT_new->setPalette(palette);
}

void MainWindow::updateColor3DDKSHADOW_old(QColor color){
    QPalette palette = QGuiApplication::palette();
    palette.setColor(QPalette::Background, color);
    palette.setColor(QPalette::Foreground, complementColor(color));
    ui->label3DDKSHADOW_old->setAutoFillBackground(true);
    ui->label3DDKSHADOW_old->setPalette(palette);
}

void MainWindow::updateColorACTIVECAPTION_old(QColor color){
    QPalette palette = QGuiApplication::palette();
    palette.setColor(QPalette::Background, color);
    palette.setColor(QPalette::Foreground, complementColor(color));
    ui->labelACTIVECAPTION_old->setAutoFillBackground(true);
    ui->labelACTIVECAPTION_old->setPalette(palette);
}

void MainWindow::updateColorBTNTEXT_old(QColor color){
    QPalette palette = QGuiApplication::palette();
    palette.setColor(QPalette::Background, color);
    palette.setColor(QPalette::Foreground, complementColor(color));
    ui->labelBTNTEXT_old->setAutoFillBackground(true);
    ui->labelBTNTEXT_old->setPalette(palette);
}

void MainWindow::buttonChooseColor3DDKSHADOW(){
    color_3DDKSHADOW->setNewColor(QColorDialog().getColor());
    color_3DDKSHADOW->colorChanged(color_3DDKSHADOW->getNewColor());
}

void MainWindow::buttonChooseColorACTIVECAPTION(){
    color_ACTIVECAPTION->setNewColor(QColorDialog().getColor());
    color_ACTIVECAPTION->colorChanged(color_ACTIVECAPTION->getNewColor());
}

void MainWindow::buttonChooseColorBTNTEXT(){
    color_BTNTEXT->setNewColor(QColorDialog().getColor());
    color_BTNTEXT->colorChanged(color_BTNTEXT->getNewColor());
}

void MainWindow::buttonSetColor3DDKSHADOW(){
    color_3DDKSHADOW->changeColor(color_3DDKSHADOW->getNewColor());
}

void MainWindow::buttonSetColorACTIVECAPTION(){
    color_ACTIVECAPTION->changeColor(color_ACTIVECAPTION->getNewColor());
}

void MainWindow::buttonSetColorBTNTEXT(){
    color_BTNTEXT->changeColor(color_BTNTEXT->getNewColor());
}

void MainWindow::buttonResetColor3DDKSHADOW(){
    color_3DDKSHADOW->setNewColor(color_3DDKSHADOW->getSavedColor());
    color_3DDKSHADOW->changeColor(color_3DDKSHADOW->getNewColor());
}

void MainWindow::buttonResetColorACTIVECAPTION(){
    color_ACTIVECAPTION->setNewColor(color_ACTIVECAPTION->getSavedColor());
    color_ACTIVECAPTION->changeColor(color_ACTIVECAPTION->getNewColor());
}

void MainWindow::buttonResetColorBTNTEXT(){
    color_BTNTEXT->setNewColor(color_BTNTEXT->getSavedColor());
    color_BTNTEXT->changeColor(color_BTNTEXT->getNewColor());
}

// Сигнал к преобразованию кодировок
void MainWindow::oemToChar(){
    emit signalOemToChar(ui->textSource->toPlainText());
}

// Получение метрик
void MainWindow::fillTableMetrics(){
    // Настроим таблицу: 4 столбца, количество строк = количество метрик
    ui->tableMetrics->setColumnCount(4);
    ui->tableMetrics->setRowCount(Metrics::getPossibleMetrics().size());
    // Заполним шапку и установим правила изменения размеров
    ui->tableMetrics->setHorizontalHeaderLabels({"Метрика", "Значение", "Единицы измерения", "Пояснение"});
    ui->tableMetrics->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableMetrics->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableMetrics->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableMetrics->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableMetrics->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    // В каждую строку добавим по одной метрике: имя, значение, единицы измерения, описание
    int last_row = 0;
    for (int metric : Metrics::getPossibleMetrics()) {
        ui->tableMetrics->setItem(last_row, 0, new QTableWidgetItem(
                                      Metrics::getName(metric)
                                      ));
        ui->tableMetrics->setItem(last_row, 1, new QTableWidgetItem(
                                      Metrics::getValue(metric)
                                      ));
        ui->tableMetrics->setItem(last_row, 2, new QTableWidgetItem(
                                      Metrics::getUnit(metric)
                                      ));
        ui->tableMetrics->setItem(last_row, 3, new QTableWidgetItem(
                                      Metrics::getDescription(metric)
                                      ));
        last_row++;
    }
}

// Получение системной информации
void MainWindow::fillSystemInfo()
{
    ui->labelUserName->     setText(SystemInfo::instance().getUserName());
    ui->labelComputerName-> setText(SystemInfo::instance().getComputerName());
    ui->labelSystemPath->   setText(SystemInfo::instance().getSystemPath());
    ui->labelWindowsPath->  setText(SystemInfo::instance().getWindowsPath());
    ui->labelTempPath->     setText(SystemInfo::instance().getTempPath());
    ui->labelBuild->        setText(SystemInfo::instance().getBuild());
    ui->labelVersion->      setText(SystemInfo::instance().getVersion());
    ui->labelPlatform->     setText(SystemInfo::instance().getPlatform());
    ui->labelCSDVersion->   setText(SystemInfo::instance().getCSDVersion());
}
