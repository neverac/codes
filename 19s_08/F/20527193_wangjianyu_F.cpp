#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 100100
using namespace std;

long long rec[SIZE];

int main()
{
    int n,t,i;
    int tmp,pos;
    long long ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",rec+i);
    sort(rec,rec+n);
    if(rec[0]<0)
    {
        ans=rec[n-1];
        for(i=n-2;rec[i]>0;i--)
            ans+=rec[i];
        for(pos=i;i>=0;i--)
            ans-=rec[i];
        printf("%lld\n",ans);
        for(i=pos+1;i<n-1;i++)
        {
            printf("%lld %lld\n",rec[0],rec[i]);
            rec[0]-=rec[i];
        }
        for(i=0;i<=pos;i++)
        {
            printf("%lld %lld\n",rec[n-1],rec[i]);
            rec[n-1]-=rec[i];
        }
    }
    else
    {
        if(n==1)
            ans=rec[0];
        else
            ans=-rec[0];
        for(i=1;i<n;i++)
            ans+=rec[i];
        printf("%lld\n",ans);
        for(i=1;i<n-1;i++)
        {
            printf("%lld %lld\n",rec[0],rec[i]);
            rec[0]-=rec[i];
        }
        if(n>1)
        printf("%lld %lld\n",rec[n-1],rec[0]);
    }

    return 0;
}
