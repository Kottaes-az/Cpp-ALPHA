#include <climits>
#include <cstring>
#include <iostream>
using namespace std;
class Solution
{
  public:
    void wordToken(char *dest[], char src[], char opr[2] = " ")
    {
        size_t j = 0;
        char *token;
        token = strtok(src, opr);
        while (token != NULL) {
            dest[j++] = token;
            token = strtok(NULL, opr);
        }
    }
    bool isLeap(size_t a) //判断是否闰年
    {
        return (!(a % 4) && (a % 100)) || !(a % 400);
    }
    void deci2Any(size_t n, int m) //将十进制数n转为m进制，2<=m<=16
    {
        if (!n) return;
        long tmp = n % m;
        n /= m;
        deci2Any(n, m);
        if (m > 10 && tmp > 9) {
            printf("%c", tmp + 55);
            return;
        }
        printf("%d", tmp);
    }
    template <class T1> size_t maxOf(T1 a[], size_t length)
    {
        //算法：基础打擂台，返回下标
        size_t max = 0;
        for (size_t i = 0; i < length; i++)
            if (a[i] > a[max]) max = i;
        return max;
    }
    template <class T1> size_t minOf(T1 a[], size_t length)
    {
        //算法：基础打擂台，返回下标
        size_t min = 0;
        for (size_t i = 0; i < length; i++)
            if (a[i] < a[min]) min = i;
        return min;
    }
    size_t maxDeci(size_t n) //求最高位位数
    {
        size_t i = 10;
        while (n / i >= 10) i *= 10;
        return i;
    }
    size_t inv(size_t n) //数学方法求倒序数
    {
        if (n < 10) return n;
        return (n % 10) * maxDeci(n) + inv(n / 10);
    }
    template <class T1>
    size_t inRange(T1 a[], size_t length, T1 bor, T1 min, T1 max,
                   char check[] = "FailCount")
    {
        /*  判断数组里有多少个数不在给定范围(闭集)内(inv的值)，或在此基础上判断有多少个数不在亚范围内(fail的值)
            (可理解为考试及格线问题)
        */
        size_t fail = 0, inv = 0;
        for (size_t i = 0; i < length; i++)
            if (a[i] >= min && a[i] < bor)
                fail++;
            else if (!(a[i] >= min && a[i] <= max))
                inv++;
        return ("FailCount" == check) ? fail : inv;
    }
    int minSizeSubarray(int nums[], int len, int target) //长度最小的子数组
    {
        int sum = 0, subl = 0, subr = 0, mink = __INT16_MAX__;
        while (subl <= subr) {
            while (subr < len && sum < target) sum += nums[++subr];
            if (subr < len && sum >= target)
                mink = (mink < subr - subl) ? mink : subr - subl;
            else if (subr == len && sum >= target)
                mink = (mink < len - subl) ? mink : len - subl;
            else
                break;
            sum -= nums[++subl];
        }
        return (__INT16_MAX__ == mink) ? 0 : mink;
        for (int i = subl; i < subr; i++) printf("%d ", nums[i]);
    }
};
