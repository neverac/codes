#include <bits/stdc++.h>
using namespace std;

int num[233333];

int main()
{
    int n, tot1 = 0, tot2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] > 0)
            tot1++;
        if (num[i] < 0)
            tot2++;
    }
    int ls = n / 2;
    if (n % 2 == 1)
        ls++;
    if (tot1 >= ls)
        puts("1");
    else if (tot2 >= ls)
        puts("-1");
    else
        puts("0");
    return 0;
}