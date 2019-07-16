#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#define sf(n) scanf("%d",&n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define ll long long
#define MAXL 1000000
#define eps 1e-6
#define MAXV 10005
#define INF 1000000005
#define mod 1000000007
using namespace std;
ll prime[100005];
int check[1000005];
int tot=0;
void init(){
    memset(check,0,sizeof(check));
    for(ll i=2; i<MAXL; ++i)
    {
      if (!check[i])
      {
        prime[tot++] = i;
      }
      for(ll j=0;j<tot;++j)
      {
        if(i*prime[j]>MAXL)break;
        check[i*prime[j]]=1;
        if(i%prime[j]==0)break;
      }
    }
}
int main()
{
    init();
    //cout<<tot<<endl;
    ll n,b;
    scanf("%lld%lld",&n,&b);
    ll a[100],c[100];ll u=0;
    for(int i=0;i<tot;i++){
        if(b%prime[i]==0){
            //cout<<prime[i]<<endl;
            a[u]=prime[i];int p=0;
            while(b%prime[i]==0){
                p++;
                b/=prime[i];
            }
            c[u]=p;
            u++;
        }
        if(b==1)break;
    }
    if(b!=1){
        a[u]=b;c[u]=1;
        u++;
    }
    //cout<<u<<endl;
    ll mmin=1000000000000000000;
    for(int i=0;i<u;i++){
        ll sum=0,m=n;
        //cout<<m<<"  "<<a[i]<<endl;
        while(m>=a[i]){
            sum+=m/a[i];
            m/=a[i];
        }
        //cout<<sum<<"  "<<c[i]<<endl;
        mmin=min(mmin,sum/c[i]);
    }
    printf("%lld\n",mmin);
}
/*
1000000000000000000 1000000000000
*/
