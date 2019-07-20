#include<bits/stdc++.h>
using namespace std;
int to[4][2]={-1,0,
               1,0,
               0,-1,
               0,1};
int vis[1005][1005];
int news[1005][1005];
string s[1005];
int h,w;
int ans;
int x,y;
struct node
{
    int x,y,step;
};
void bfs()
{
    queue<node> q;
    node b;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(s[i][j]=='#')
            {
                b.step=0;
                b.x=i;
                b.y=j;
                q.push(b);
            }
        }
    }
    while(!q.empty())
    {
        b=q.front();
        q.pop();
        int flag=0;
        for(int i=0;i<4;i++)
        {
            int xx=b.x+to[i][0];
            int yy=b.y+to[i][1];
            if(0<=xx&&xx<h&&0<=yy&&yy<w)
            {
                if(s[xx][yy]=='.')
                {
                    s[xx][yy]='#';
                    node tmp;
                    tmp.x=xx;
                    tmp.y=yy;
                    tmp.step=b.step+1;
                    ans=max(ans,tmp.step);
                    q.push(tmp);
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    cin>>h>>w;
    ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<h;i++) cin>>s[i];
    bfs();
    /*while(1)
    {
        memset(news,0,sizeof(n));
        sum=0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(s[i][j]=='#') sum++;
            }
        }
        if(sum==h*w) break;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(s[i][j]=='#'&&!vis[i][j]&&!news[i][j])
                {
                    vis[i][j]=1;
                    for(int k=0;k<4;k++)
                    {
                        int xx=i+to[k][0];
                        int yy=j+to[k][1];
                        if(0<=xx&&xx<h&&0<=yy&&yy<w)
                        {
                            if(s[xx][yy]=='.')
                            {
                                s[xx][yy]='#';
                                news[xx][yy]=1;
                            }
                        }
                    }
                }
            }
        }
        ans++;
//        for(int i=0;i<h;i++)
//        {
//            for(int j=0;j<w;j++)
//                cout<<s[i][j]<<" ";
//            cout<<endl;
//        }

    }*/
    /*for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }
    */
    //cout<<ans<<endl;
    return 0;
}
