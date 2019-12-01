#include "metrics.h"

// Сопоставление константы, ее названия и описания, а также функции для преобразования результат в строку
const QMap<int, struct Metrics::metric_fields> Metrics::metrics = {
{SM_CLEANBOOT,      {"SM_CLEANBOOT",     "",    "В каком режиме загружена система",                                                                         Metrics::interpretBoot}},
{SM_CMONITORS,      {"SM_CMONITORS",     "",    "Количество активных мониторов",                                                                            Metrics::interpretInt}},
{SM_CMOUSEBUTTONS,  {"SM_CMOUSEBUTTONS", "",    "Количество кнопок мыши, или 0 - если мыши нет",                                                            Metrics::interpretInt}},
{SM_CXBORDER,       {"SM_CXBORDER",      "px",  "Ширина границы окна",                                                                                      Metrics::interpretInt}},
{SM_CXCURSOR,       {"SM_CXCURSOR",      "px",  "Ширина курсора",                                                                                           Metrics::interpretInt}},
{SM_CXDLGFRAME,     {"SM_CXDLGFRAME",    "px",  "Ширина рамки диалогового окна",                                                                            Metrics::interpretInt}},
{SM_CXDOUBLECLK,    {"SM_CXDOUBLECLK",   "px",  "Ширина прямоугольной области, в которой второе нажатие на кнопку мыши воспринимается как двойное нажатие", Metrics::interpretInt}},
{SM_CXBORDER,       {"SM_CXBORDER",      "px",  "Ширина рамки окна",                                                                                        Metrics::interpretInt}},
{SM_CXDRAG,         {"SM_CXDRAG",        "px",  "Ширина 'мертвой' области при перетаскивании",                                                              Metrics::interpretInt}},
{SM_CXEDGE,         {"SM_CXEDGE",        "px",  "Ширина 3D рамки",                                                                                          Metrics::interpretInt}},
{SM_CXFIXEDFRAME,   {"SM_CXFIXEDFRAME",  "px",  "Толщина горизонтальной рамки вокруг окна фиксированного размера",                                          Metrics::interpretInt}},
{SM_CXFOCUSBORDER,  {"SM_CXFOCUSBORDER", "px",  "Ширина левого и правого краев прямоугольника фокусировки",                                                 Metrics::interpretInt}},
{SM_CXFULLSCREEN,   {"SM_CXFULLSCREEN",  "px",  "Ширина окна в полноэкранном режиме",                                                                       Metrics::interpretInt}},
{SM_CXHSCROLL,      {"SM_CXHSCROLL",     "px",  "Ширина стрелки на горизонтальной полосе прокрутки",                                                        Metrics::interpretInt}},
{SM_CXHTHUMB,       {"SM_CXHTHUMB",      "px",  "Ширина ползунка на горизонтальной полосе прокрутки",                                                       Metrics::interpretInt}},
{SM_CXICON,         {"SM_CXICON",        "px",  "Ширина значка",                                                                                            Metrics::interpretInt}},
{SM_CXICONSPACING,  {"SM_CXICONSPACING", "px",  "Ширина сетки для значков",                                                                                 Metrics::interpretInt}},
{SM_CXMAXIMIZED,    {"SM_CXMAXIMIZED",   "px",  "Ширина открытого на весь экран окна",                                                                      Metrics::interpretInt}},
{SM_CXMAXTRACK,     {"SM_CXMAXTRACK",    "px",  "Максимальная ширина окна с заголовком и изменяемыми размерами",                                            Metrics::interpretInt}},
{SM_CXMIN,          {"SM_CXMIN",         "px",  "Минимальная ширина окна",                                                                                  Metrics::interpretInt}},
{SM_CXMINIMIZED,    {"SM_CXMINIMIZED",   "px",  "Ширина минимизированного окна",                                                                            Metrics::interpretInt}},
{SM_CXSCREEN,       {"SM_CXSCREEN",      "px",  "Ширина экрана на основном мониторе",                                                                       Metrics::interpretInt}},
{SM_CXSIZE,         {"SM_CXSIZE",        "px",  "Ширина кнопки в заголовке окна",                                                                           Metrics::interpretInt}},
{SM_CXSIZEFRAME,    {"SM_CXSIZEFRAME",   "px",  "Толщина горизонтальной рамки вокруг окна с изменяемым размером",                                           Metrics::interpretInt}},
{SM_CXSMICON,       {"SM_CXSMICON",      "px",  "Рекомендуемый размер для маленьких иконок",                                                                Metrics::interpretInt}},
{SM_CXVIRTUALSCREEN,{"SM_CXVIRTUALSCREEN","px", "Ширина виртуального экрана (сумма ширин всех дисплеев)",                                                   Metrics::interpretInt}},
{SM_CXVSCROLL,      {"SM_CXVSCROLL",     "px",  "Ширина вертикальной полосы прокрутки",                                                                     Metrics::interpretInt}},
{SM_CYBORDER,       {"SM_CYBORDER",      "px",  "Высота рамки окна",                                                                                        Metrics::interpretInt}},
{SM_CYCAPTION,      {"SM_CYCAPTION",     "px",  "Высота области надписи",                                                                                   Metrics::interpretInt}},
{SM_CYCURSOR,       {"SM_CYCURSOR",      "px",  "Высота курсора",                                                                                           Metrics::interpretInt}},
{SM_CYDLGFRAME,     {"SM_CYDLGFRAME",    "px",  "Высота рамки диалогового окна",                                                                            Metrics::interpretInt}},
{SM_CYDOUBLECLK,    {"SM_CYDOUBLECLK",   "px",  "Высота прямоугольной области, в которой второе нажатие на кнопку мыши воспринимается как двойное нажатие", Metrics::interpretInt}},
{SM_CYDRAG,         {"SM_CYDRAG",        "px",  "Высота 'мертвой' области при перетаскивании",                                                              Metrics::interpretInt}},
{SM_CYEDGE,         {"SM_CYEDGE",        "px",  "Высота рамки окна",                                                                                        Metrics::interpretInt}},
{SM_CYFIXEDFRAME,   {"SM_CYFIXEDFRAME",  "px",  "Толщина вертикальной рамки вокруг окна фиксированного размера",                                            Metrics::interpretInt}},
{SM_CYFULLSCREEN,   {"SM_CYFULLSCREEN",  "px",  "Высота окна в полноэкранном режиме",                                                                       Metrics::interpretInt}},
{SM_CYHSCROLL,      {"SM_CYHSCROLL",     "px",  "Высота горизонтальной полосы прокрутки",                                                                   Metrics::interpretInt}},
{SM_CYICON,         {"SM_CYICON",        "px",  "Высота значка",                                                                                            Metrics::interpretInt}},
{SM_CYICONSPACING,  {"SM_CYICONSPACING", "px",  "Высота сетки для значков",                                                                                 Metrics::interpretInt}},
{SM_CYMAXIMIZED,    {"SM_CYMAXIMIZED",   "px",  "Высота открытого на весь экран окна",                                                                      Metrics::interpretInt}},
{SM_CYMAXTRACK,     {"SM_CYMAXTRACK",    "px",  "Максимальная высота окна с заголовком и изменяемыми размерами",                                            Metrics::interpretInt}},
{SM_CYMIN,          {"SM_CYMIN",         "px",  "Минимальная высота окна",                                                                                  Metrics::interpretInt}},
{SM_CYMINIMIZED,    {"SM_CYMINIMIZED",   "px",  "Высота минимизированного окна",                                                                            Metrics::interpretInt}},
{SM_CYSCREEN,       {"SM_CYSCREEN",      "px",  "Высота экрана на основном мониторе",                                                                       Metrics::interpretInt}},
{SM_CYSIZE,         {"SM_CYSIZE",        "px",  "Высота кнопки в заголовке окна",                                                                           Metrics::interpretInt}},
{SM_CYSIZEFRAME,    {"SM_CYSIZEFRAME",   "px",  "Толщина вертикальной рамки вокруг окна с изменяемым размером",                                             Metrics::interpretInt}},
{SM_CYSMICON,       {"SM_CYSMICON",      "px",  "Рекомендуемый размер для маленьких иконок",                                                                Metrics::interpretInt}},
{SM_CYVIRTUALSCREEN,{"SM_CYVIRTUALSCREEN","px", "Высота виртуального экрана (сумма ширин всех дисплеев)",                                                   Metrics::interpretInt}},
{SM_CYVSCROLL,      {"SM_CYVSCROLL",     "px",  "Высота стрелки на вертикальной полосе прокрутки",                                                          Metrics::interpretInt}},
{SM_CYVTHUMB,       {"SM_CYVTHUMB",      "px",  "Высота ползунка на вертикальной полосе прокрутки",                                                         Metrics::interpretInt}},
{SM_DEBUG,          {"SM_DEBUG",         "",    "Установлена отладочная версия User.exe",                                                                   Metrics::interpretBool}},
{SM_MEDIACENTER,    {"SM_MEDIACENTER",   "",    "Версия системы - MediaCenter Edition",                                                                     Metrics::interpretBool}},
{SM_MOUSEPRESENT,   {"SM_MOUSEPRESENT",  "",    "Подключена мышь",                                                                                          Metrics::interpretBool}},
{SM_MOUSEWHEELPRESENT, {"SM_MOUSEWHEELPRESENT", "", "Мышь имеет колесо для прокрутки",                                                                      Metrics::interpretBool}},
{SM_SLOWMACHINE,    {"SM_SLOWMACHINE", "", "На компьютере установлен слабый процессор",                                                                     Metrics::interpretBool}}
};

Metrics::Metrics(){

}

const QString Metrics::getName(int metric){
    if (!metrics.contains(metric)){
        return "Неизвестная метрика";
    }
    return metrics[metric].name;
}

const QString Metrics::getValue(int metric){
    if (!metrics.contains(metric)){
        return "Неизвестная метрика";
    }
    int value = GetSystemMetrics(metric);
    return metrics[metric].interpret_value(value);
}

const QString Metrics::getUnit(int metric){
    if (!metrics.contains(metric)){
        return "Неизвестная метрика";
    }
    return metrics[metric].unit;
}

const QString Metrics::getDescription(int metric){
    if (!metrics.contains(metric)){
        return "Неизвестная метрика";
    }
    return metrics[metric].description;
}

const QList<int> Metrics::getPossibleMetrics(){
    return metrics.keys();
}

QString Metrics::interpretInt(int value){
    return QString::number(value);
}

QString Metrics::interpretBool(int value){
    return value ? "Да" : "Нет";
}

QString Metrics::interpretBoot(int value){
    switch (value){
        case 0:
            return "Нормальная загрузка";
        case 1:
            return "Безопасная загрузка";
        case 2:
            return "Безопасная загрузка с поддержкой сети";
        default:
            return "Неожиданное значение: " + QString::number(value);
    }
}
