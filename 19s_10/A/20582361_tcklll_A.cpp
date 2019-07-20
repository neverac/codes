#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#define sf(n) scanf("%d",&n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define ll long long
#define MAXL 1000000
#define eps 1e-6
#define MAXV 10005
#define INF 1000000005
#define mod 998244353
using namespace std;
int a[1005][1005];
int step[4][2]={-1,0,1,0,0,1,0,-1};
struct node{
    int x;int y;
    int sum;
    bool operator <(const node a)const{
        return sum>a.sum;
    }
};
int main()
{
    int n,m;
    sff(n,m);
    memset(a,-1,sizeof(a));
    priority_queue<node>q;
    for(int i=1;i<=n;i++){
        string x;cin>>x;
        for(int j=1;j<=m;j++){
            if(x[j-1]=='.'){a[i][j]=0;}//cout<<"???"<<i<<j<<endl;}
            else {
                a[i][j]==1;
                node er;
                er.x=i;er.y=j;
                er.sum=0;
                q.push(er);
            }
        }
        //cout<<a[1][2]<<endl;
    }
    node now;
    //cout<<a[1][2]<<endl;
    while(!q.empty()){
        now=q.top();
        //cout<<now.x<<now.y<<now.sum<<endl;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=now.x+step[i][0],yy=now.y+step[i][1];
            //cout<<xx<<yy<<a[xx][yy]<<"?"<<endl;
            if(a[xx][yy]==0){
                //cout<<xx<<"  "<<yy<<endl;
                node next;
                next.x=xx;next.y=yy;
                next.sum=now.sum+1;
                a[xx][yy]=1;
                q.push(next);
            }
        }
    }
    printf("%d\n",now.sum);
}
