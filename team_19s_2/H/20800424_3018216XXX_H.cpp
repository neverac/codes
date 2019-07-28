#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[1000],n[1000];
ll pi=1;
ll tot=0;
void pini(ll x)
{
    ll x2=sqrt(x);
    ll tmp=x;
    for(ll i=2;i<=x2;i++)
    {
        if(tmp%i==0)
        {
            p[++tot]=i;
            n[tot]=0;
            while(tmp%i==0)
            {
                n[tot]++;
                tmp/=i;
            }
            pi*=(n[tot]+1);
        }
    }
    if(tmp!=1)
    {
        p[++tot]=tmp;
        n[tot]=1;
        pi*=2;
    }
}

int main()
{
    int t;
    cin>>t;
    ll x;
    while(t--)
    {
        memset(p,0,sizeof(p));
        memset(n,0,sizeof(n));
        tot=0;
        pi=1;
        cin>>x;
        pini(x);
        ll ans=0;
        for(int i=1;i<=tot;i++)
        {
            ans+=n[i]*pi/(n[i]+1);
        }
        cout<<ans<<endl;
    }
}
