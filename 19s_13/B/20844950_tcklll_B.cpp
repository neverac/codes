#include <bits/stdc++.h>
#define ll long long
#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d",&a,&b)
#define MAXN 10005
#define INF 1000000000000000.
#define mod 998244353
using namespace std;
ll index[100005][2]={0};
int main()
{
    ll n;scanf("%lld",&n);
    for(ll i=1;i<=2*n;i++){
        int p;sf(p);
        if(index[p][0]==0)index[p][0]=i;
        else index[p][1]=i;
    }
    ll sum=index[1][0]+index[1][1]-2;
    for(int i=2;i<=n;i++){
        ll u=abs(index[i][0]-index[i-1][0])+abs(index[i][1]-index[i-1][1]);
        ll v=abs(index[i][0]-index[i-1][1])+abs(index[i][1]-index[i-1][0]);
        sum+=min(u,v);
    }
    printf("%lld\n",sum);
}
