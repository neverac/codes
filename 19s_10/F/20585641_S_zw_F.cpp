#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
//#include <map>
using namespace std;int stop;
int n,m,s,t;
int map[1001][1001];
int diss[1001];
bool ischs[1001];
int dist[1001];
bool ischt[1001];
int main(){
    int i,j,k,x,y;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    memset(map,0x3f,sizeof(map));
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        map[x][y] = map[y][x] = 1;
    }

    for(i=1;i<=n;i++){
        map[i][i] = 0;
        diss[i] = map[s][i];
        dist[i] = map[t][i];
    }
    ischs[s] = ischt[t] = 1;
    
    for(i=1;i<=n-1;i++){
        int tmp = 9999,k = -1;
        for(j=1;j<=n;j++){
            if(diss[j] < tmp && !ischs[j]){
                tmp = diss[j];k = j;
            }
        }
        ischs[k] = 1;
        for(j=1;j<=n;j++){
            if(map[j][k] + diss[k] < diss[j] && !ischs[j]){
                diss[j] = map[j][k] + diss[k];
            }
        }
    }

    for(i=1;i<=n-1;i++){
        int tmp = 9999,k = -1;
        for(j=1;j<=n;j++){
            if(dist[j] < tmp && !ischt[j]){
                tmp = dist[j];k = j;
            }
        }
        ischt[k] = 1;
        for(j=1;j<=n;j++){
            if(map[j][k] + dist[k] < dist[j] && !ischt[j]){
                dist[j] = map[j][k] + dist[k];
            }
        }
    }

    int dis = diss[t];
    int ans = 0;
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(map[i][j] == 1){continue;}
            if(s == i){//包含中点是j
                if(1+dist[j] >= dis){
                    ans++;continue;
                }
            }
            if(s == j){
                if(1+dist[i] >= dis){
                    ans++;continue;
                }
            }
            if(t == j){
                if(1+diss[i] >= dis){
                    ans++;continue;
                }
            }
            if(t == i){
                if(1+diss[j] >= dis){
                    ans++;continue;
                }
            }
            if(diss[i] + 1 + dist[j] >= dis  && diss[j] + 1 + dist[i] >= dis){
                //printf("%d--%d--%d\n",i,j,min(map[s][i] + 1 + map[j][t],map[s][j] + 1 + map[i][t]));
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}