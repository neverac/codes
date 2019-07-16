#include<bits/stdc++.h>
using namespace std;
long long p[1000005];
long long num[1000005];
long long tot=0;

void pini(long long x)
{
    long long x2=sqrt(x);
    long long tmp=x;
    for(int i=2;i<=x2;i++)
    {
        if(tmp%i==0)
        {
            p[++tot]=i;
            num[tot]=0;
            while(tmp%i==0)
            {
                num[tot]++;
                tmp/=i;
            }
        }
    }
    if(tmp!=1)
    {
        p[++tot]=tmp;
        num[tot]=1;
    }
}
long long solve(long long p, long long n)
{
    long long ans=0;
    while(n)
    {
        ans+=n/p;
        n/=p;
    }
    return ans;
}
int main()
{
    long long n,b;
    cin>>n>>b;
    pini(b);
    //for(int i=0;i<=tot;i++) cout<<p[i]<<num[i]<<endl;
    //cout<<solve(3,9)<<endl;
    long long ans=solve(p[1],n)/num[1];
    int i=2;
    while(i<=tot)
    {
        long long tmp=solve(p[i],n)/num[i];
        ans=min(tmp,ans);
        i++;
    }
    cout<<ans<<endl;
}

