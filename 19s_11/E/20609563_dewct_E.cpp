#include <bits/stdc++.h>
using namespace std;

int num[233333];
int ls[233333];
int ls2[233333];
int ls3[233333];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        ls[i] = num[i];
    }
    int ans = 0;
    sort(ls + 1, ls + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (ls[i] != num[i])
            ans++, ls2[ans] = i;
    }
    sort(ls + 1, ls + n + 1, cmp);
    int ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ls[i] != num[i])
            ans2++, ls3[ans2] = i;
    }
    ans = min(ans, ans2);
    if (ans > 2)
        puts("No hope");
    else if (ans == 2)
    {
        if (ans2 == 2)
            printf("Yes\n%d %d", ls3[1], ls3[2]);
        else
            printf("Yes\n%d %d", ls2[1], ls2[2]);
    }
    else
        puts("Nothing to do here");
    return 0;
}