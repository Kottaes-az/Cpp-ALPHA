#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int j = 1, space = 0;
    char *token, opr[2] = " ", st[501] = {0};
    cin.getline(st, 500);
    for (int i = 0; i <= (int)strlen(st); i++)
        if (st[i] == ' ') space++;
    token = strtok(st, opr);
    while (token != NULL) {
        cout << strlen(token);
        if (j < space - 1) cout << ',';
        token = strtok(NULL, opr);
        j++;
    }
    return 0;
}