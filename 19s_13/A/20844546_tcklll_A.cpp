#include <bits/stdc++.h>
#define ll long long
#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d",&a,&b)
#define MAXN 10005
#define INF 1000000000000000.
#define mod 998244353
using namespace std;
int main()
{
    int n;sf(n);
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        int p;sf(p);
        if(p>0)sum1++;
        if(p<0)sum2++;
    }
    int k=(n+1)/2;
    if(sum1>=k){
        printf("1\n");
    }
    else if(sum2>=k){
        printf("-1\n");
    }
    else{
        printf("0\n");
    }
}
