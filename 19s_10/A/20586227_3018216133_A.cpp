#include <iostream>
#include <queue>

using namespace std;

char mp[1002][1002];
int n,m;
string str;
struct node{
    int x;
    int y;
    int step;
};
int tox[] = {-1,0,0,1};
int toy[] = {0,-1,1,0};
bool vis[1002][1002];
int cnt,cnt2,cnt3;

int main()
{
    queue<node> q;
    node s;
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> str;
        for(int j = 0;j < m;j++)
        {
            mp[i][j] = str[j];
            if(str[j]  == '.')cnt++;
            else{s.x = i,s.y = j;
                q.push(s);
                cnt2++;
            }
        }
    }
    node no;
    int ans = 0;
    while(cnt)
    {
        ans++;
        while(cnt2--)
        {
            no = q.front();
            q.pop();
            for(int i = 0;i < 4;i++)
            {
                int x = no.x + tox[i];
                int y = no.y + toy[i];
                if(x>=0&&y>=0&&x<n&&y<m&&mp[x][y] == '.' && vis[x][y] == 0){
                    cnt--;
                    vis[x][y] = 1;
                    s.x = x;
                    s.y = y;
                    q.push(s);
                    cnt3++;
                }
            }
        }
        cnt2 = cnt3;
        cnt3 = 0;
    }
    cout << ans << endl;
    return 0;
}
