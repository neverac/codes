#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
char in[200005];
int main() {
    long long n; scanf("%lld",&n);
    scanf("%s",in);
    bool same=true;
    for(int i=0;i<n;i++) {
        if(in[i]!=in[0]) {
            same=false;
        }
    }
    if(same) {
        printf("%lld\n",(n+1)*n/2%mod);
        return 0;
    }
    if(n==2) {
        puts("3");
        return 0;
    }
    long long tou=0,wei=0;
    for(int i=0;i<n;i++) {
        if(in[i]==in[0]) {
            tou++;
        }
        else {
            break;
        }
    }
    for(int i=n-1;i>=0;i--) {
        if(in[i]==in[n-1]) {
            wei++;
        }
        else {
            break;
        }
    }
    if(in[0]==in[n-1]) {
        long long ans=0;
        ans+=tou+wei+1;
        ans+=(long long)tou*wei;
        ans%=mod;
        printf("%lld\n",ans);
    }
    else {
        printf("%d\n",tou+wei+1);
    }
}
