//#include <bits/stdc++.h>
//#define MOD (int)(1e9+7)
//using namespace std;
//int fac[100005];
//
//int qPow(int x,int y){
//    int ans=1,sta=x;
//    while(y){
//        if(y&1)ans=1ll*ans*sta%MOD;
//        sta=1ll*sta*sta%MOD,y>>=1;
//    }
//    return ans;
//}
//int inv(int x){
//    return qPow(x,MOD-2);
//}
//
//int C(int x,int y){
//    int a=fac[x],b=fac[y],c=fac[x-y];
//    return 1ll*x*inv(b)%MOD*inv(c)%MOD;
//}
//int main() {
//    ios::sync_with_stdio(false);
//    cin >> n;
//    fac[0]=1;
//    for(int i=1;i<=100000;i++)fac[i]=1ll*i*fac[i-1]%MOD;
//    int t;
//    cin>>t;
//    while(t--){
//
//
//
//
//    }
//
//}
#include <bits/stdc++.h>

using namespace std;
int op[100005], n;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)cin >> op[i];
        cout << (int)sqrt(abs(op[1] - op[n])) <<endl;
    }
    return 0;
}
