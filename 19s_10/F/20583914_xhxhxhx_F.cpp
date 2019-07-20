#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


typedef long long ll;
const int MAX_N = 1008;


int G[MAX_N][MAX_N];
int deg[MAX_N];

void add_edge(const int u, const int v);
int dist[MAX_N];
int dist2[MAX_N];
bool M[MAX_N][MAX_N];

void bfs(const int S);
void bfs2(const int S);

int main()
{
	int n, m, s, t, a, b;

	scanf("%d%d%d%d", &n, &m, &s, &t);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &a, &b);
		add_edge(a, b);
		M[a][b] = M[b][a] = true;
	}
	
	bfs(s);
	bfs2(t);

	const int& td = dist[t];
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (!M[i][j] && dist[i] + dist2[j] + 1 >= td && dist2[i] + dist[j] + 1 >= td)
			{
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

void add_edge(const int u, const int v)
{
	G[u][deg[u]++] = v;
	G[v][deg[v]++] = u;
}

void bfs(const int S)
{
	queue<int> q;
	fill(dist, dist + MAX_N, 1000000);
	dist[S] = 0;
	q.push(S);

	while (!q.empty())
	{
		int cur = q.front();
		const int nd = dist[cur] + 1;
		q.pop();

		for (int i = 0; i < deg[cur]; ++i)
		{
			const int& to = G[cur][i];
			if (nd < dist[to])
			{
				dist[to] = nd;
				q.push(to);
			}
		}
	}
}

void bfs2(const int S)
{
	queue<int> q;
	fill(dist2, dist2 + MAX_N, 1000000);
	dist2[S] = 0;
	q.push(S);

	while (!q.empty())
	{
		int cur = q.front();
		const int nd = dist2[cur] + 1;
		q.pop();

		for (int i = 0; i < deg[cur]; ++i)
		{
			const int& to = G[cur][i];
			if (nd < dist2[to])
			{
				dist2[to] = nd;
				q.push(to);
			}
		}
	}
}
