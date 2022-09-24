#include <iostream>
#include <limits>
using namespace std;
int main()
{
    int i, n;
    int max = 0, min = INT_MAX;
    cin >> n;
    if (n >= 0 && n <= 1000) {
        int l[n] = {0};
        for (i = 1; i <= n; i++) {
            cin >> l[i];
            if (l[i] > max) max = l[i];
            if (l[i] < min) min = l[i];
        }
        printf("%d", max - min);
    }
    return 0;
}
