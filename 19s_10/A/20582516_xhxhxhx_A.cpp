#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;

const int INF = 1e6;
const int MAX_N = 1005;

const int dx[4] = { -1,0,0,1 };
const int dy[4] = { 0,-1,1,0 };

int M[MAX_N][MAX_N];

struct P
{
	int x;
	int y;
	int st;
	P() {}
	P(const int& x, const int& y, const int& st)
		:x(x), y(y), st(st) {}
};


int main()
{
	int H, W;
	char ch;

	scanf("%d%d", &H, &W);

	queue<P> q;
	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			scanf(" \n%c", &ch);
			if (ch == '#')
			{
				M[i][j] = 0;
				q.push(P(i, j, 0));
			}
			else
			{
				M[i][j] = INF;
			}
		}
	}

	while (!q.empty())
	{
		P cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			P nxt(cur.x + dx[i], cur.y + dy[i], cur.st + 1);
			if (M[nxt.x][nxt.y] > nxt.st)
			{
				M[nxt.x][nxt.y] = nxt.st;
				q.push(nxt);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			if (M[i][j] > ans)
			{
				ans = M[i][j];
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}
