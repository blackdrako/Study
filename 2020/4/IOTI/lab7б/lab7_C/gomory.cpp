#include "Gomory.h"

using namespace std;

void Gomory::Input() {
    cout << "Ââåäèòå êîýôôèöèåíòû ñèñòåìèû îãðàíè÷åíèé:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    cout << "Ââåäèòå êîýôôèöèåíòû öåëåâîé ôóíêöèè:" << endl;
    for (int i = 0; i < n; i++)
        cin >> Z[i];
}

bool Gomory::check_int() {
    for (int i = 0; i < m; i++)
        if (M[i][n - 1].denominator != 1) return false;
    return true;
}

bool Gomory::isPsevdo() {
    for (int i = 0; i < m; i++)
        if (M[i][n - 1].numerator < 0) return true;
    return false;
}

void Gomory::copyToSimp(SimplexArtificial& S) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n ; j++) {
            S.SLU[i][j] = M[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        S.Z[i] = Z[i];
    }
}

void Gomory::copyFromSimp(SimplexArtificial& S) {
    m = S.x - 1;
    n = S.y;
    M.Create(m , n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            M[i][j] = S.T[i][j + 1];
        }
        M[i][n - 1] = S.T[i][0];
    }
    for (int i = 0; i < n - 1; i++) {
        Z[i].numerator = -S.T[S.x - 1][i + 1].numerator;
        Z[i].denominator = S.T[S.x - 1][i + 1].denominator;
    }
    Z[n - 1] = S.T[S.x - 1][0];
}

void Gomory::copyToClar(ClarSimplexTable& C) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C.SLU[i][j] = M[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        C.Z[i] = Z[i];
    }
}

void Gomory::copyFromClar(ClarSimplexTable& C) {
    m = C.x - 1;
    n = C.y;
    M.Create(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            M[i][j] = C.T[i][j + 1];
        }
        M[i][n - 1] = C.T[i][0];
    }
    for (int i = 0; i < n - 1; i++) {
        Z[i].numerator = -C.T[C.x - 1][i + 1].numerator;
        Z[i].denominator = C.T[C.x - 1][i + 1].denominator;
    }
    Z[n - 1] = C.T[C.x - 1][0];
}

void Gomory::addRestrictions() {
    int k = 0;
    while (M[k][n - 1].denominator == 1) k++;
    Frac_matr a(m + 1, n + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++)
            a[i][j] = M[i][j];
        a[i][n - 1] = 0;
        a[i][n] = M[i][n - 1];
    }
    a[m][n - 1] = 1;
    for (int j = 0; j < n - 1; j++)
        a[m][j] = -(M[k][j].mod());
    a[m][n] = -(M[k][n - 1].mod());
    Frac_arr b(n + 1);
    for (int i = 0; i < n - 1; i++)
        b[i] = Z[i];
    b[n - 1] = 0; b[n] = Z[n - 1];
    M = a;
    Z = b;
    m++; n++;
}

void Gomory::GomorySolution() {
    SimplexArtificial S(m, n);
    copyToSimp(S);
    S.simplexArtificial();
    copyFromSimp(S);
    if (!check_int()) {
        addRestrictions();
        GomoryStep();
    }
    else outputSolution(S);
}

void Gomory::GomoryStep() {
    int f;
    ClarSimplexTable C(m, n);
    SimplexArtificial S(m, n);
    if (isPsevdo()) {
        copyToClar(C);
        C.clarification();
        copyFromClar(C);
        f = 1;
    }
    else {
        copyToSimp(S);
        S.simplexArtificial();
        copyFromSimp(S);
        f = 2;
    }
    if (!check_int()) {
        addRestrictions();
        GomoryStep();
    }
    else
        if (f == 1) outputSolution(C);
        else outputSolution(S);
}

long Search3(long* a, long n, long k, long* j)
{
    for (long i = 0; i < n; i++)
        if (k == a[i]) {
            *j = i;
            return 1;
        }
    return 0;
}

void Gomory::outputSolution(SimplexArtificial& S) {
    S.outputArtificialTable(cout);
    cout << "Z_max = " << S.T[S.x - 1][0] << endl;
    std::cout << "ò.max (";
    long j;
    for (long i = 1; i < S.y; i++) {
        if (Search3(S.base, S.x - 1, i, &j))
            std::cout << S.T[j][0];
        else std::cout << "     0    ";
        if (i < S.y - 1) std::cout << ", ";
    }
    std::cout << ")" << std::endl;
}

void Gomory::outputSolution(ClarSimplexTable& C) {
    cout << C;
    cout << "Z_max = " << C.T[C.x - 1][0] << endl;
    std::cout << "ò.max (";
    long j;
    for (long i = 1; i < C.y; i++) {
        if (Search3(C.base, C.x - 1, i, &j))
            std::cout << C.T[j][0];
        else std::cout << "     0    ";
        if (i < C.y - 1) std::cout << ", ";
    }
    std::cout << ")" << std::endl;
}
