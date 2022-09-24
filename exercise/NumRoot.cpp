#include <iostream>
using namespace std;
bool is_positive_int(int n) { return n > 0; }
int num_root(int n)
{
    int tmp = 0, r_num;
    if (n % 10 == n)
        return n;
    while (is_positive_int(n))
    {
        r_num = n % 10;
        tmp += r_num;
        n /= 10;
    } //求数的个位之和
    num_root(tmp);
} //求出数根
int main()
{
    int s;
    scanf("%d", &s);
    printf("%d", num_root(s));
    return 0;
}