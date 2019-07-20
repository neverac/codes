#include <stdio.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
ll ans[N];

void creat()
{
    ans[1] = 1;
    ans[2] = 5;
    for (int i = 3; i < N; i ++)
        ans[i] = 1 + 3 * ans[i - 1] - 3 * ans[i - 2] + ans[i - 3] + ((i & 1) == 0);
}

int main()
{
    creat();
    int t, n;
    scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
}