#include<bits/stdc++.h>
using namespace std;
long long in[200005];
struct node{
    long long v,pos;
}tt[200005];
bool cmp(node a,node b) {
    return a.v<b.v;
}
int can[200005];
int main() {
    long long n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    long long cang=n-m*k;
    long long sum=0;
    for(int i=0;i<n;i++) {
        scanf("%lld",in+i);
        tt[i].v=in[i];
        tt[i].pos=i;
        can[i]=1;
        sum+=in[i];
    }
    sort(tt,tt+n,cmp);
    for(int i=0;i<cang;i++) {
        can[tt[i].pos]=0;
        sum-=tt[i].v;
    }
    printf("%lld\n",sum);
    for(int i=0;i<n;i++) {
        int cn=0;
        bool falg=false;
        for(int j=i;j<n;j++) {
            if(can[j]&&cn<m) {
                cn++;
            }
            else if(can[j]&&cn==m) {
                i=j-1;
                printf("%d ",j);
                break;
            }
            if(j==n-1) {
                falg=true;
            }
        }
        if(falg) break;
    }
    puts("");
}
