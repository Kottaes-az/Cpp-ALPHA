#include <iostream>
#include <algorithm>
using namespace std;
#define SIDE 5
int a[SIDE][SIDE];
int main()
{
    int n, m, i, j;
    for (i = 0; i < SIDE; i++)
        for (j = 0; j < SIDE; j++)
            scanf("%d", &a[i][j]);
    scanf("%d %d", &n, &m);
    for (i = 0; i < SIDE; i++)
        swap(a[n - 1][i], a[m - 1][i]);
    for (i = 0; i < SIDE; i++)
    {
        for (j = 0; j < SIDE; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}