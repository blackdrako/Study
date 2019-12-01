#include "otherapi.h"
#include <QDebug>

OtherAPI::OtherAPI(){

}

void OtherAPI::updateError(){
    // errorMessageID будет содержать код последней ошибки
    DWORD errorMessageID = GetLastError();
    // Чтобы получить словесное описание кода, используем FormatMessage
    LPWSTR messageBuffer = nullptr;
    size_t size = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                         NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&messageBuffer, 0, NULL);
    // Пошлем сигнал с этим сообщением и номером ошибки
    emit signalSetLastErrMsg(QString::fromWCharArray(messageBuffer, size));
    emit signalSetLastErrCode(QString::number(errorMessageID));
}

// Получить строковое представление числа как суммы денег
// в текущей валюте
void OtherAPI::updateCurrency(int value){
    LPWSTR input = new WCHAR[256];
    LPWSTR result = new WCHAR[256];
    QString qs_input = QString::number(value);
    int sz_input = qs_input.toWCharArray(input);
    input[sz_input] = 0;
    int sz;
    sz = GetCurrencyFormatW(LOCALE_USER_DEFAULT, 0, input, NULL, result, 256);
    QString to_emit = QString::fromWCharArray(result, sz);
    emit signalSetCurrency(to_emit);
}

// Переключение раскладки туда и обратно
void OtherAPI::switchKBNext(){
    ActivateKeyboardLayout((HKL)HKL_NEXT, 0);
}

void OtherAPI::switchKBPrev(){
    ActivateKeyboardLayout((HKL)HKL_PREV, 0);
}

// Конвертирование между раскладками
void OtherAPI::oemToCharIn(QString str){
    char* input_buffer = str.toLocal8Bit().data();
    WCHAR result_buffer[256];
    OemToCharW(input_buffer, result_buffer);
    emit oemToCharOut(QString::fromWCharArray(result_buffer));
}
