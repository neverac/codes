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
/*
int a[500005];
int k[6]={4,8,15,16,23,42};
*/
int main()
{
    ll k,a,b;scanf("%lld%lld%lld",&k,&a,&b);
    if(b==1){
        printf("%lld\n",1+k);
        return 0;
    }
    if(b-a<=2){
        printf("%lld\n",1+k);
        return 0;
    }
    if(k<=a-1){
        printf("%lld\n",1+k);
        return 0;
    }
    k-=(a-1);
    if(k%2==0){
        printf("%lld\n",a+(k/2)*(b-a));
    }
    else{
        printf("%lld\n",a+(k/2)*(b-a)+1);
    }


}
