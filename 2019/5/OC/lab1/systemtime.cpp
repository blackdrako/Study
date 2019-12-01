#include "systemtime.h"

#include <QDebug>
#include <QApplication>

// Соотвтетствия между днями недели и номерами месяцев
// и их названиями
const QMap<WORD, QString> DayOfWeekConsts = {
    {0, "Воскресенье"},
    {1, "Понедельник"},
    {2, "Вторник"},
    {3, "Среда"},
    {4, "Четверг"},
    {5, "Пятница"},
    {6, "Суббота"}
};

const QMap<WORD, QString> MonthConsts = {
    {1, "Январь"},
    {2, "Февраль"},
    {3, "Март"},
    {4, "Апрель"},
    {5, "Май"},
    {6, "Июнь"},
    {7, "Июль"},
    {8, "Август"},
    {9, "Сентябрь"},
    {10, "Октябрь"},
    {11, "Ноябрь"},
    {12, "Декабрь"}
};

SystemTime::SystemTime(){
    lpSystemTime = new SYSTEMTIME;
}

// Обновление текущего времени
void SystemTime::updateTime(){
    GetSystemTime(lpSystemTime);
    // Функция отдает измененные данные о времени в соответствующие поля
    emit signalSetYear(QString::number(lpSystemTime->wYear));
    emit signalSetDayOfWeek(DayOfWeekConsts.value(lpSystemTime->wDayOfWeek));
    emit signalSetMonth(MonthConsts.value(lpSystemTime->wMonth));
    emit signalSetDay(QString::number(lpSystemTime->wDay));
    emit signalSetHour(QString::number(lpSystemTime->wHour));
    emit signalSetMinute(QString::number(lpSystemTime->wMinute));
    emit signalSetSecond(QString::number(lpSystemTime->wSecond));
    emit signalSetMilliseconds(QString::number(lpSystemTime->wMilliseconds));
}

// Обновление часового пояса
void SystemTime::updateTimeZone(){
    LPTIME_ZONE_INFORMATION timeZoneInformation = new TIME_ZONE_INFORMATION;
    // currentBias будет хранить константу, в которой записано, какое из смещений используется
    DWORD currentBias = GetTimeZoneInformation(timeZoneInformation);
    // Bias хранит смещение, по которому вычисляется текущее время
    LONG Bias;
    switch(currentBias){
        case TIME_ZONE_ID_UNKNOWN:
            emit signalDayLightStatus("Перевод времени не используется");
            Bias = timeZoneInformation->Bias;
            // Скрыть информацию о переводе времени
            emit signalHideTransitions();
            break;
        case TIME_ZONE_ID_STANDARD:
            emit signalDayLightStatus("Зимнее время");
            Bias = timeZoneInformation->StandardBias;
            // Показать информацию о переводе времени
            emit signalShowTransitions();
            break;
        case TIME_ZONE_ID_DAYLIGHT:
            emit signalDayLightStatus("Летнее время");
            Bias = timeZoneInformation->DaylightBias;
            // Показать информацию о переводе времени
            emit signalShowTransitions();
            break;
    }
    // Если перевод времени используется, то установить даты перевода часов
    if (currentBias != TIME_ZONE_ID_UNKNOWN){
        emit signalSetTransitionStandardMonth(MonthConsts.value(timeZoneInformation->StandardDate.wMonth));
        emit signalSetTransitionStandardDay(QString::number(timeZoneInformation->StandardDate.wDay));
        emit signalSetTransitionDaylightMonth(MonthConsts.value(timeZoneInformation->DaylightDate.wMonth));
        emit signalSetTransitionDaylightDay(QString::number(timeZoneInformation->DaylightDate.wDay));
    }
    // Формула UTC + Bias = Local
    Bias = -Bias;
    // Вычислим локальное время
    SYSTEMTIME stLocalTime = *lpSystemTime;
    stLocalTime.wMinute += Bias % 60;
    stLocalTime.wHour += stLocalTime.wMinute / 60;
    stLocalTime.wMinute %= 60;
    stLocalTime.wHour += Bias / 60;
    stLocalTime.wDay += stLocalTime.wHour / 24;
    stLocalTime.wHour %= 24;
    stLocalTime.wDay += Bias / (60*24);
    // Установим новое время
    emit signalSetLocalMilliseconds(QString::number(stLocalTime.wMilliseconds));
    emit signalSetLocalSecond(QString::number(stLocalTime.wSecond));
    emit signalSetLocalMinute(QString::number(stLocalTime.wMinute));
    emit signalSetLocalHour(QString::number(stLocalTime.wHour));
    emit signalSetLocalDay(QString::number(stLocalTime.wDay));
    emit signalSetLocalMonth(MonthConsts.value(stLocalTime.wMonth));
    emit signalSetLocalDayOfWeek(DayOfWeekConsts.value(stLocalTime.wDayOfWeek));
    emit signalSetLocalYear(QString::number(stLocalTime.wYear));
    delete timeZoneInformation;
}

// В эту переменную будет записано то, что передано callback-функция
static QString temp_for_callback;

// callback-функция будет вызываться для обработки значения внутри
// API-функции EnumCalendarInfo. Поскольку нам достаточно получить только
// первое значение, функция возвращает FALSE (закончить перечисление)
BOOL CALLBACK EnumCalCallBack(LPTSTR lptStr){
    temp_for_callback = QString::fromWCharArray(lptStr);
    return FALSE;
}

// Получить информацию из системного календаря
void SystemTime::updateCalendarInfo(){
    // Длинный формат дат
    EnumCalendarInfoW(EnumCalCallBack, LOCALE_USER_DEFAULT, ENUM_ALL_CALENDARS, CAL_SLONGDATE);
    emit signalSetCalFormatLong(temp_for_callback);
    // Короткий формат дат
    EnumCalendarInfoW(EnumCalCallBack, LOCALE_USER_DEFAULT, ENUM_ALL_CALENDARS, CAL_SSHORTDATE);
    emit signalSetCalFormatShort(temp_for_callback);
    // Длинное название первого месяца
    EnumCalendarInfoW(EnumCalCallBack, LOCALE_USER_DEFAULT, ENUM_ALL_CALENDARS, CAL_SMONTHNAME1);
    emit signalSetCalMonthLong(temp_for_callback);
    // Короткое название первого месяца
    EnumCalendarInfoW(EnumCalCallBack, LOCALE_USER_DEFAULT, ENUM_ALL_CALENDARS, CAL_SABBREVMONTHNAME1);
    emit signalSetCalMonthShort(temp_for_callback);
    // Длинное название первого дня недели
    EnumCalendarInfoW(EnumCalCallBack, LOCALE_USER_DEFAULT, ENUM_ALL_CALENDARS, CAL_SDAYNAME1);
    emit signalSetCalDayLong(temp_for_callback);
    // Короткое название первого дня недели
    EnumCalendarInfoW(EnumCalCallBack, LOCALE_USER_DEFAULT, ENUM_ALL_CALENDARS, CAL_SABBREVDAYNAME1);
    emit signalSetCalDayShort(temp_for_callback);
}
