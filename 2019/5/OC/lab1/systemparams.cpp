#include "systemparams.h"

/*
 * SPI_GETACCESSTIMEOUT, SPI_GETKEYBOARDPREF, SPI_GETSCREENREADER, SPI_SCREENSAVERRUNNING, SPI_SETFILTERKEYS, SPI_SETMINIMIZEDMETRICS
 */

QString boolValue(bool val){
    return val ? "Да" : "Нет";
}

int flagToBool(int flag){
    return flag ? 1 : 0;
}

// Получить из поля iArrange направление и начало
// https://docs.microsoft.com/ru-ru/windows/win32/api/winuser/ns-winuser-minimizedmetrics
void getStartDirection(INT iArrange, int &direction, int &start){
    if (iArrange & ARW_TOPRIGHT){
        start = TOP_RIGHT;
        if (iArrange & ARW_DOWN){
            // Направление - вниз
            direction = DOWN;
        }else{
            direction = LEFT;
        }
    }else{
        if (iArrange & ARW_TOPLEFT){
            start = TOP_LEFT;
            if (iArrange & ARW_DOWN){
                direction = DOWN;
            }else{
                direction = RIGHT;
            }
        }else{
            if (iArrange & ARW_BOTTOMRIGHT){
                start = BOTTOM_RIGHT;
                if (iArrange & ARW_UP){
                    direction = UP;
                }else{
                    direction = LEFT;
                }
            }else{
                //BOTTOMLEFT
                start = BOTTOM_LEFT;
                if (iArrange & ARW_UP){
                    direction = UP;
                }else{
                    direction = LEFT;
                }
            }
        }
    }
    if (iArrange & ARW_HIDE){
        direction = HIDE;
    }
}

void SystemParams::updateData(){
    // Здесь надо получить штуки и отправить сигналы
    // Перед передачей структуры в функцию, надо заполнить поле с размером
    UINT uiParam = currentMinimizedMetrics.cbSize = sizeof(MINIMIZEDMETRICS);
    SystemParametersInfoW(
                SPI_GETMINIMIZEDMETRICS,
                uiParam,
                &currentMinimizedMetrics,
                0);
    // Полученную структуру запомним, чтобы можно было вернуться к исходному состоянию
    defaultMinimizedMetrics = currentMinimizedMetrics;

    // Отправим сигналы с новыми величинами
    int start, direction;
    getStartDirection(currentMinimizedMetrics.iArrange, direction, start);
    emit signalSetMMDirection(direction);
    emit signalSetMMStart(start);

    emit signalSetMMWidth(currentMinimizedMetrics.iWidth);
    emit signalSetMMVerticalGap(currentMinimizedMetrics.iVertGap);
    emit signalSetMMHorizontalGap(currentMinimizedMetrics.iHorzGap);

    // Проделаем то же самое с FILTERKEYS
    uiParam = currentFilterKeys.cbSize = sizeof(FILTERKEYS);
    SystemParametersInfoW(
                SPI_GETFILTERKEYS,
                uiParam,
                &currentFilterKeys,
                0);
    // Полученную структуру запомним, чтобы можно было вернуться к исходному состоянию
    defaultFilterKeys = currentFilterKeys;
    emit signalSetFKFilterAvailable(flagToBool(currentFilterKeys.dwFlags & FKF_AVAILABLE));
    emit signalSetFKClickOn(flagToBool(currentFilterKeys.dwFlags & FKF_CLICKON));
    emit signalSetFKConfirmHotkey(flagToBool(currentFilterKeys.dwFlags & FKF_CONFIRMHOTKEY));
    emit signalSetFKIsOn(flagToBool(currentFilterKeys.dwFlags & FKF_FILTERKEYSON));
    emit signalSetFKHotkeyActive(flagToBool(currentFilterKeys.dwFlags & FKF_HOTKEYACTIVE));
    emit signalSetFKHotkeySound(flagToBool(currentFilterKeys.dwFlags & FKF_HOTKEYSOUND));
    emit signalSetFKIndicator(flagToBool(currentFilterKeys.dwFlags & FKF_INDICATOR));
    emit signalSetFKWait(currentFilterKeys.iWaitMSec);
    emit signalSetFKDelay(currentFilterKeys.iDelayMSec);
    emit signalSetFKRepeat(currentFilterKeys.iRepeatMSec);
    emit signalSetFKBounce(currentFilterKeys.iBounceMSec);

    ACCESSTIMEOUT *act = new ACCESSTIMEOUT;
    uiParam = act->cbSize = sizeof(ACCESSTIMEOUT);
    SystemParametersInfoW(
                SPI_GETACCESSTIMEOUT,
                uiParam,
                act,
                0);
    emit signalSetAccessOnOffFeedback(boolValue(act->dwFlags & ATF_ONOFFFEEDBACK));
    emit signalSetAccessTimeOutOn(boolValue(act->dwFlags & ATF_TIMEOUTON));
    emit signalSetAccessTimeout(boolValue(act->iTimeOutMSec));

    delete act;
    BOOL tmp_bool;
    SystemParametersInfoW(
                SPI_GETKEYBOARDPREF,
                0,
                &tmp_bool,
                0);
    emit signalSetKeyboardPrefferred(boolValue(tmp_bool));
    SystemParametersInfoW(
                SPI_GETSCREENREADER,
                0,
                &tmp_bool,
                0);
    emit signalSetScreenReaderOn(boolValue(tmp_bool));
    SystemParametersInfoW(
                SPI_SCREENSAVERRUNNING,
                0,
                &tmp_bool,
                0);
    emit signalSetScreenSaverRunning(boolValue(tmp_bool));
}

SystemParams::SystemParams(){
}

void SystemParams::setMM(){
    currentMinimizedMetrics.cbSize = sizeof(MINIMIZEDMETRICS);
    SystemParametersInfoW(
                SPI_SETMINIMIZEDMETRICS,
                currentMinimizedMetrics.cbSize,
                &currentMinimizedMetrics,
                0);
    updateData();
}

void SystemParams::resetMM(){
    currentMinimizedMetrics = defaultMinimizedMetrics;
    setMM();
    updateData();
}

void SystemParams::setFK(){
    currentFilterKeys.cbSize = sizeof(FILTERKEYS);
    SystemParametersInfoW(
                SPI_SETFILTERKEYS,
                currentFilterKeys.cbSize,
                &currentFilterKeys,
                0);
    updateData();
}

void SystemParams::resetFK(){
    currentFilterKeys = defaultFilterKeys;
    setFK();
    updateData();
}

// Слоты установки новых значений
void SystemParams::setMMStart(int start){
    if (start == BOTTOM_LEFT) currentMinimizedMetrics.iArrange |= ARW_BOTTOMLEFT;
    if (start == BOTTOM_RIGHT) currentMinimizedMetrics.iArrange |= ARW_BOTTOMRIGHT;
    if (start == TOP_LEFT) currentMinimizedMetrics.iArrange |= ARW_TOPLEFT;
    if (start == TOP_RIGHT) currentMinimizedMetrics.iArrange |= ARW_TOPRIGHT;
}

void SystemParams::setMMDirection(int direction){
    if (direction == HIDE) currentMinimizedMetrics.iArrange |= ARW_HIDE;
    if (direction == LEFT) currentMinimizedMetrics.iArrange |= ARW_LEFT;
    if (direction == RIGHT) currentMinimizedMetrics.iArrange |= ARW_RIGHT;
    if (direction == UP) currentMinimizedMetrics.iArrange |= ARW_UP;
    if (direction == DOWN) currentMinimizedMetrics.iArrange |= ARW_DOWN;
}

void SystemParams::setMMWidth(int width){
    currentMinimizedMetrics.iWidth = width;
}

void SystemParams::setMMHorizontalGap(int hgap){
    currentMinimizedMetrics.iHorzGap = hgap;
}

void SystemParams::setMMVerticalGap(int vgap){
    currentMinimizedMetrics.iVertGap = vgap;
}

void SystemParams::setFKFilterAvailable(bool val){
    if (val) currentFilterKeys.dwFlags |= FKF_AVAILABLE;
}

void SystemParams::setFKClickOn(bool val){
    if (val) currentFilterKeys.dwFlags |= FKF_CLICKON;
}

void SystemParams::setFKConfirmHotkey(bool val){
    if (val) currentFilterKeys.dwFlags |= FKF_CONFIRMHOTKEY;
}

void SystemParams::setFKIsOn(bool val){
    if (val) currentFilterKeys.dwFlags |= FKF_FILTERKEYSON;
}

void SystemParams::setFKHotkeyActive(bool val){
    if (val) currentFilterKeys.dwFlags |= FKF_HOTKEYACTIVE;
}

void SystemParams::setFKHotkeySound(bool val){
    if (val) currentFilterKeys.dwFlags |= FKF_HOTKEYSOUND;
}

void SystemParams::setFKIndicator(bool val){
    if (val) currentFilterKeys.dwFlags |= FKF_INDICATOR;
}

void SystemParams::setFKWait(unsigned long wait){
    currentFilterKeys.iWaitMSec = wait;
}

void SystemParams::setFKDelay(unsigned long delay){
    currentFilterKeys.iDelayMSec = delay;
}

void SystemParams::setFKRepeat(unsigned long repeat){
    currentFilterKeys.iRepeatMSec = repeat;
}

void SystemParams::setFKBounce(unsigned long bounce){
    currentFilterKeys.iBounceMSec = bounce;
}
