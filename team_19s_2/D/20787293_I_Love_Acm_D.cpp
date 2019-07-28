#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;

int INF=10000;

int n,m;
int d[205][205];
int ans[300];

int main(){
    while(cin>>n){
        if(n==0) break;
        cin>>m;
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) d[i][j]=0;
                else d[i][j]=INF;
            }
        }
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            d[x][y]=1;
            d[y][x]=1;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                    d[j][i]=d[i][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans[d[i][j]]+=2;
            }
        }
        for(int i=1;i<n;i++){
            if(ans[i]!=0){
                cout<<i<<" "<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
