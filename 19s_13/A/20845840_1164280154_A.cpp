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
const int MAXN=105;
int T,n,m,k,numf,numz,f,fu,x,f1;
int a[MAXN];
int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        if (a[i]<0) {numf++;}
        if (a[i]>0) {numz++;}
    }
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++){
        if (a[i]==0 && f==0) {fu=i-1; f=1;}
        if (a[i]>0 && f1==0) {k=i; f1=1;}
    }

    x=ceil(n*1.0/2*1.0);
    if (numz>=x) {
        printf("1\n");
        return 0;
    }
    if (numf>=x){
        printf("-1\n");
        return 0;
    }
    printf("0\n");
    return 0;
}