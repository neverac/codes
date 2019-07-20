#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;int stop;
int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int black;
int map[1002][1002];
bool isfull[1002][1002];
struct Node
{
    int x,y;
    int step;
    Node(int a,int b,int c){
        x=a,y=b,step = c;
    }
};

int check(int x,int y,int k){
    int sum = 0;
    for(int i=0;i<4;i++){
        if(map[x+dx[i]][y+dy[i]] == 999999){
            map[x+dx[i]][y+dy[i]] = k;
            sum++;
        }
    }
    return sum;
}

int main(){
    int i,j,k,x;
    char ch;
    queue<Node>q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>ch;
            if(ch == '#'){
                map[i][j] = 0;
                black++;
                q.push(Node(i,j,0));
            }else{
                map[i][j] = 999999;
            }
        }
    }
    if(black == n*m){
        printf("0\n");
        return 0;
    }
    
    int ans = 0;
    while (!q.empty())
    {
        Node u = q.front();q.pop();
        for(k=0;k<4;k++){
            if(map[u.x + dx[k]][u.y+dy[k]] == 999999){
                map[u.x + dx[k]][u.y+dy[k]] = 0;
                q.push(Node(u.x + dx[k],u.y+dy[k],u.step+1));
                ans = max(ans,u.step+1);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}