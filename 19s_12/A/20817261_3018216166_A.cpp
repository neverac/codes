#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int n, m;
bool vis[100];
int cnt[100];
int main(){
    while(cin >> n >> m){
        double x;
        memset(vis, false, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        int T = 1000;
        while(T--){
            n *= 10;
            int t = n / m;
            vis[t] = true;
            n -= m * t;
        }
        for(int i = 0; i < 10; i++){
            if(vis[i]) printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}
