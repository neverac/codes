#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>
using namespace std;

const int dx[4] = { -1,0,0,1 };
const int dy[4] = { 0,-1,1,0 };

struct P
{
	int x;
	int y;
	int k;
	int st;
	P(const int& x, const int& y, const int& k, const int& st)
		:x(x), y(y), k(k), st(st) {}
};

const int MAX_N = 105;

int A[32][MAX_N][MAX_N];
int dist[32][MAX_N][MAX_N];
int vis[32][MAX_N][MAX_N];
int keys[MAX_N][MAX_N];

int ax, ay, tx, ty;

void bfs();

int main()
{
	int N, M, K, ma, mb;
	char ch;
	memset(dist, -1, sizeof(dist));

	scanf("%d%d%d%d%d%d%d", &N, &M, &K, &ax, &ay, &tx, &ty);
	++ax;
	++ay;
	++tx;
	++ty;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			scanf(" \n%c", &ch);
			switch (ch)
			{
			case '.':
				for (int iii = 0; iii < 32; ++iii)
				{
					A[iii][i][j] = 1;
				}
				break;
			case '#':

				break;
			default:
				int tk = ch - 'A';
				for (int iii = 0; iii < 32; ++iii)
				{
					if (iii >> tk & 1)
					{
						A[iii][i][j] = 1;
					}
				}
				break;
			}
		}
	}

	for (int i = 0; i < K; ++i)
	{
		scanf("%d%d", &ma, &mb);
		keys[ma + 1][mb + 1] |= 1 << i;
	}

	bfs();

	int ans = INT_MAX;
	for (int i = 0; i < 32; ++i)
	{
		if (dist[i][tx][ty] != -1 && dist[i][tx][ty] < ans)
		{
			ans = dist[i][tx][ty];
		}
	}
	if (ans == INT_MAX)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", ans);
	}

	return 0;
}

void bfs()
{
	for (int i = 0; i < 32; ++i)
	{
		dist[i][ax][ay] = 0;
	}
	P m(ax, ay, 0, 0);
	queue<P> q;
	vis[0][ax][ay] = 1;
	if (keys[ax][ay])
	{
		m.k |= keys[ax][ay];
		vis[m.k][ax][ay] = 1;
	}
	q.push(m);

	while (!q.empty())
	{
		m = q.front();
		q.pop();

		int ned = m.st + 1;

		for (int i = 0; i < 4; ++i)
		{
			if (A[m.k][m.x + dx[i]][m.y + dy[i]] && !vis[m.k][m.x + dx[i]][m.y + dy[i]])
			{
				P ns(m.x + dx[i], m.y + dy[i], m.k, ned);			
				vis[m.k][ns.x][ns.y] = 1;
				dist[m.k][ns.x][ns.y] = ned;
				if (keys[ns.x][ns.y])
				{
					ns.k |= keys[ns.x][ns.y];
					vis[m.k][ns.x][ns.y] = 1;
					dist[m.k][ns.x][ns.y] = ned;
				}
				q.push(ns);
			}
		}
	}
}
