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
struct node{
    ll x;int index;
    bool operator<(const node a)const{
        return x>a.x;
    }
}a[200005];
bool y[200005]={0};
int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        ll p;scanf("%lld",&p);
        a[i].x=p,a[i].index=i;
    }
    sort(a,a+n);
    ll sum=0ll;
    for(int i=0;i<m*k;i++){
        //cout<<sum<<endl;
        sum+=a[i].x;
        y[a[i].index]=1;
        //printf("%lld\n",sum);
    }

    printf("%lld\n",sum);
    int er=0,o=0;
    for(int i=0;i<n,o<k-1;i++){
        if(er==m){printf("%d ",i);o++;er=0;}
        if(y[i])er++;
    }
    printf("\n");
}

