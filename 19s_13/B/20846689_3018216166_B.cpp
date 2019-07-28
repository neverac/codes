#include <bits/stdc++.h>
#define maxn 500005
#define INF 0x3f3f3f3f
#define ll long long
#define R register
using namespace std;
ll n;
ll a[maxn];
vector<ll> pos[maxn];

int main(){
    scanf("%d", &n);
    for(ll i = 1; i <= 2 * n; i++){
        scanf("%d", &a[i]);
        pos[a[i]].push_back(i);
    }
    ll ans = 0;
    ll pos1 = 1, pos2 = 1;
    for(ll i = 1; i <= n; i++){
        ll a1 = abs(pos1 - pos[i][1]) + abs(pos2 - pos[i][0]);
        ll a2 = abs(pos1 - pos[i][0]) + abs(pos2 - pos[i][1]);
        if(a1 <= a2){
            ans += a1;
            pos1 = pos[i][1];
            pos2 = pos[i][0];
        }
        else{
            ans += a2;
            pos1 = pos[i][0];
            pos2 = pos[i][1];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
