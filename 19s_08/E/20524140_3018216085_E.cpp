#include<bits/stdc++.h>
#define  MAX 100005
#define  MOD 1000000007
#define ll long long
using namespace std;

int cnt[4];
int main() {
    ll t,n,a;
    cin>>t;
    while(t--){
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        for(ll i=1;i<=n;i++){
            cin>>a;
            cnt[a%3]++;
        }
        int ans=cnt[0];
        if(cnt[1]>cnt[2]){
            ans+=cnt[2];
            cnt[1]-=cnt[2];
            ans+=cnt[1]/3;
        }else {
            ans+=cnt[1];
            cnt[2]-=cnt[1];
            ans+=cnt[2]/3;
        }
        cout<<ans<<endl;
    }
}
