#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    string s;
    int o1, o2, result = 0;
    char opr = '0';
    cin >> s;
    for (int i = 0; i < (int)s.size() && opr == '0'; i++)
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ||
            s[i] == '%') {
            o1 = atoi((const char *)s.substr(0, i).c_str());
            o2 = atoi((const char *)s.substr(i + 1).c_str());
            opr = s[i];
        }
    switch (opr) {
    case '+': result = o1 + o2; break;
    case '-': result = o1 - o2; break;
    case '*': result = o1 * o2; break;
    case '/': result = o1 / o2; break;
    case '%': result = o1 % o2; break;
    }
    cout << result;
    return 0;
}