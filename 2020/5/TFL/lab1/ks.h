#ifndef KS_H
#define KS_H
#include "iostream"
#include "vector"
#include "string"
class ks
{
private:
    std::vector <unsigned int> o_ks;
    std::vector<std::string> ksm;
    void Lway();
    void read_oKS();
public:
    ks();
    bool calc_rKS();
    void read_ksm();
    void write_ksm();
};

#endif // KS_H
