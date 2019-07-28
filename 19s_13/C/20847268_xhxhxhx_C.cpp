#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 55;


const int dx[4] = { -1,0,0,1 };
const int dy[4] = { 0,-1,1,0 };

struct P
{
	int x;
	int y;
	P() {}
	P(const int& x, const int& y) :x(x), y(y) {}
};

bool M[MAX_N][MAX_N];

void bfs(const P S, vector<P>& v);
int dist(const P& p1, const P& p2);

int main()
{
	int N;
	P S, T;
	char ch;
	scanf("%d%d%d%d%d", &N, &S.x, &S.y, &T.x, &T.y);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf(" \n%c", &ch);
			if (ch == '0')
			{
				M[i][j] = true;
			}
		}
	}

	vector<P> v1, v2;
	bfs(S, v1);
	if (!M[T.x][T.y])// 如果原本就在同一连通块
	{
		printf("0\n");
		return 0;
	}

	bfs(T, v2);
	int ans = 1 << 30;
	for (vector<P>::iterator i = v1.begin(); i != v1.end(); ++i)
	{
		for (vector<P>::iterator j = v2.begin(); j != v2.end(); ++j)
		{
			int m = dist(*i, *j);
			if (m < ans)
			{
				ans = m;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}

void bfs(const P S, vector<P>& v)
{
	queue<P> q;

	M[S.x][S.y] = false;
	v.push_back(S);
	q.push(S);

	while (!q.empty())
	{
		P cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			P nxt(cur.x + dx[i], cur.y + dy[i]);
			if (M[nxt.x][nxt.y])
			{
				M[nxt.x][nxt.y] = false;
				v.push_back(nxt);
				q.push(nxt);
			}
		}
	}
}

int dist(const P& p1, const P& p2)
{
	int m = p1.x - p2.x;
	int n = p1.y - p2.y;
	return m * m + n * n;
}