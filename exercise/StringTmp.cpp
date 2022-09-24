#include <iostream>
#include <math.h>
using namespace std;
#define Limit 1000
int Deci2Bin(int a)
{
    int tmp = a, i = 0, bin[100000] = {0}, ret = 0;
    /*短除操作，但不倒序填入*/
    while (tmp > 0) {
        bin[++i] = tmp % 2;
        tmp /= 2;
    }
    /*累加*/
    for (int j = 0; j < i - 1; j++) ret += bin[j] * pow(10, j);
    return ret;
}
int main()
{
    int TyA = 0, TyB = 0;
    for (int x = 1; x <= Limit; x++) {
        int tmp1 = 0, tmp0 = 0;
        string S = to_string(Deci2Bin(x));
        for (int y = 0; y <= (int)S.size(); y++)
            if (S[y] == '1')
                tmp1++;
            else if (S[y] == '0')
                tmp0++;
        if (tmp1 > tmp0)
            TyA++;
        else
            TyB++;
    }
    cout << TyA << ' ' << TyB << endl;
    return 0;
}