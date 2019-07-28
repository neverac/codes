#include <bits/stdc++.h>
using namespace std;
int mmp[305][305];
int ans[305][305];
int maxx,cnt,n,u,v,w;
int main(){
    cin >> cnt;
    while(cnt--){
        cin >> n;
        memset(ans,0,sizeof(ans)); maxx=0;
        for(int i=1;i<=n*(n-1)/2;i++){
            cin >> u >> v >> w;
            mmp[u][v]=mmp[v][u]=w;
        }
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    ans[i][j]=max(ans[i][j],mmp[i][j]+mmp[j][k]+mmp[i][k]);
                }
                maxx=max(ans[i][j],maxx);
            }
        }
        cout << maxx << endl;
    }
    return 0;
}/////
