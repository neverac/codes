#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn  = 1e6+5;
ll a[maxn];
int t,n;
void solve(){
    a[1]=1;a[2]=5;a[3]=13;
    for(int i=4;i<=1000002;i++){
        if(i%2==0) a[i]=3*a[i-1]+a[i-3]-3*a[i-2]+2;
        else a[i]=3*a[i-1]+a[i-3]-3*a[i-2]+1;
    }
    return ;
}
int main(){
    cin >> t;
    solve();
    while(t--){
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}
