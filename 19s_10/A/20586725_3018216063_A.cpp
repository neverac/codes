#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int maxx=0;
char a[1010][1010];
int vis[1010][1010];
int h,w;
struct node
{
    int x,y,cnt;
    char c;

};
bool jud()
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(a[i][j]=='.')
                return false;
        }
    }
    return true;
}
void bfs()
{
    queue<node> q;

    memset(vis,0,sizeof(vis));
    while(jud()==false)
    {

        for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(a[i][j]=='#')
            {
                vis[i][j]=1;
                node b;
                b.c=a[i][j]; b.x=i; b.y=j;b.cnt=0;
                q.push(b);

            }
        }
    }
        while(q.empty()==false)
        {

            node d=q.front();//d.cnt++;
            q.pop();
            //d.cnt++;
            maxx=max(maxx,d.cnt);
            if(d.x+1<h&&vis[1+d.x][d.y]==0&&a[1+d.x][d.y]=='.')
            {
                a[1+d.x][d.y]='#';//cout<<"a";
                node e;e.c='#';e.cnt=d.cnt+1;e.x=1+d.x;e.y=d.y;
                q.push(e);
            }
            if(d.x-1>=0&&vis[d.x-1][d.y]==0&&a[d.x-1][d.y]=='.')
            {
                a[d.x-1][d.y]='#';
                node e;e.c='#';e.cnt=d.cnt+1;e.x=d.x-1;e.y=d.y;
                q.push(e);
            }
            if(d.y+1<w&&vis[d.x][d.y+1]==0&&a[d.x][d.y+1]=='.')
            {
                a[d.x][d.y+1]='#';
                node e;e.c='#';e.cnt=d.cnt+1;e.x=d.x;e.y=d.y+1;
                q.push(e);
            }
            if(d.y-1>=0&&vis[d.x][d.y-1]==0&&a[d.x][d.y-1]=='.')
            {
                a[d.x][d.y-1]='#';
                 node e;e.c='#';e.cnt=d.cnt+1;e.x=d.x;e.y=d.y-1;
                q.push(e);
            }
//cout<<"a"<<maxx<<endl;
       }
    }


}

int main()
{
    cin>>h>>w;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>a[i][j];
        }
    }
    bfs();
    cout<<maxx;
    return 0;
}
