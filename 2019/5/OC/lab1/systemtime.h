#ifndef SYSTEMTIME_H
#define SYSTEMTIME_H

/*
 * GetSystemTime, GetTimeZonelnformation, EnumCalendarlnfo
 */

#include <QObject>
#include <QString>
#include <QMap>

#include <windows.h>

class SystemTime : public QObject
{
    Q_OBJECT
    LPSYSTEMTIME lpSystemTime;
public:
    SystemTime();
signals:
    void signalSetYear(QString value);
    void signalSetMonth(QString value);
    void signalSetDayOfWeek(QString value);
    void signalSetDay(QString value);
    void signalSetHour(QString value);
    void signalSetMinute(QString value);
    void signalSetSecond(QString value);
    void signalSetMilliseconds(QString value);

    void signalSetBias(QString value);
    void signalDayLightStatus(QString value);

    void signalHideTransitions();
    void signalShowTransitions();

    void signalSetLocalYear(QString value);
    void signalSetLocalMonth(QString value);
    void signalSetLocalDayOfWeek(QString value);
    void signalSetLocalDay(QString value);
    void signalSetLocalHour(QString value);
    void signalSetLocalMinute(QString value);
    void signalSetLocalSecond(QString value);
    void signalSetLocalMilliseconds(QString value);

    void signalSetTransitionStandardMonth(QString value);
    void signalSetTransitionStandardDay(QString value);
    void signalSetTransitionDaylightMonth(QString value);
    void signalSetTransitionDaylightDay(QString value);

    void signalSetCalFormatLong(QString value);
    void signalSetCalFormatShort(QString value);
    void signalSetCalDayLong(QString value);
    void signalSetCalDayShort(QString value);
    void signalSetCalMonthLong(QString value);
    void signalSetCalMonthShort(QString value);

public slots:
    void updateTime();
    void updateTimeZone();
    void updateCalendarInfo();
};
#endif // SYSTEMTIME_H
