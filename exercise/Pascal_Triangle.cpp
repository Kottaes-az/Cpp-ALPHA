#include <iostream>
const int N = 21;
int a[N][N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (i >= 2) a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            if (j == i || j == 0) a[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = n - 1 - i; k > 0; k--) printf(" ");
        for (int j = 0; j < i + 1; j++) printf("%d ", a[i][j]);
        printf("\n");
    }
}