#ifndef OTHERAPI_H
#define OTHERAPI_H

#include <QObject>
#include <windows.h>

/*
 * ActivateKeyboardLayout, GetCurrencyFormat, GetLastError, OemToChar
 */

class OtherAPI : public QObject
{
    Q_OBJECT
public:
    OtherAPI();
public slots:
    void updateError();
    void updateCurrency(int value);
    void switchKBNext();
    void switchKBPrev();
    void oemToCharIn(QString str);
signals:
    void signalSetLastErrCode(QString code);
    void signalSetLastErrMsg(QString message);
    void signalSetCurrency(QString value);
    void oemToCharOut(QString str);
};
#endif // OTHERAPI_H
