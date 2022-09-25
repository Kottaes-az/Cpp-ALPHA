#include <iostream>
#include <string.h>
using namespace std;
int a[10001], tmp[10001];
int n;
int tar_pos(int tar)
{
    for (int i = 1; i <= n; i++)
        for (int j = i; j >= 2; j--)
            if (tmp[j] < tmp[j - 1]) {
                swap(tmp[j], tmp[j - 1]);
                if (tar == j) tar--;
                if (tar == j - 1) tar++;
            }
    return tar;
}
int main()
{
    int Q, opr, x, v;
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= Q; i++) {
        memcpy(tmp, a, n + 1);
        cin >> opr;
        if (1 == opr) {
            cin >> x >> v;
            a[x] = v;
        }
        else if (2 == opr) {
            cin >> x;
            cout << tar_pos(x) << endl;
        }
    }
    return 0;
}