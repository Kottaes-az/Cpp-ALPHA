#include <iostream>
#include <limits>
#include <sstream>
using namespace std;
bool IsLeap(int a)
{
    return (!(a % 4) && (a % 100)) || !(a % 400);
} //判断是否闰年
template <class T1, class RET> class Solution
{
  public:
    RET MaxOf(T1 a[], RET length)
    {
        //算法：基础打擂台，返回下标
        RET max = 0;
        for (RET i = 0; i < length; i++)
            if (a[i] > a[max]) max = i;
        return max;
    }
    RET MinOf(T1 a[], RET length)
    {
        //算法：基础打擂台，返回下标
        RET min = 0;
        for (RET i = 0; i < length; i++)
            if (a[i] < a[min]) min = i;
        return min;
    }
    RET maxDeci(RET n) //求最高位位数
    {
        RET i = 10;
        while (n / i >= 10) i *= 10;
        return i;
    }
    RET inv(RET n) //数学方法求倒序数
    {
        if (n < 10) return n;
        return (n % 10) * maxDeci(n) + inv(n / 10);
    }
    RET InRange(T1 a[], RET length, int bor, int min, int max,
                string check = "FailCount")
    {
        /*  判断数组里有多少个数不在给定范围(闭集)内(inv的值)，或在此基础上判断有多少个数不在亚范围内(fail的值)
            (可理解为考试及格线问题)
        */
        RET fail = 0, inv = 0;
        for (RET i = 0; i < length; i++)
            if (a[i] >= min && a[i] < bor)
                fail++;
            else if (!(a[i] >= min && a[i] <= max))
                inv++;
        return ("FailCount" == check) ? fail : inv;
    }
};
