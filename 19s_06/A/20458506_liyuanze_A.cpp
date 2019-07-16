#include<bits/stdc++.h>
using namespace std;
struct node{
    long long v, num;
}yin[10000005];
long long cn=0;
long long truenum[10000005];
int main() {
    long long n,b;
    scanf("%lld%lld",&n,&b);
    yin[0].num=0;
    for(long long i=2;b!=1;i++) {
        bool falg=false;
        while(b%i==0) {
            falg=true;
            yin[cn].v=i;
            yin[cn].num++;
            b/=i;
        }
        if(i>(long long)sqrt(b)&&b!=1) {
            if(falg) cn++;
            yin[cn].v=b;
            yin[cn].num=1;
            cn++;
            break;
        }
        if(falg) {
            cn++;
            yin[cn].num=0;
        }
    }

    /*for(int i=0;i<cn;i++) {
        cout<<yin[i].v<<"*"<<yin[i].num<<endl;
    }*/
    memset(truenum,0,sizeof(truenum));
    for(long long i=0;i<cn;i++) {
        long long temp=yin[i].v;
        //cout<<n<<"^"<<temp<<endl;
        while(n/temp!=0) {
            truenum[i]+=n/temp;
            if(temp>1000000000000000000/yin[i].v) break;
            temp*=yin[i].v;
        }
    }
    /*for(int i=0;i<cn;i++) {
        cout<<truenum[i]<<"&"<<endl;
    }*/
    long long ans=1000000000000000000;
    for(long long i=0;i<cn;i++) {
        ans=min(ans,truenum[i]/yin[i].num);
    }
    printf("%lld\n",ans);
}
