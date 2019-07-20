#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    int x,y,t;
};
int n,m,ans=0,cnt=0;
char gra[1005][1005];
int d[4][2]={1,0,0,1,-1,0,0,-1};
bool can(int x,int y){
    if(x<0||x>=n||y<0||y>=m)return false;
    if(gra[x][y]=='#')return false;
    return true;
}
int main(){

    cin>>n>>m;
    for(int i=0;i<n;i++)
        scanf("%s",gra[i]);
    queue<node> q;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        if(gra[i][j]=='#'){
            node t;
            t.x=i;
            t.y=j;
            t.t=0;
            q.push(t);
            cnt++;
        }
    }
    while(!q.empty()){
        node t=q.front();
        q.pop();
        if(cnt==n*m)break;
        for(int i=0;i<4;i++){
            node nn;
            nn.x=t.x+d[i][0];
            nn.y=t.y+d[i][1];
            nn.t=t.t+1;
            if(can(nn.x,nn.y)){
                gra[nn.x][nn.y]='#';
                ans=max(ans,nn.t);
                cnt++;
                q.push(nn);
            }
        }
    }
    cout<<ans<<endl;
}
