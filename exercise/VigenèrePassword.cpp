#include <iostream>
using namespace std;
// Vigenère密码
int main()
{
    string abt1, abt2, k, c, tmpk;
    char tmp1 = 'a', tmp2 = 'A';
    for (int i = 0; i < 26; i++) {
        abt1 += tmp1++;
        abt2 += tmp2++;
    }
    abt1 += abt1; //小写字母表，双重
    abt2 += abt2; //大写字母表，双重
    cin >> k >> c;
    int lenK = k.size(), lenC = c.size();
    for (int i = 0; i < lenK; i++)
        if (k[i] >= 'A' && k[i] <= 'Z') k[i] += 'a' - 'A';
    for (int i = 0; i <= lenC / lenK; i++) tmpk += k;
    for (int i = 0; i < lenC; i++) //将C一个一个转成明文
        for (int j = (int)abt1.size() / 2; j < (int)abt1.size(); j++)
            if (c[i] == abt1[j]) {
                c[i] = abt1[j - tmpk[i] + 'a'];
                break;
            }
            else if (c[i] == abt2[j]) {
                c[i] = abt2[j - tmpk[i] + 'a'];
                break;
            }
    for (int i = 0; i < lenC; i++) cout << c[i];
    return 0;
}