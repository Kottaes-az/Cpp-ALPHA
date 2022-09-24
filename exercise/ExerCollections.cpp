#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

template <class T1, class T2> class Solution
{
  public:
    bool IsLeap(T1 a)
    {
        return (!(a % 4) && (a % 100)) || !(a % 400);
    }                         //判断是否闰年
    void Deci2Any(T1 n, T1 m) //将十进制数n转为m进制，2<=m<=16
    {
        if (!n) return;
        T1 tmp = n % m;
        n /= m;
        Deci2Any(n, m);
        if (m > 10 && tmp > 9) {
            printf("%c", tmp + 55);
            return;
        }
        printf("%d", tmp);
    }
    T2 MaxOf(T1 a[], T2 length)
    {
        //算法：基础打擂台，返回下标
        T2 max = 0;
        for (T2 i = 0; i < length; i++)
            if (a[i] > a[max]) max = i;
        return max;
    }
    T2 MinOf(T1 a[], T2 length)
    {
        //算法：基础打擂台，返回下标
        T2 min = 0;
        for (T2 i = 0; i < length; i++)
            if (a[i] < a[min]) min = i;
        return min;
    }
    T2 maxDeci(T2 n) //求最高位位数
    {
        T2 i = 10;
        while (n / i >= 10) i *= 10;
        return i;
    }
    T2 inv(T2 n) //数学方法求倒序数
    {
        if (n < 10) return n;
        return (n % 10) * maxDeci(n) + inv(n / 10);
    }
    T2 InRange(T1 a[], T2 length, T1 bor, T1 min, T1 max,
               string check = "FailCount")
    {
        /*  判断数组里有多少个数不在给定范围(闭集)内(inv的值)，或在此基础上判断有多少个数不在亚范围内(fail的值)
            (可理解为考试及格线问题)
        */
        T2 fail = 0, inv = 0;
        for (T2 i = 0; i < length; i++)
            if (a[i] >= min && a[i] < bor)
                fail++;
            else if (!(a[i] >= min && a[i] <= max))
                inv++;
        return ("FailCount" == check) ? fail : inv;
    }
};
