#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;

char gra[55][55];
int dis1[55][55],dis2[55][55],n;
int d[4][2]={1,0,0,1,-1,0,0,-1};
struct node{int x,y;};
bool check(int x,int y){
    if(x<1||x>n||y<1||y>n)return false;
    if(gra[x][y]=='1')return false;
    return true;
}
int main(){
    node b,e;
    cin>>n;
    cin>>b.x>>b.y>>e.x>>e.y;
    for(int i=1;i<=n;i++){
        scanf("%s",gra[i]+1);
    }
    memset(dis1,0x3f,sizeof(dis1));
    memset(dis2,0x3f,sizeof(dis2));
    queue<node>q1,q2;;
    q1.push(b),q2.push(e);
    dis1[b.x][b.y]=dis2[e.x][e.y]=0;
    while(!q1.empty()){
        node t=q1.front();
        q1.pop();
        for(int i=0;i<4;i++){
            node nt;
            nt.x=t.x+d[i][0];
            nt.y=t.y+d[i][1];
            if(check(nt.x,nt.y)&&dis1[t.x][t.y]+1<dis1[nt.x][nt.y]){
                dis1[nt.x][nt.y]=dis1[t.x][t.y]+1;
                q1.push(nt);
            }
        }
    }
    while(!q2.empty()){
        node t=q2.front();
        q2.pop();
        for(int i=0;i<4;i++){
            node nt;
            nt.x=t.x+d[i][0];
            nt.y=t.y+d[i][1];
            //cout<<nt.x<<" "<<nt.y<<endl;
            if(check(nt.x,nt.y)&&dis2[t.x][t.y]+1<dis2[nt.x][nt.y]){
                dis2[nt.x][nt.y]=dis2[t.x][t.y]+1;
                q2.push(nt);
            }
        }
    }
    int ans=dis1[0][0];
    if(dis1[e.x][e.y]!=dis1[0][0]){
        cout<<0<<endl;return 0;
    }else{

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis1[i][j]==dis1[0][0])continue;
                for(int k=1;k<=n;k++){
                    for(int l=1;l<=n;l++){
                        if(dis2[k][l]==dis2[0][0])continue;
                        else ans=min(ans,(k-i)*(k-i)+(l-j)*(l-j));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
