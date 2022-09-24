#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
const long double PI = M_PI;
// y=x⅔+0.9×(N-x²)½×sin(a×π×x)
int main(int argc, char *argv[], char *env[])
{
    double x, y, dx = 1.0 / 16, dy = 1.0 / 16;
    for (y = 1.0; y >= -1.0; y -= dy, cout << endl)
        for (x = 0.0; x < 6.28; x += dx) putchar(" *"[pow(x, 2 / 3)]);
    return 0;
}