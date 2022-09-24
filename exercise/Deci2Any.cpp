#include <iostream>
using namespace std;
void Deci2Any(int n, int m) //将十进制数n转为m进制，2<=m<=16
{
    if (!n) return;
    int tmp = n % m;
    n /= m;
    Deci2Any(n, m);
    if (m > 10 && tmp > 9) {
        printf("%c", tmp + 55);
        return;
    }
    printf("%d", tmp);
}
int main()
{
    int n, m;
    cin >> n >> m;
    Deci2Any(n, m);
    return 0;
}