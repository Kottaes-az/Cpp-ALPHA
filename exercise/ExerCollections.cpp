#include <iostream>
#include <limits>
#include <sstream>
using namespace std;
bool IsLeap(int a)
{
    return (!(a % 4) && (a % 100)) || !(a % 400);
} //判断是否闰年
int MaxOf(int *a)
{
    //算法：基础打擂台
    float max = -INT_MIN;
    for (int i = 0; i <= sizeof(a); i++)
        if (a[i] > max) max = a[i];
    return max;
}
int MinOf(int *a)
{
    //算法：基础打擂台
    int min = INT_MAX;
    for (int i = 0; i <= sizeof(a); i++)
        if (a[i] < min) min = a[i];
    return min;
}
int maxDeci(int n) //求最高位位数
{
    int i = 10;
    while (n / i >= 10) i *= 10;
    return i;
}
int inv(int n) //数学方法求倒序数
{
    if (n < 10) return n;
    return (n % 10) * maxDeci(n) + inv(n / 10);
}
int InRange(int *a, int bor, int min, int max, string check = "FailCount")
{
    /*  判断数组里有多少个数不在给定范围(闭集)内(inv的值)，或在此基础上判断有多少个数不在亚范围内(fail的值)
        (可理解为考试及格线问题)
    */
    int fail = 0, inv = 0;
    for (int i = 0; i < sizeof(a); i++) {
        if (a[i] >= min && a[i] < bor)
            fail++;
        else if (!(a[i] >= min && a[i] <= max))
            inv++;
    }
    if (check == "InvCount") return inv;
    return fail;
}
