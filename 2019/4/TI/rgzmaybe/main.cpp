#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <time.h>
#include <fstream>
#include <math.h>
#include <conio.h>
#include <dos.h>

char tabl[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void writeMatr(char **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%i ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

char **getCheckMatrix(int m, int *n, int *k)
{
    *n = (1 << m) - 1;
    *k = *n - m;
    char **matr = (char**) calloc(m, sizeof(char));
    for (int i = 0; i < m; i++)
        matr[i] = (char*) calloc(*n, sizeof(char));
    for (int i = m - 1, h = 1; i >= 0; i--, h <<= 1)
        for (int j = *n - 1; j >= 0; j -= 2*h)
            for (int x = 0; x < h; x++)
                matr[i][j - x] = 1;
    return matr;
}

char **getSubMatrix(char **H, int m, int n, int k)
{
    char **a = (char **) calloc(m, sizeof(char*));
    for (int i = 0; i < m; i++)
    {
        a[i] = (char *) calloc(n, sizeof(char));
        for (int j = 0; j < n; j++)
            a[i][j] = H[i][j];
    }
    for (int j = 1, h = 1, x = 0; j <= n; j++)
        if (j % h == 0)
            h = j;
        else
        {
            for (int i = 0; i < m; i++)
                a[i][x] = a[i][j - 1];
            x++;
        }
    return a;
}

char **getGenMatrix(char **H, int m, int n, int k)
{
    char **matr = (char**) calloc(k, sizeof(char*));
    for (int i = 0; i < k; i++)
        matr[i] = (char*) calloc(n, sizeof(char));
    char **a = getSubMatrix(H, m, n, k);

    for (int j = 1, h = 1, i = m - 1, x = 0; j <= n; j++)
        if (j % h == 0)
        {
            h = j;
            for (int z = 0; z < k; z++)
                matr[z][j - 1] = a[i][z];
            i--;
        }
        else
            matr[x++][j - 1] = 1;
    return matr;
}

std::string M[100] = {};
float vec[100] = {0};
void read_data(char *s, std::string a[100], float b[100], int *i)
{
    FILE *f = fopen(s, "r");
    char c;
    float p = 0;
    while (!feof(f))
    {
        fscanf(f, "%c", &c);
  //    printf("%i\n",c);
   //     printf("%c  %c",c,toupper(c));
        if (c != ' ' && c != '\0' && c != '\n')
        {
            c = c + 100;
            a[*i] = c;
            fscanf(f,"%f",&b[(*i)++]);
            p += b[(*i) - 1];
        }

    }
            a[*i] = ' ' + 100;
        b[(*i)++] = 1 - p;
    fclose(f);
}

int read_message(char *s, std::string *w, int *flag)
{
    char c;
    int i = 0;
    FILE *f = fopen(s,"r");
    int fq = 0;
    fscanf(f,"%i", &fq);
    *flag = fq;
    fscanf(f,"%c",&c);
    while (!feof(f))
    {
        if (c != '\0' && c != '\n')
        {
            i++;
            *w += c + 100;
        }
        fscanf(f,"%c",&c);
    }
    fclose(f);
    return i;
}

void sort(float *p, std::string **a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        float x = p[i];
        std::string t = a[i][0];
        for (j = i - 1; j>=0 && p[j] < x; j--)
        {
            p[j+1] = p[j];
            a[j+1][0] = a[j][0];
        }
        p[j+1] = x;
        a[j+1][0] = t;
    }
}

static int Q = 0;
void sort(float *p, std::string *a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        float x = p[i];
        std::string t = a[i];
        for (j = i - 1; j>=0 && (p[j] < x || (p[j] == x && a[j] > t)); j--)
        {
            p[j+1] = p[j];
            a[j+1] = a[j];
        }
        p[j+1] = x;
        a[j+1] = t;
    }
}

void searchTree(std::string branch, std::string full_branch, int start_pos, int end_pos, float *p, std::string **res)
{

    std::string c_branch;
    int i, m;

    c_branch = full_branch + branch;

    if (start_pos == end_pos)
    {
        res[Q++][1] = c_branch;
        return;
    }

    float min = 2;
    float dS = 0;
    for (i = start_pos; i <= end_pos; i++)
        dS +=p[i];
    i = end_pos;
    m = i;
    while (min >= fabs(dS) && i > start_pos)
    {
        min = dS;
        dS = dS - 2*p[i];
        i--;
        m--;
    }

    if (min >= fabs(dS))
        min = dS;
    else
    {
        i++;
        m++;
    }
    searchTree("0", c_branch, start_pos, m, p, res);
    searchTree("1", c_branch, m + 1, end_pos, p, res);
}


void searchTreeH(float *p, std::string **res, int n, int d)
{
    float *ver = (float*) calloc(n, sizeof(float));
    std::string *alp = (std::string*) calloc(n, sizeof(std::string));
    for (int i = 0; i < n; i++)
    {
        ver[i] = p[i];
        alp[i] = res[i][0];
    }
    float P = 0;
    int k = n;
    while (fabs(P - 1) > 0.0001)
    {
        sort(ver, alp, k);
      //  std::cout << ver[k-2] <<"   " << alp[k-2] << "\t" << ver[k-1] << "   "<<alp[k-1] <<"\n";


        P = ver[k - 1] + ver[k - 2];
        ver[k - 2] = P;
        for (int j = 0; j <= alp[k-1].length(); j += d)
        {
            std::string temp = "";
            for (int q = j ; q < j + d; q++)
                temp = temp + alp[k-1][q];
            for (int i = 0; i < n; i++)
                if (temp == res[i][0])
                    res[i][1] = "1" + res[i][1];
        }
        for (int j = 0; j <= alp[k-2].length(); j += d)
        {
            std::string temp = "";
            for (int q = j; q < j + d; q++)
                temp = temp + alp[k-2][q];
            for (int i = 0; i < n; i++)
                if (temp == res[i][0])
                    res[i][1] = "0" + res[i][1];
        }
        alp[k - 2] = alp[k - 2] + alp[k - 1];
        k--;
    }
}

void razm(int i, int n, float *p, std::string *a, std::string ***c, float **ps, int k, int *kol)
{
    for (int j = 0; j < n; j++)
    {
        M[i] = a[j];
        vec[i] = p[j];
        if (i == k - 1)
        {
            (*ps) = (float*) realloc(*ps, (*kol + 1)*sizeof(float));
            (*ps)[*kol] = 1;
            for (int t = 0; t < k; t++)
                (*ps)[*kol] *= vec[t];

            (*c) = (std::string**) realloc(*c, (*kol + 1) * sizeof(std::string));
            (*c)[*kol] = (std::string*) calloc(k, sizeof(std::string));
            for (int t = 0; t < k; t++)
                (*c)[*kol][0] += M[t];
        //    std::cout << (*c)[*kol][0] << " " << (*ps)[*kol] << std::endl;
            (*kol)++;
        }
        else
            razm(i+1,n,p,a,c,ps,k,kol);
    }
}

int ShennonFano(std::string *a, float *p, int n, int d, float **ps, std::string ***res)
{
    int N = 0;
    if (d > 1)
        razm(0,n,p,a,&(*res),&(*ps),d,&N);
    else
    {
        *res = new std::string *[n];
        N = n;
        for (int i = 0; i < n; i++)
        {
            (*res)[i] = new std::string[2];
            (*res)[i][0] = a[i];
        }
        *ps = p;
    }
    sort(*ps,*res,N);
    searchTree("", "", 0, N-1, *ps, *res);
    return N;
}

int haffman(std::string *a, float *p, int n, int d, float **ps, std::string ***res)
{
    int N = 0;
    if (d > 1)
        razm(0,n,p,a,&(*res),&(*ps),d,&N);
    else
    {
        *res = new std::string *[n];
        N = n;
        for (int i = 0; i < n; i++)
        {
            (*res)[i] = new std::string[2];
            (*res)[i][0] = a[i];
        }
        *ps = p;
    }
    sort(*ps,*res,N);
    searchTreeH(*ps, *res, N, d);
    return N;
}

int searchBlock(std::string** a, std::string block, int N)
{
    for (int i = 0; i < N; i++)
        if (block == a[i][0])
            return i;
    printf("символа нету в алфавите в блоке ");
    std::cout << block;
    return -1;
}

int searchCodBlock(std::string **a, std::string block, int N)
{
    for (int i = 0; i < N; i++)
        if (block == a[i][1])
            return i;
    return -1;
}

std::string to_dv(int n, int x)
{
    std::string w;
    n = 1 << n - 1;
    while (n > 0)
    {
        if ((x & n) != 0)
            w += "1";
        else
            w += "0";
        n >>= 1;
    }
    return w;
}

int stringToDec(std::string s)
{
    int n = s.length();
    int a = 0;
    for (int i = 0; i < n; i++)
        a += (s[i] - '0') << (n - i - 1);
    return a;
}

std::string decodeMessage(std::string m_cod, float *ps, std::string **res, int N)
{
    int i = 0;
    int n = m_cod.length();
    int l = 0;
    std::string block = "";
    while (block.size() < 8)
        block += m_cod[i++];
    int d = stringToDec(block);
    block = "";
    while (block.size() < 8)
        block += m_cod[i++];
    int j = stringToDec(block);
    block = "";
    std::string m = "";
    printf("\n");
    while (i < n)
    {
        if (m_cod[i] <= ' ')
            i++;
        else
            block += m_cod[i++];
        int t = 0;
        if ((t = searchCodBlock(res, block, N)) >= 0)
        {
            l += d;
            m += res[t][0];
            std::cout << res[t][1] << "\t" << res[t][0] << "\n";
            block = "";
        }
    }
    m.resize(l - j);
    return m;
}

std::string encodeMessage(std::string m, int n, float *ps, std::string **res, int N, int d)
{
    int p = 0;
    std::string block;
    printf("\nразобьем сообщение на блоки по %i символов\n",d);
    for (int i = 0; i*d < n; i++)
    {
        block = "";
        for (int j = 0; j < d && d*i+j < n; j++)
           block += m[d*i+j];
        std::cout << block << "\n";
    }
    printf("\n");
    if (n % d != 0)
    {
        p =  d - (n % d);
        printf("\nДополним наше сообщение %i-м(я) символом(ами) %c\n", p, res[0][0][0]);
        for (int i = 0; i < p; i++)
            m += res[0][0][0];
        n += d - (n % d);
        std::cout << m << "\n\n";
    }


    printf("разобъем сообщение на блоки по %i символу(ов) и закодируем:\n", d);
    int k = n / d;
    std::string m_cod = "";
    m_cod += to_dv(8,d);
    m_cod += to_dv(8,p);
    for (int i = 0; i < k; i++)
    {
        std::string block = "";
        for (int j = 0; j < d; j++)
            block += m[d*i+j];
        std::cout << block;
        int t = searchBlock(res,block,N);
        printf("| (p = %.4f) |", ps[t]);
        std::cout << res[t][1] << "\n";
        m_cod += res[t][1];
    }
    std::cout << "\n\nВ начало допишем " << 8 << " бит (" << to_dv(8,p) << ") с кол-вом дописанных символов\n";
    std::cout << "Допишем в начало закодированного сообщения " << 8 << " бита (" << to_dv(8,d) << "), которые будут означать что размеры блоков равны " << d;
    std::cout << "\n\nРезультат кодирования :\n" << m_cod << "\n\n";
    return m_cod;
}

void write_arr(float *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%.4f  ",a[i]);
    std::cout << std::endl;
}
void write_arr(std::string *a, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << a[i] << "     ";
    std::cout << std::endl;
}

char **readMessage(int m, char *name, int *N)
{
    std::string s;
    FILE *f = fopen(name, "r");
    char c;
    for (int i = 0; !feof(f); i++)
    {
        fscanf(f, "%c", &c);
        s += c;
    }
    fclose(f);
    std::cout << s << "(" << s.size() - 2 << ")\n";
    printf("\nразобьем сообщение на блоки по %i символов\n",m);
    for (int i = 0; i < s.size();)
    {
        for (int j = 0;  i < s.size() && j < m; j++, i++)
            if (s[i] == ' ')
                j--;
            else
                std::cout << s[i];
        printf("\n");
    }
    printf("\n");
    int n = (s.size() - 2) / m;
    std::string block = to_dv(m, m - (s.size() - 2) % m);
    if ((s.size() - 2) % m != 0)
    {
        n += 2;
        printf("дополним сообщение %i битами '0'\n", m - (s.size() - 2) % m);
        printf("В начало допишем %i бит (", m);
        std::cout << block << ")\n";
        s.resize(s.size() + m - (s.size() - 2) % m, '0');
    }
    s = block + s;
    std::cout << "\n" << s << "\n";
    char **mesage = (char **) calloc(n, sizeof(char* ));
    for (int i = 0, k = 0; i < n; i++)
    {
        mesage[i] = (char *)  calloc(m + 2, sizeof(char));
        for (int j = 0; k < s.size() && j < m ; j++, k++)
        {
            if (s[k] == ' ')
                k++;
            mesage[i][j] = s[k];
        }
    }
    *N = n;
    return mesage;
}

char *encode(char *mes, char **g, int n, int k)
{
    char *c = (char *) calloc(n, sizeof(char));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            c[i] ^= mes[j] * g[j][i];
    return c;
}

void addError(char **c, int N, int n)
{
    srand(time(NULL));
    int i = rand() % N;
    int j = rand() % n;
    c[i][j] ^= 1;
    printf("Произошла ошибка в %i-ом(ем) слове в %i бите\n", i + 1, j + 1);
}

std::string *getSindrom(char **y, char **H, int N, int m, int n)
{
    char w[100][100] = {0};
    for (int z = 0; z < N; z++)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                w[z][i] ^= y[z][j] * H[i][j];
    }
    std::string *s = new std::string [N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < m; j++)
            s[i][j] = w[i][j];
    }
    return s;
}

std::string *decode(char **c, char **H, char **G, int *N, int m, int n, int k)
{
    int d1 = 0;
    std::string *s = getSindrom(c, H, *N, m, n);
    std::string *y = new std::string[*N];
    for (int z = 0; z < *N; z++)
    {
        printf("код. слово ");
        for (int i = 0; i < n; i++)
            printf("%i", c[z][i]);
        int t = 0;
        for (int i = 0; i < m; i++)
            t += s[z][i] << m - i - 1;
        if (t != 0)
            c[z][t - 1] ^= 1;
        printf("  (синдром = ");
        for (int i = 0; i < m - 1; i++)
            printf("%i", s[z][i]);
        printf("%i) --->  ", s[z][m - 1]);
        if (t != 0)
        {
            printf("исправленное кодовое слово : ");
            for (int i = 0; i < n; i++)
                printf("%i",c[z][i]);
            printf(" ---> ");
        }
        std::string block;
        int x = 0;
        for (int j = 0; j < n; j++)
        {
            int t = 0;
            int i = 0;
            while (i < k && t < 2)
                t += G[i++][j];
            if (t == 1)
            {
                if (z == 0)
                {
                    y[z] += c[z][j] + '0';
                    block += c[z][j] + '0';
                    if (block.size() == k)
                        d1 = stringToDec(block);
                }
                else
                    y[z - 1] += c[z][j] + '0';
            }
        }
        if (z == 0)
        {
            for (int i = 0; i < k; i++)
                printf("%c", y[z][i]);
            y[z] = "";
        }
        else
            for (int i = 0; i < k; i++)
                printf("%c",y[z - 1][i]);
        printf("\n");
    }
    printf("\nудалим с конца %i символов\n", d1);
    *N -= 1;
    y[*N - 1].resize(k - d1);
    return y;
}
int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    QCoreApplication app(argc, argv);
    std::string a[100];
    std::string M;
    std::string M_cod;
    float p[100];
    int nA = 0;
    read_data("alphavit.txt", a, p, &nA);
    int flag = 0;
    int Nm = read_message("message1.txt", &M, &flag);

    printf("Ai: ");
    write_arr(a,nA);
    printf("Pi: ");
    write_arr(p,nA);
    std::cout << "\nИсходное сообщение: " << M << " (n = " << Nm << ")" << "\n\n";

    int f;
    int Nres = 0;
    int d;
    float *ps = NULL;
    std::string **res = NULL;
   f = 0;
     if (flag == 1)
    {  switch (f)
    {
        case 0:
        {
           d = 3;
            Nres = ShennonFano(a,p,nA,d,&ps,&res);
            M_cod = encodeMessage(M,Nm,ps,res,Nres,d);
            break;
        }
        case 1 :
        {
            d = 3;
            Nres = haffman(a,p,nA,d,&ps,&res);
            M_cod = encodeMessage(M,Nm,ps,res,Nres,d);
            break;
        }
    }


    std::ofstream g("result.txt");
    std::string Block = "";
    int DD = 0;
    for (int i = 0; i < M_cod.length();)
        {
            Block = "";
            int j = 0;
            for (j = 0; i < M_cod.length() && j < 4; j++, i++)
                Block += M_cod[i];
            while (j < 4)
            {
                j++;
                Block += '0';
                DD++;
            }
            std::cout << "BLOCK = " << Block << std::endl;
            int KKQ = stringToDec(Block);
            g << tabl[KKQ];
        }

            g << tabl[DD];
            std::cout << "DD BLOCK = " << DD << std::endl;
    //g << M_cod;
    g.close();
        }
    else
    {
        f = 0;
        switch (f)
    {
        case 0:
        {
           d = 3;
            Nres = ShennonFano(a,p,nA,d,&ps,&res);
            break;
        }
        case 1 :
        {
            d = 3;
            Nres = haffman(a,p,nA,d,&ps,&res);
            break;
        }
    }
    int m,n,k;
    std::string MM2 = "";
    int QE = 0;
    for (int i = 0; i < M.length(); i++)
        std::cout <<(char)( M[i] - 100);
    for (int i = 0; i < M.length(); i++)
        {
            switch ((char)( M[i] - 100))
            {
            case '0':
                MM2 += "0000";
                QE = 0;
                break;
                            case '1':
                MM2 += "0001";
                QE = 1;
                break;
                            case '2':
                                QE = 2;
                MM2 += "0010";
                break;
                            case '3':
                                QE = 3;
                MM2 += "0011";
                break;
                            case '4':
                                QE = 4;
                MM2 += "0100";
                break;
                            case '5':
                                QE = 5;
                MM2 += "0101";
                break;
                            case '6':
                                QE = 6;
                MM2 += "0110";
                break;
                            case '7':
                                QE = 7;
                MM2 += "0111";
                break;
                            case '8':
                                QE = 8;
                MM2 += "1000";
                break;
                            case '9':
                                QE = 9;
                MM2 += "1001";
                break;
                            case 'A':
                MM2 += "1010";
                QE = 10;
                break;
                            case 'B':
                                QE = 11;
                MM2 += "1011";
                break;
                            case 'C':
                                QE = 12;
                MM2 += "1100";
                break;
                            case 'D':
                                QE = 13;
                MM2 += "1101";
                break;
                            case 'E':
                                QE = 14;
                MM2 += "1110";
                break;
                            case 'F':
                                QE = 15;
                MM2 += "1111";
                break;
            }

        }
        std::cout << " QE  =   "<< QE << std::endl << "\n\n" << MM2 << "\n\n\n";
        MM2.erase(MM2.length() - 4 - QE + 1);

    std::ofstream g("message.txt");
    g << MM2;
    g.close();

    m = 4;
    char **H = getCheckMatrix(m, &n, &k);
    printf("n = %i\nk = %i\n\n",n,k);
    printf("проверочная матрица H(%ix%i):\n",m,n);
    writeMatr(H,m,n);
    printf("\nпорождающая матрица G(%ix%i):\n",k,n);
    char **G = getGenMatrix(H, m, n, k);
    writeMatr(G,k,n);
    int N = 0;
    char **message = readMessage(k, "message.txt", &N);
    printf("\n\n");
    std::string m_cod;
    char **c = (char **) calloc(N, sizeof(char *));
    printf("Разобьем сообщение на блоки по %i символов и закодируем\n",k);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < k; j++)
        {
            message[i][j] -= '0';
            printf("%i", message[i][j]);
        }
        printf("    ");
        c[i] = encode(message[i], G, n, k);
        for (int t = 0; t < n; t++)
        {
            m_cod += (c[i][t] + '0');
            printf("%i", c[i][t]);
        }
        printf("\n");
    }
    printf("\n");
    std::cout << "закодированное сообщение Хэммингом:\n" << m_cod << "\n\n";
    int t;
    addError(c, N, n);
    printf("поулчили код :\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < n; j++)
            printf("%i", c[i][j]);
    printf("\n\n");
    std::string *y = decode(c, H, G, &N, m, n, k);
    std::ofstream F("message.txt");
    for (int i = 0; i < N; i++)
    {
        std::cout << y[i] << "\n";
        F << y[i];
    }
    F.close();

    std::string m_decode = decodeMessage(MM2,ps,res,Nres);
    for (int i = 0; i < m_decode.length(); i++)
        printf("%c",m_decode[i] -100);
    std::ofstream F2("result.txt");
        for (int i = 0; i < m_decode.length(); i++)
        F2 << (char)(m_decode[i] -100);
    }
    return app.exec();
}
