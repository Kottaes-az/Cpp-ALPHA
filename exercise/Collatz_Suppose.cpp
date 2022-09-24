#include <iostream>
int a[3000] = {1};
int main()
{
    int n, i = 0;
    scanf("%d", &n);
    while (n != 1) {
        a[++i] = n;
        n = (n % 2) ? (n * 3 + 1) : (n / 2);
    }
    printf("1");
    for (int j = i; j > 0; j--) printf(" %d", a[j]);
    return 0;
}