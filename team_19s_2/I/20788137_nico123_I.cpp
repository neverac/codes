#include <iostream>
#include <string.h>
using namespace std;


const int MAX_N = 105;
const int MAX_V = 105;


int G[MAX_V][MAX_N];
int deg[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v);
bool dfs(const int& v);
int bipartite_matching(const int V);


int main()
{
	int m, n, e;
	while (~scanf("%d", &m))
	{
		if (!m) break;
		scanf("%d%d", &n, &e);
		memset(deg, 0, sizeof(deg));
		int V = m + n;

		for (int i = 0; i < e; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			b += m;
			add_edge(a, b);
		}

		printf("%d\n", bipartite_matching(V));
	}

	return 0;
}

void add_edge(int u, int v)
{
	G[u][deg[u]++] = v;
	G[v][deg[v]++] = u;
}

bool dfs(const int& v)
{
	used[v] = true;
	for (int i = 0; i < deg[v]; i++)
	{
		int u = G[v][i];
		int w = match[u];

		if (w == -1 || !used[w] && dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int bipartite_matching(const int V)
{
	int res = 0;
	memset(match, -1, sizeof(match));
	for (int v = 0; v < V; v++)
	{
		if (match[v] == -1)
		{
			memset(used, 0, sizeof(used));
			res += dfs(v);
		}
	}
	return res;
}
