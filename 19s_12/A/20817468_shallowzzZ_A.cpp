#include <bits/stdc++.h>

using namespace std;

bool vis[20], use[10000005];
int p,q;
int main(){
    cin >> p >> q;
    use[p]=true;
    while(p){
        p*=10;
        if(use[p]) break;
        use[p]=true;
        vis[p/q]=true;
        p%=q;
    }
    for(int i=0;i<=10;i++){
        if(vis[i]) cout << i;
    }
    return 0;
}
