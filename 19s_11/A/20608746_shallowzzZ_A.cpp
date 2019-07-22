#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int maxn  = 1e5+5;

int n,a[maxn];
ll sum,ans;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++){
        ans+=sum*a[i];
        sum-=a[i];
        ans+=sum*a[i];
    }
    cout << ans << endl;
    return 0;
}
