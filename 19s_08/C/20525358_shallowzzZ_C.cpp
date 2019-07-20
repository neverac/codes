#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll k,a,b,ans;
int main(){
    cin >> k >> a >> b;
    if(k<=a-1 || b<=a+2){
        ans=1+k;
    }
    else{
        k-=(a-1);
        ll p=1ll*k/2;
        ans =1ll*p*(b-a)+a+(k%2);
    }
    cout << ans << endl;
    return 0;
}
