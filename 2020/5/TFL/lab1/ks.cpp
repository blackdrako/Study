#include "ks.h"

ks::ks()
{

}

void ks::read_ksm(){
    std::string buffer = "";
    std::cout << "Read KS:" << std::endl;
    do{
        std::getline(std::cin,buffer);
        if(buffer.size()>0){
            ksm.push_back(buffer);
        }
    } while (buffer != "");
    std::cout << "Order Y/N:" << std::endl;
    char temp;
    std::cin >> temp;
    buffer = "";
    if(temp == 'Y' or temp == 'y'){

    }
}

void ks::write_ksm(){
    unsigned long int vector_size = ksm.size();
    for (unsigned long int i = 0; i < vector_size; i++) {
        std::cout << i+1 << "." << ksm[i] << std::endl;
    }
}
