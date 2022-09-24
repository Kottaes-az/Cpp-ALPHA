#include <iostream>
#include <string.h>
using namespace std;
const int Limit = 1000;
int m, n, x, s = 0;
int a[Limit + 1];
void func()
{
    int k = 0;
    if (a[x] == 0 && s >= m) //内存满了 且新数为下标那格为空 进if条件
                             //其他情况说明内存中有数 空跑一次func()函数啥也不做
    {
        s++; //进循环代表查了一次词典++
        for (int i = 0; i < Limit + 1; i++) //遍历数组
        {
            if (a[i] >= 1) //遇到里面存有数字  则把他们减1
                           //一共m个数,代表原来是存1的格子变0 原来是2变1...
            {
                a[i] -= 1;
                k++;
            }
            if (k == m) //一共m个数 提前找完提前结束
                break;
        }
        if (m > 0) //当初输入的内存不为空 把新数为下标那格存入内存大小数 m
                   //之前是m的那格被-1了 变成m-1
            a[x] = m;
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++) // n次循环
    {
        cin >> x;               // n个单词x
        if (a[x] == 0 && s < m) // x为下标这格为空 且内存还没有满时s<m
        {
            s++;
            a[x] = s; // x下标这格 里面存放s值   里面数会是[1,m)
                      // 代表在内存中存入顺序 越大越后面
        }
        else
            func(); //当前格子不为空 或者内存满了
    }
    cout << s;
    return 0;
}