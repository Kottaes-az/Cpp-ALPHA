#include <iostream>
using namespace std;
int main()
{
    float t1, t2; //参与运算的两个量
    char opr;     //运算控制符
    scanf("%g%g%c", &t1, &t2, &opr);
    switch (opr) {
    case '+': cout << t1 + t2; break;
    case '-': cout << t1 - t2; break;
    case '*': cout << t1 * t2; break;
    case '/':
        if (t2)
            cout << t1 / t2;
        else
            cout << "Devided by zero";
        break;
    default: cout << "Invalid operator!"; break;
    }
    return 0;
}