#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;
typedef long long ll;
const int MAXN=100001;
const int N=200001;
int a[N];
struct q{
    int l=0;
    int r=0;
}cake[MAXN];
int n;
int main(){
    scanf("%d",&n);
    for (int i=1; i<=n*2; i++){
        scanf("%d",&a[i]);
        if (cake[a[i]].l==0) cake[a[i]].l=i;
        else cake[a[i]].r=i;
    }
    ll distance=0;
    int current1=cake[1].l;
    int current2=cake[1].r;
    distance+=current1+current2-2;
    for (int i=1; i<=n; i++){
        int d1=abs(current1-cake[i].l)+abs(current2-cake[i].r);
        int d2=abs(current1-cake[i].r)+abs(current2-cake[i].l);
        if (d1<d2){
        distance+=d1;
        current1=cake[i].l;
        current2=cake[i].r;
        }
        else {
            distance+=d2;
            current1=cake[i].r;
            current2=cake[i].l;
        }
    }
    printf("%lld\n",distance);
    return 0;
}