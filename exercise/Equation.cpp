#include <iostream>
// NOIP2000-T1 计算器的改良(解形如ax±b=c的方程)
using namespace std;
int main()
{
    char unk; //存放未知数字母的字符
    /*未知数系数，常数项，临时累加数，是否在等号左边(不在则变为-1)，系数正负性(非正则变为-1)，是否读入了数字(用于未知数系数为1而省略的情况)*/
    ssize_t coe = 0, con = 0, tmp = 0, lef = 1, nega = 1, read = false;
    // 化简后的方程：coe*unk+con=0
    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++)
        if (isdigit(s[i])) //如果是数字
            tmp = tmp * 10 + s[i] - '0', read = true;
        else if (islower(s[i])) //如果是未知数
            coe += (read ? (lef * nega * tmp) : (lef * nega)),
                tmp = 0, unk = s[i], read = false;
        else {
            con += lef * nega * tmp, tmp = 0, read = false;
            if (s[i] == '=') //如果是等号
                lef = -1, nega = 1;
            else if (s[i] == '+' || s[i] == '-') //如果是运算符
                nega = (s[i] == '-' ? -1 : 1);
        }
    con += lef * nega * tmp; //如果有则加上最后的常数项，没有则加上0不变
    double ans = -con * 1.0 / coe;
    printf("%c=%.3lf", unk, ans == -0.0 ? 0 : ans);
    return 0;
}