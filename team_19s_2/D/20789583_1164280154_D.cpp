#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <queue>
#define ll long long
#define N 210
using namespace std;
const int INF = 0x3f3f3f3f;
int n,e;
int rec[N];
int map[N][N];
int main(){
    int i,j,k,x,y;
    while (scanf("%d",&n),n)
    {
        memset(map,0x3f,sizeof(map));
        for(i=0;i<n;i++){
            map[i][i] = 0;
        }
        memset(rec,0,sizeof(rec));
        scanf("%d",&e);
        for(i=0;i<e;i++){
            scanf("%d%d",&x,&y);
            map[x][y] = map[y][x] = 1;
        }

        for(k=0;k<n;k++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    map[i][j] = min(map[i][j],map[i][k]+ map[k][j]);
                }
            }
        }

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(map[i][j] != INF){
                    rec[map[i][j]]++;
                }
            }
        }

        for(i=1;i<=n;i++){
            if(rec[i] != 0){
                printf("%d %d\n",i,rec[i]);
            }
        }
    }
    return 0;
}