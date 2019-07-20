#include<bits/stdc++.h>

using namespace std;

const int maxn = 10000;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n,m,ans;
char s[1111][1111];

struct node
{
    int x,y,step;
};
queue<node> temp;

void bfs()
{
    while(!temp.empty())
    {
        node now = temp.front();
        temp.pop();

        ans = max(ans, now.step);

        for(int i = 0; i < 4; i++)
        {
            node nex = node{now.x + dx[i], now.y + dy[i], now.step + 1};

            if(s[nex.x][nex.y] == '.')
            {
                s[nex.x][nex.y]= '#';
                temp.push(nex);
            }
        }
    }
}

int main()
{
    cin>>n>>m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin>>s[i][j];

            if(s[i][j] == '#')
                temp.push(node{i, j, 0});
        }

    bfs();

    cout<<ans<<endl;

    return 0;
}
