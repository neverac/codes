#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;
struct node {
    int x , y ;
} ;
const int maxn = 2505 ;
int ma[55][55] ;
int visit[55][55] ;
node s[maxn] ;
int ss = 0 ;
node en[maxn] ;
int ens = 0 ;
int n ;

node mov[4] ;

void set_mov(){
    mov[0].x = 1 , mov[0].y = 0 ;
    mov[1].x = 0 , mov[1].y = 1 ;
    mov[2].x = -1 , mov[2].y = 0 ;
    mov[3].x = 0 , mov[3].y = -1 ;
}

void bfs( int sx , int sy , int endx , int endy, int flog ) {
    memset(visit,0,sizeof(visit)) ;
    queue<node> q ;
    node temp , temp1 ;
    temp.x = sx ; temp.y = sy ;
    visit[sx][sy] = 1 ;
    q.push(temp) ;
    while(!q.empty()) {
        temp = q.front() ;
        q.pop() ;
        if (flog) s[ss++] = temp ;
        else en[ens++] = temp ;
        for(int i = 0 ; i< 4 ; i++) {
            int xx = temp.x + mov[i].x ;
            int yy = temp.y + mov[i].y ;
            if (!visit[xx][yy] && ma[xx][yy]==0 && xx>0 && xx<=n && yy>0 && yy<=n) {
                temp1.x = xx ,temp1.y = yy ;
                visit[xx][yy] = 1 ;
                q.push(temp1) ;
            }
        }
    }
}


int main()
{
    cin >> n ;
    int x1 , y1 , x2 , y2 ;
    cin >> x1 >> y1 ;
    cin >> x2 >> y2 ;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j<= n ; j++) {
            char ch ;
            cin >> ch ;
            ma[i][j] = ch-'0' ;
        }
    }
    set_mov() ;
    bfs(x1,y1,x2,y2,1) ;
    bfs(x2,y2,x1,y1,0) ;
    int ans = 1e9 ;
    for (int i = 0 ; i <ss ; i++) {
        for (int j = 0 ; j < ens ; j++) {
            int temp = (s[i].x - en[j].x) * (s[i].x - en[j].x) + (s[i].y - en[j].y) * (s[i].y - en[j].y) ;
            ans = min(ans , temp) ;
        }
    }
    cout << ans << endl ;
}