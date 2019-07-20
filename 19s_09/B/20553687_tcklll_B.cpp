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
#define mod 998244353
using namespace std;
int main()
{
    ll n;scanf("%lld",&n);
    string x;cin>>x;
    if(x[0]==x[n-1]){
        ll p,q;bool flag=0;
        for(p=0;p<n;p++)
            if(x[p]!=x[0]){flag=1;break;}
        for(q=n-1;q>=0;q--)
            if(x[q]!=x[n-1])break;
        if(flag==0){
            printf("%lld\n",((n+1)*n/2)%mod);
        }
        else{
            printf("%lld\n",(p+1)*(n-q)%mod);
        }
    }
    else{
        ll p,q;
        for(p=0;p<n;p++)
            if(x[p]!=x[0])break;
        for(q=n-1;q>=0;q--)
            if(x[q]!=x[n-1])break;
        printf("%lld\n",(n-q+p)%mod);
    }
}
