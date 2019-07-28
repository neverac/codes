#include <bits/stdc++.h>
#define ll long long
#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d",&a,&b)
#define MAXN 10005
#define INF 1000000000000000.
#define mod 998244353
using namespace std;
int step[4][2]={0,1,0,-1,1,0,-1,0};
struct node{
    int x,y;
    bool operator==(const node a)const{
        return x==a.x&&y==a.y;
    }
};
node s1[2600],s2[2600];
int cnt1=0,cnt2=0;
int a[55][55];
bool f1[55][55]={0};
bool f2[55][55]={0};
int dis(node a,node b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void dfs1(node er){
    s1[cnt1++]=er;
    int x=er.x,y=er.y;
    for(int i=0;i<4;i++){
        int xx=x+step[i][0],yy=y+step[i][1];
        if(a[xx][yy]==0&&f1[xx][yy]==0){
            f1[xx][yy]=1;
            node p;p.x=xx;p.y=yy;
            dfs1(p);
        }
    }
    return;
}
void dfs2(node er){
    s2[cnt2++]=er;
    int x=er.x,y=er.y;
    for(int i=0;i<4;i++){
        int xx=x+step[i][0],yy=y+step[i][1];
        if(a[xx][yy]==0&&f2[xx][yy]==0){
            f2[xx][yy]=1;
            node p;p.x=xx;p.y=yy;
            dfs2(p);
        }
    }
    return;
}
int main()
{
    int n;sf(n);
    int r1,c1;sff(r1,c1);
    int r2,c2;sff(r2,c2);
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        string x;cin>>x;
        for(int j=1;j<=n;j++){
            a[i][j]=x[j-1]-'0';
        }
    }
    node n1;n1.x=r1;n1.y=c1;
    node n2;n2.x=r2;n2.y=c2;
    f1[r1][c1]=1;f2[r2][c2]=1;
    dfs1(n1);dfs2(n2);
    for(int i=0;i<cnt1;i++){
        if(s1[i]==n2){printf("0\n");return 0;}
    }
    int mmin=1000000000;
    for(int i=0;i<cnt1;i++){
        for(int j=0;j<cnt2;j++){
            mmin=min(mmin,dis(s1[i],s2[j]));
        }
    }
    printf("%d\n",mmin);
}
