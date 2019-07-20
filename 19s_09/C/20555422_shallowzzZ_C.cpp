#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t,ang,ans;
int main(){
    cin >> t;
    while(t--){
        cin >> ang;
        if(ang==179){
            cout << 360 << endl;
            continue;
        }
        int ans=3;
        for(ans;ans<=180;ans++){
            if((ans*ang)%180==0 && 180*(ans-2)>=ans*ang) break;
        }
        cout << ans << endl;
    }
    return 0;
}
