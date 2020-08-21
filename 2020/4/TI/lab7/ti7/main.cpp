#include <iostream>

#include "bch_code.h"

int main()
{
    system("cls");
    BCH r(4);
    int k;
    std::cout << std::endl << "0 - ñãåíåðèðîâàòü ñëó÷àéíîå êîäîâîå ñëîâî" << std::endl;
    std::cout << std::endl << "1 - ââåñòè êîäîâîå ñëîâî" << std::endl;
    std::cin >> k;
    std::vector<int> info;
    if (k)
        info = r.read_info();
    else
        info = r.generate_info();

    //std::cout << "˜˜˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ i(x) = " << info << std::endl;
    std::vector<int> code = r.coding(info);
    r.putMistake(code);

    info = r.decoding(code);
    system("pause");
}
