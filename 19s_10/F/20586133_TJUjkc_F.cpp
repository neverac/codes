#include<iostream>
#include<memory.h>
using namespace std;

int n,m,s,t;
int ds[1005];
int dt[1005];
int w[1005][1005];
int v[1005];//vis

int main(){
    memset(w,0,sizeof(w));
    //memset(ds,0,sizeof(ds));
    //memset(dt,0,sizeof(dt));
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        w[a][b]=1;
        w[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        ds[i]=10000;
        dt[i]=10000;
    }
    ds[s]=0;
    dt[t]=0;
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++){
        int x,dis = 10000;
        for(int y=1;y<=n;y++) if(!v[y]&&ds[y]<=dis) dis=ds[x=y];
        v[x]=1;
        for(int y=1;y<=n;y++) if(w[x][y]==1) ds[y]=min(ds[y],ds[x]+1);
    }
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++){
        int x,dis = 10000;
        for(int y=1;y<=n;y++) if(!v[y]&&dt[y]<=dis) dis=dt[x=y];
        v[x]=1;
        for(int y=1;y<=n;y++) if(w[x][y]==1) dt[y]=min(dt[y],dt[x]+1);
    }
    //for(int i=1;i<=n;i++) cout<<ds[i]<<" "<<endl;
    //for(int i=1;i<=n;i++) cout<<dt[i]<<" "<<endl;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(w[i][j]==1) continue;
            if(dt[s]<=(ds[i]+dt[j]+1)&&dt[s]<=(ds[j]+dt[i]+1)){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


