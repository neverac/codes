#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define SIZE 110

using namespace std;

char map[SIZE][SIZE];

struct record
{
	int x,y;
	int sum;
}key[9];

int n,m,k;
int ex,ey;
int v[SIZE][SIZE][1<<6];
int d[4][2]=
{
    {-1,0},
    {1,0},
    {0,1},
    {0,-1}
};
bool legal(int x,int y)
{
    if(x<0 || x>=n)
        return false;
    if(y<0 || y>=m)
        return false;
    return map[x][y]!='#';
}
int bfs(int nx,int ny)
{
    int i;
	memset(v,0,sizeof(v));
	v[nx][ny][0]=1;
	record tmp;
	queue<record> que;
	while(!que.empty())
        que.pop();
	que.push({nx,ny,0});
	while(!que.empty())
	{
		tmp=que.front();
		que.pop();
		if(tmp.x==ex && tmp.y==ey)
            return v[tmp.x][tmp.y][tmp.sum]-1;
		for(i=0;i<4;i++)
		{
			nx=tmp.x+d[i][0];
			ny=tmp.y+d[i][1];
    //      printf("nx=%d ny=%d\n",nx,ny);
			if(legal(nx,ny))
			{
				if(map[nx][ny]=='.' && v[nx][ny][tmp.sum]==0)
				{
					v[nx][ny][tmp.sum]=v[tmp.x][tmp.y][tmp.sum]+1;
					que.push({nx,ny,tmp.sum});
					//puts("case1");
				}
				else if(map[nx][ny]>='A' && map[nx][ny]<='K')
				{
					if(tmp.sum&(1<<(map[nx][ny]-'A'))
                        && v[nx][ny][tmp.sum]==0)
					{
						v[nx][ny][tmp.sum]=v[tmp.x][tmp.y][tmp.sum]+1;
						que.push({nx,ny,tmp.sum});
						//puts("case2");
					}
				}
				else if(map[nx][ny]>='0' && map[nx][ny]<='9')
				{
					int sum=tmp.sum|(1<<(map[nx][ny]-'0'));
					//puts("case3");
					if(v[nx][ny][sum])
                        continue;
                      //  printf("new\n");
					v[nx][ny][sum]=v[tmp.x][tmp.y][tmp.sum]+1;
					que.push({nx,ny,sum});
				}
			}
		}
	}
	return -1;
}
int main()
{
    int i,j;
	int sx,sy;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	for(i=0;i<n;i++)
    {
        scanf("%s",map[i]);
    }
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&key[i].x,&key[i].y);
		map[key[i].x][key[i].y]='0'+i;
	}
	int ans=bfs(sx,sy);
	printf("%d\n",ans);
	return 0;
}
