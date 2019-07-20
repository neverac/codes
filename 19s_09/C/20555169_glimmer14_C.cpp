#include <stdio.h>
using namespace std;

int gcd(int a, int b)
{
    int r = a % b;
    if (r == 0) return b;
    else return gcd(b, r);
}

int main()
{
    int t, ang, gg, a, b;
    scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &ang);
        gg = gcd(180, ang);
        a = 180 / gg;
        b = ang / gg;
        if (a == b + 1) a *= 2;
        printf("%d\n", a);
    }
}