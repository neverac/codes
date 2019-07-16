#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define SIZE 1000100
#define MOD 1000000007

using namespace std;

bool judge[SIZE];
struct st
{
    long long num;
    int times;
}rec[1000];

int main()
{
    long long n,b,nn;
    int j,k;
    long long cnt;
    long long ans=0x3fffffffffffffff;
    long long i,fac;
    scanf("%lld%lld",&n,&b);
    nn=n;
    int top=0;
    memset(judge,true,SIZE);
    judge[2]=true;
    for(i=4;i<SIZE;i+=2)
        judge[i]=false;
    for(i=3;i<SIZE;i+=2)
    {
        for(j=i;!judge[j];j+=2);
        for(k=2;k*j<SIZE;k++)
            judge[i*k]=false;
    }
    if(b%2==0)
    {
        rec[top].num=2;
        rec[top].times=1;
        b/=2;
        while(b%2==0)
        {
            b/=2;
            rec[top].times++;
        }
        top++;
    }
    for(i=3;i*i<=b;i+=2)
    {
        while(!judge[i])
            i+=2;
        if(b%i==0)
        {
            rec[top].num=i;
            rec[top].times=1;
            b/=i;
            while(b%i==0)
            {
                b/=i;
                rec[top].times++;
            }
            top++;
        }
    }
    if(b>1)
    {
        rec[top].num=b;
        rec[top].times=1;
        top++;
    }
    for(i=0;i<top;i++)
    {
        n=nn;
        cnt=0;
        while(n)
        {
    //        printf("n=%lld\n",n);
            cnt+=n/rec[i].num;
            n/=rec[i].num;
        }
    //    printf("num=%lld times=%d cnt=%lld\n",rec[i].num,rec[i].times,cnt);
        ans=min(ans,cnt/rec[i].times);
    }
    printf("%lld\n",ans);
    return 0;
}

