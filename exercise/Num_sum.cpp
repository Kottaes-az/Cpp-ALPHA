#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    do
    {
        n /= 10;
        sum++;
    } while (n > 0);
    printf("%d", sum);
    return 0;
}