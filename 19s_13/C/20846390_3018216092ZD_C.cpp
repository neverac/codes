#include <iostream>
#include <queue>
using namespace std;
struct node{
    int x;
    int y;
};
char maze[100][100];
bool visied[100][100];
int sx,sy,fx,fy,n,m;
int ans = 99999999;
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
int cnt = 0;
node path[2600];
void bfs(int x,int y){
    node temp;
    temp.x = x;
    temp.y = y;
    queue<node> Q;
    Q.push(temp);
    visied[x][y] = 1;
    while(!Q.empty()){
        node top = Q.front();
        Q.pop();
        for(int i = 0;i < cnt;i++){
            int dis = (path[i].x - top.x) * (path[i].x - top.x) + (path[i].y - top.y) * (path[i].y - top.y);
            if(dis < ans) ans = dis;
        }
        for(int i = 0;i < 4;i++){
            int newx = top.x + xx[i];
            int newy = top.y + yy[i];
            if(newx < 0 || newy < 0 || newx >= n || newy >= n) continue;
            if(maze[newx][newy] == '1' || visied[newx][newy]) continue;
            visied[newx][newy] = 1;
            temp.x = newx;
            temp.y = newy;
            Q.push(temp);
        }

    }
}
void bfs2(int x,int y){
    node temp;
    temp.x = x;
    temp.y = y;
    queue<node> Q;
    Q.push(temp);
    visied[x][y] = 1;
    while(!Q.empty()){
        node top = Q.front();
        Q.pop();
        path[cnt].x = top.x;
        path[cnt++].y = top.y;
        for(int i = 0;i < 4;i++){
            int newx = top.x + xx[i];
            int newy = top.y + yy[i];
            if(newx < 0 || newy < 0 || newx >= n || newy >= n) continue;
            if(maze[newx][newy] == '1' || visied[newx][newy]) continue;
            visied[newx][newy] = 1;
            temp.x = newx;
            temp.y = newy;
            Q.push(temp);
        }

    }
}
int main()
{
    cin >> n ;
    cin >> sx >> sy >> fx >> fy;
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        for(int j = 0;j < n;j++){
            maze[i][j] = s[j];
        }
    }
    sx--;
    sy--;
    fx--;
    fy--;
    bfs2(fx,fy);
//    cout << cnt << endl;
//    for(int i = 0;i < cnt;i++){
//        cout << path[i].x << " " << path[i].y << endl;
//    }
    bfs(sx,sy);

    cout << ans << endl;
    return 0;
}