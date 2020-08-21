#include "bch_code.h"

std::vector<int> BCH::getS3(const std::vector<int>& y)
{
    std::vector<int> s3(n_, 0);
    s3[0] = y[0];
    for (int i = 1; i < y.size(); i++) {
        if (y[i]) {
            s3 = s3 + E_[(i * 3) % n_];
        }
    }
    dellNull(s3);
    return s3;
}

std::vector<int> BCH::decoding(std::vector<int>& code)
{
    output_bound();
    std::cout << QString::fromUtf8("Декодирование: ").toLocal8Bit().data() << std::endl;
    std::cout << QString::fromUtf8("Принятое слово y = ").toLocal8Bit().data();
    output_vector(code);
    std::cout << std::endl;
    std::cout << QString::fromUtf8("Принятый многочлен y(x) = ").toLocal8Bit().data() << code << std::endl;
    std::cout << "\nS1 = y(E) = ";
    std::vector<int> S1 = computeE(code);
    std::vector<int> S3 = getS3(code);
    std::vector<int> info(k_);
    output_E(S1);
    std::cout << "\nS3 = y(E^3) = ";
    output_E(S3);
    std::cout << std::endl;
    if (!S1.size() && !S3.size()) {
        std::cout << "S1 = S3 = 0 => y(x) = c(x)" << std::endl;
    }
    else {
        std::vector<int> S1_3 = S1 * S1 * S1;
        std::vector<int> S1_1 = E_[n_ - S1.size()];
        dellNull(S1_1);
        dellNull(S1_3);
        std::cout << "S1^3 = ";
        S1_3 = computeE(S1_3);
        std::cout << " = ";
        output_E(S1_3);
        std::cout << "\nS1^(-1) = (";
        output_E(S1_3);
        int p = getNumE(S1);
        std::cout << ")^(-1) = " << "(e" << p << ")^(-1) = ";
        S1_1 = E_[n_ - p];
        output_E(S1_1);
        std::vector<int> res((S1_3 + S3) * S1_1);
        std::cout << "\n\nf: X^2 + (";
        output_E(S1);
        std::cout << ") * X + ";
        output_E(res);
        std::cout << QString::fromUtf8("\nКорни уравнения: ").toLocal8Bit().data() << std::endl;
        std::vector<int> mistakes;
        for (int i = 0; i < n_; i++) {
            std::cout << "f(e" << i << ")\t = ";
            std::vector<int> solve = E_[i] * E_[i];
            solve = solve + E_[i] * S1 + res;
            output_E(solve);
            if (solve.size() > r_) {
                std::cout << " = ";
                solve = computeE(solve);
                output_E(solve);
            }
            if (!solve.size()) {
                std::cout << QString::fromUtf8("\nОшибка в ").toLocal8Bit().data() << i << QString::fromUtf8(" бите").toLocal8Bit().data();
                mistakes.push_back(i);
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < mistakes.size(); i++) {
            code[mistakes[i]] = (code[mistakes[i]]) ? 0 : 1;
        }
        std::cout << QString::fromUtf8("Исправленное кодовое слово:\n").toLocal8Bit().data()
            << "c(x) = " << code <<
            "\nc = ";
        output_vector(code);
        std::cout << "\n\n";
    }

    std::copy(code.begin() + n_ - k_, code.end(), info.begin());
    std::cout << QString::fromUtf8("Информационное слово i = ").toLocal8Bit().data();
    output_vector(info);
    std::cout << std::endl;
    std::cout << QString::fromUtf8("Информационный многочлен i(x) = ").toLocal8Bit().data() << info << std::endl;
    output_bound();
    return info;
}
