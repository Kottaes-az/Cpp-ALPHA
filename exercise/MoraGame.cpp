#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
template <class T> T randGen(T a, T b, unsigned int seed = time(0))
{
    srand(time(0));
    return rand() % b + a; // From b to a-1+b,b is the range
}
template <class T> T Mora_Input(const char addition_output[])
{
    T a;
    cout << addition_output;
    cin >> a;
    return a;
}
int Compare(int a, int b)
{
    // a is the choice of program,b is the choice of user.
    if ((a == 1 && b == 3) || (a == 2 && b == 1) || (a == 3 && b == 2))
        return 1; // User lose.
    if ((a == 3 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 3))
        return 0; // User win.
    if (a == b) return 2;
    if ((int)a == a && (int)b == b)
        return 3;
    else
        return randGen<int>(10, 100);
}
void Mora_Program(bool type)
{
    // The Rock-Paper-Scissors Game
    // 1 means Rock,2 means Paper,3 means Scissors
    if (!type) return;
    printf("Let's Play the Rock-Paper-Scissors game !");
    int a = randGen<int>(1, 3);
    int b = Mora_Input<int>(
        "Your Choice(1 means Rock,2 means Paper,3 means Scissors):");
    switch (Compare(a, b)) {
    case 0: printf("You win this time."); break;
    case 1: printf("The Program Win,But you lose this time."); break;
    case 2: printf("You two have got a same choice this time."); break;
    case 3:
        printf("Error!You(User) Just Input a error number which "
               "isn't in the range of 1,2 or 3!");
        break;
    default: printf("Fatal Input Error!");
    }
}
int main()
{
    bool mora = true;
    Mora_Program(mora);
    return 0;
}