#include<cstdio>
#include<algorithm>
#include<cstring>
#define SIZE 1000010
#define MOD 998244353

using namespace std;

int in[10010];
long long ans[SIZE];
int main()
{
    int t,top=-1;
    long long i;
    ans[1]=1;
    ans[2]=5;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",in+i);
        top=max(top,in[i]);
    }

    for(i=3;i<=top;i++)
    {
        ans[i]=ans[i-1]+i*(i+i+i+2)/4;
    }
    for(i=0;i<t;i++)
        printf("%lld\n",ans[in[i]]);
    return 0;
}