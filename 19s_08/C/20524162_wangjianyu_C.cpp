#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 50010
using namespace std;


int main()
{
    long long k,a,b;
    int times;
    long long ans=1;
    scanf("%lld%lld%lld",&k,&a,&b);
    if(b-a>2)
    {
        k-=a-1;
        times=k>>1;
        ans=a+(b-a)*times;
        if(k&1)
            ans++;
    }
    else
    {
        ans+=k;
    }
    printf("%lld\n",ans);
    return 0;
}
