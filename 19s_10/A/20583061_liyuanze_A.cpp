#include<bits/stdc++.h>
using namespace std;
char Map[1005][1005];
int n,m,turn[4][2]={1,0,0,1,-1,0,0,-1};
void judge(int _x,int _y) {
    if(_x<0||_x>=n) return;
    if(_y<0||_y>=m) return;
    if(Map[_x][_y]=='.') Map[_x][_y]='*';
}
struct node {
    int a,b;
    node (int x,int y) {
        a=x,b=y;
    }
    node(){}
}point[1005];
int dis(int a,int b,int c,int d) {
    return abs(a-c)+abs(b-d);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%s",Map[i]);
    }
    int cn=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(Map[i][j]=='#') {
                if(cn<=1005) {
                    point[cn++]=node(i,j);
                }
                else {
                    break;
                }
            }
        }
    }
    if(cn<1000) {
        int ans=0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int Min=0x3f3f3f3f;
                if(Map[i][j]=='.') {
                    for(int k=0;k<cn;k++) {
                        Min=min(Min,dis(i,j,point[k].a,point[k].b));
                    }
                    ans=max(ans,Min);
                }
            }
        }
        printf("%d\n",ans);
        return 0;
    }
    int ans=0;
    while(true) {
        bool falg=false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(Map[i][j]=='#') {
                    for(int k=0;k<4;k++) {
                        int _x=i+turn[k][0];
                        int _y=j+turn[k][1];
                        judge(_x,_y);
                    }
                }
                else {
                    falg=true;
                }
            }
        }

        if(!falg) break;
        ans++;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(Map[i][j]=='*') Map[i][j]='#';
            }
        }
    }
    printf("%d\n",ans);
}
