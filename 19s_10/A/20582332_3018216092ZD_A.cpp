#include <iostream>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
using namespace std;
struct node{
    int x;
    int y;
    int step;
};
int xx[4] = {0,1,0,-1};
int yy[4] = {1,0,-1,0};
int n,m;
char maze[1005][1005];
bool visited[1005][1005];
queue<node> Q;
int bfs(){
    node top;
    while(!Q.empty()){
        top = Q.front();
        Q.pop();
        //cout << top.x << " " << top.y << " " << top.step << endl;
        for(int i = 0;i < 4;i++){
            int newx = top.x + xx[i];
            int newy = top.y + yy[i];
            if(newx < 0 || newy < 0 || newx >= n || newy >= m) continue;
            if(visited[newx][newy] || maze[newx][newy] == '#') continue;
            node temp;
            visited[newx][newy] = 1;
            temp.x = newx;
            temp.y = newy;
            temp.step = top.step + 1;
            Q.push(temp);
        }
    }
    return top.step;
}
int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> maze[i][j];
            if(maze[i][j] == '#'){
                node t;
                t.x = i;
                t.y = j;
                t.step = 0;
                Q.push(t);
            }
        }
    }
    int ans = bfs();
    cout << ans << endl;

    return 0;
}