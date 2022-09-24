#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    string s;
    int ans = 0;
    cin >> s;
    int len = (int)s.length();
    for (int i = 0; i < len; i++) {
        int j = i;
        while (s[i] == s[j + 1]) {
            if (j >= len) break;
            j++;
            ans++;
        }
        cout << ans + 1 << s[i];
        i = j;
        ans = 0;
    }

    return 0;
}