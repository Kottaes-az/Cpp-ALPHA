#include <iostream>
using namespace std;
int main()
{
    int n, i, j, max = 0;
    cin >> n;
    string c;
    int a[27] = {0};
    for (i = 0; i <= n; i++) {
        getline(cin, c);
        for (j = 0; j < (int)c.size(); j++)
            if (c[j] >= 'A' && c[j] <= 'Z') a[c[j] - 'A']++;
    }
    for (i = 0; i < 26; i++)
        if (a[i] > max) max = a[i];
    for (i = max; i > 0; i--, cout << endl)
        for (j = 0; j < 26; j++) cout << (a[j] >= i ? '*' : ' ') << ' ';
    for (char i = 'A'; i <= 'Z'; i++) cout << i << ' ';
    return 0;
}