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
    int p,q;sff(p,q);
    set<int>s;
    bool f[10]={0};
    while(1){
        s.insert(p);
        int k=p*10/q;
        f[k]=1;
        p=(p*10)%q;
        if(s.count(p)==1)break;
    }
    for(int i=0;i<=9;i++)
        if(f[i])printf("%d",i);
    printf("\n");
}
