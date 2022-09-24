#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int a)
{
    if (a <= 3) return a > 1;
    for (int i = 2; i <= int(sqrt(a)); i++)
        if (a % i == 0) return 0;
    return 1;
}
int main()
{
    for (int s = 0; s < 2; s++) {
        //为防止意料之外的数据冗积，每次循环都重新进行变量的声明
        int n, num = 0, p[201] = {0}, sol[201] = {0};
        sol[0] = 1; // f(0) = 1
        cin >> n;
        for (int i = 2; i <= n; i++)
            if (isPrime(i)) p[++num] = i;
        for (int i = 1; i <= num; i++) // dynamic programming
            for (int j = p[i]; j <= n; j++) sol[j] += sol[j - p[i]];
        // f(n)=f(n)(未分配之前)+f(n-被分配质数)
        printf("%d\n", sol[n]);
    }
    return 0;
}