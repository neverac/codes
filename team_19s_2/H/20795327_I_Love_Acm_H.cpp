#include <bits/stdc++.h>
using namespace std;
long long nn;
long long a[300],s[300],sum[300];
long long prime[1000000];
bool used[2000100]; 
typedef long long ll;
#define maxn 2000000
int main(){
    ll T;
    cin>>T;
    ll k=0;
    ll n=maxn;
    memset(used,0,sizeof(used));
    for (ll i=2;i<=n;i++){
        if (!used[i]){
            prime[k]=i;
            k++;
        }
        for (ll j=0;j<=k-1;j++){
            if (i*prime[j]>maxn) break;else used[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
    k--;
    while (T--){
        cin>>nn;
        memset(a,0,sizeof a);
        memset(s,0,sizeof a);
        memset(sum,0,sizeof a);
        ll cnt=0;
        ll i=0,p=0;
        while (nn!=1&&i<=k){
            while (nn%prime[i]!=0) {
                i++;
                if (i>k) break;
            }
            if (i>k) break;
            while (nn%prime[i]==0){
                p++;nn/=prime[i];
            }
            a[++cnt]=p;p=0; 
        }
        if (i>k) {
            a[++cnt]=1;
        }
        s[1]=a[1];
        sum[1]=a[1]+1;
        for (ll i=2;i<=cnt;i++){
            s[i]=1ll*s[i-1]*(a[i]+1)+1ll*sum[i-1]*a[i];
            sum[i]=1ll*sum[i-1]*(a[i]+1);
        }
        //cout<<cnt<<endl;
        cout<<s[cnt]<<endl;
    }
    return 0;
}