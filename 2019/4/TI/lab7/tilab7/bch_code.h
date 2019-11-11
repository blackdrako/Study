#ifndef BCH_CODE_H
#define BCH_CODE_H
#include "cyclic_coding.h"

class BCH : public CyclicCode {
    public:
        BCH(int r, int t = 2) : CyclicCode(r, t), g1_(r_ + 1, 1) {
            std::vector<int> g2(r_ + 1, 1);
            g1_[3] = g1_[2] = 0;
            std::swap(g_ , g1_);
            compute_GF();
            std::swap(g_, g1_);
            g_ = g1_ * g2;
            dellNull(g_);
            // ïîðîæäàþùèé ìíîãî÷ëåí
            std::cout << "r = " << r_ << ", n = " << n_ << ", k = " << k_ << std::endl;
            std::cout << "Ïîðîæäàþùèé ìíîãî÷ëåí g(x) = "
            << "(" << g1_ << ") * ( " << g2 << ") = " << g_ << std::endl;
            k_ = n_ - g_.size() + 1;
            std::cout << "q = " << g_.size() - 1 << "\nk = " << n_  << " - " << g_.size() - 1 << " = " << k_ << std::endl;
            output_GF();
            //output_bound();
        };
        std::vector<int> getS3(const std::vector<int>& y);
        virtual std::vector<int> decoding(std::vector<int>& code);
    private:
        std::vector<int> g1_;
};

#endif // BCH_CODE_H
