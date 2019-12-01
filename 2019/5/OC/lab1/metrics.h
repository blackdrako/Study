#ifndef METRICS_H
#define METRICS_H


#include <QList>
#include <QString>
#include <QMap>
#include <windows.h>
#include <winuser.h>

class Metrics
{
public:
    Metrics();
    static const QString getName(int metric);
    static const QString getValue(int metric);
    static const QString getUnit(int metric);
    static const QString getDescription(int metric);
    static const QList<int> getPossibleMetrics();
private:
    struct metric_fields {
        QString name;
        QString unit;
        QString description;
        QString (* interpret_value)(int value);
    };
    static const QMap<int, struct metric_fields> metrics;

    static QString interpretInt(int);
    static QString interpretBool(int);
    static QString interpretBoot(int);
};

#endif // METRICS_H
