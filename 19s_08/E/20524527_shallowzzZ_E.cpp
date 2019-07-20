#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t,n;
ll a[105];
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        ll ans=0,cnt1=0,cnt2=0,x;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i]%3==0) ans++;
            if(a[i]%3==1) cnt1++;
            if(a[i]%3==2) cnt2++;
        }
        if(cnt1>cnt2) ans+=cnt2+(cnt1-cnt2)/3;
        else ans+=cnt1+(cnt2-cnt1)/3;
        cout << ans << endl;
    }
}
