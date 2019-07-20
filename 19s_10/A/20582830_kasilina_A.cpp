#include <bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int h,w;
struct node{
	int x,y,step;
};
int vis[1005][1005];
queue<node>q;
int tox[]={1,0,0,-1};
int toy[]={0,1,-1,0};
int main()
{
	cin >> h >> w;
	int cnt=0;
	node s;
	for(int i=0;i<h;i++)
	{
		scanf("%s",mp[i]);
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(mp[i][j]=='#')
			{
				vis[i][j]=1;
				s.x=i;
				s.y=j;
				s.step=0;
				q.push(s);
			}
		}
	}
	node t;
	int op=0;
	while(!q.empty())
	{
		s=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int x=s.x+tox[i];
			int y=s.y+toy[i];
			if(x<h&&x>=0&&y>=0&&y<w)
			{
				if(mp[x][y]=='.'&&!vis[x][y])
				{
					mp[x][y]='#';
					vis[x][y]=1;
					t.x=x;
					t.y=y;
					t.step=s.step+1;
					q.push(t);
					op=max(op,t.step);
				}
			}
		}
	}
	printf("%d\n",op);
    return 0;
}