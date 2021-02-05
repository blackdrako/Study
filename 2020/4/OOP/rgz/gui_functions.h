#ifndef GUI_FUNCTIONS_H
#define GUI_FUNCTIONS_H

#include <sstream>
#include <string>
#include <QTextCodec>
#include <QTextStream>

namespace gui
{
    const std::string menu_title(const std::string title);
    const std::string menu_divider(const unsigned amount = 30, const char symbol = '-');
    const std::string menu_item(const unsigned index, const std::string text);
}

#endif // GUI_FUNCTIONS_H
