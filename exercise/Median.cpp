#include <iostream>
#include <algorithm>
using namespace std;
bool is_odd(int a) { return a % 2; } // 1 means odd,0 means even
int main()
{
    int n, i;
    float m;
    scanf("%d", &n);
    int num[n] = {0};
    for (i = 0; i < n; i++)
        scanf("%d", &num[i]);
    sort(num, num + n);
    if (is_odd(n))
        m = num[(int)(n / 2)];
    else
        m = (num[n / 2] + num[n / 2 - 1]) / 2.00;
    printf("%.2f", m);
    return 0;
}