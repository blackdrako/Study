#ifndef SYSTEMPARAMS_H
#define SYSTEMPARAMS_H

#include <QObject>
#include <windows.h>

/*
 * SPI_GETACCESSTIMEOUT, SPI_GETKEYBOARDPREF, SPI_GETSCREENREADER, SPI_SCREENSAVERRUNNING, SPI_SETFILTERKEYS, SPI_SETMINIMIZEDMETRICS
 */

// Константы, задающие направление и начальное положение для минимизированных окон
typedef enum {BOTTOM_LEFT, BOTTOM_RIGHT, TOP_LEFT, TOP_RIGHT} START;
typedef enum {LEFT, RIGHT, UP, DOWN, HIDE} DIRECTION;

class SystemParams : public QObject
{
    Q_OBJECT
public:
    SystemParams();
    void updateData();
private:
    MINIMIZEDMETRICS currentMinimizedMetrics, defaultMinimizedMetrics;
    FILTERKEYS currentFilterKeys, defaultFilterKeys;
signals:
    void signalSetMMStart(int value);
    void signalSetMMDirection(int value);

    void signalSetAccessTimeOutOn(QString value);
    void signalSetAccessTimeout(QString value);
    void signalSetAccessOnOffFeedback(QString value);
    void signalSetKeyboardPrefferred(QString value);
    void signalSetScreenReaderOn(QString value);
    void signalSetScreenSaverRunning(QString value);

    void signalSetFKFilterAvailable(int value);
    void signalSetFKClickOn(int value);
    void signalSetFKConfirmHotkey(int value);
    void signalSetFKIsOn(int value);
    void signalSetFKHotkeyActive(int value);
    void signalSetFKHotkeySound(int value);
    void signalSetFKIndicator(int value);
    void signalSetMMWidth(int value);
    void signalSetMMHorizontalGap(int value);
    void signalSetMMVerticalGap(int value);
    void signalSetFKWait(int value);
    void signalSetFKDelay(int value);
    void signalSetFKRepeat(int value);
    void signalSetFKBounce(int value);

public slots:
    void setMM();
    void resetMM();

    void setFK();
    void resetFK();

    void setMMStart(int);
    void setMMDirection(int);
    void setMMWidth(int);
    void setMMHorizontalGap(int);
    void setMMVerticalGap(int);

    void setFKFilterAvailable(bool);
    void setFKClickOn(bool);
    void setFKConfirmHotkey(bool);
    void setFKIsOn(bool);
    void setFKHotkeyActive(bool);
    void setFKHotkeySound(bool);
    void setFKIndicator(bool);
    void setFKWait(unsigned long);
    void setFKDelay(unsigned long);
    void setFKRepeat(unsigned long);
    void setFKBounce(unsigned long);
};

#endif // SYSTEMPARAMS_H
