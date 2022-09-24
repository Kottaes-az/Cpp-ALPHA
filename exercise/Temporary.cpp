#include <iostream>
#include <string.h>
using namespace std;
int a[10001], tmp[10001];
int n;
void insert_sort()
{
    for (int i = 1; i <= n; i++)
        for (int j = i; j >= 2; j--)
            if (tmp[j] < tmp[j - 1]) swap(tmp[j], tmp[j - 1]);
}
int find(int k)
{
    for (int i = 1; i <= n; i++)
        if (tmp[i] == k) return i;
    return -1;
}
int main()
{
    int Q, opr, x, v;
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= Q; i++) {
        memcpy(tmp, a, n + 1);
        cin >> opr;
        switch (opr) {
        case 1:
            cin >> x >> v;
            a[x] = v;
            break;
        case 2:
            cin >> x;
            insert_sort();
            cout << find(a[x]) << endl;
            break;
        default: cout << "input error" << endl; break;
        }
    }
    return 0;
}