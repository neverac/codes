#include<iostream>
#include<queue>
#define ll long long
using namespace std;

int pos[100005][2];
ll ans,n;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int x;
    for(int i=1;i<=2*n;i++){
        cin >> x;
        if(pos[x][0]) pos[x][1]=i;
        else pos[x][0]=i;
    }
    ans+=pos[1][0]-1;
    ans+=pos[1][1]-1;
    for(int i=2;i<=n;i++){
        ans+=abs(pos[i][0]-pos[i-1][0]);
        ans+=abs(pos[i][1]-pos[i-1][1]);
    }
    cout << ans << endl;
    return 0;
}



