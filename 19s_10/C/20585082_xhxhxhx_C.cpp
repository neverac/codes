#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;


typedef long long ll;

const int MAX_N = 205000;

struct Edge
{
	int to;
	int next;
};
Edge G[2 * MAX_N];
int head[MAX_N];
int deg;
void init();
void add_edge(const int u, const int v);

bool vis[MAX_N];
void bfsc(const int v, const int d, int& maxd, int& t);

bool dp[MAX_N];

int main()
{
	int N, a, b;

	dp[1] = true;
	dp[2] = false;
	for (int i = 3; i < MAX_N; ++i)
	{
		if ((i - 2) % 3 == 0)
		{
			dp[i] = false;
		}
		else
		{
			dp[i] = true;
		}
	}
	init();

	scanf("%d", &N);

	for (int i = 1; i < N; ++i)
	{
		scanf("%d%d", &a, &b);
		add_edge(a, b);
	}

	memset(vis, true, sizeof(vis));
	int t = 1, maxd = 0;
	bfsc(1, 0, maxd, t);
	maxd = 0;
	memset(vis, true, sizeof(vis));
	bfsc(t, 0, maxd, t);

	printf("%s\n", dp[maxd + 1] ? "First" : "Second");

	return 0;
}

void init()
{
	memset(head, -1, sizeof(head));
	deg = 0;
}

void add_edge(const int u, const int v)
{
	G[deg].to = v;
	G[deg].next = head[u];
	head[u] = deg++;

	G[deg].to = u;
	G[deg].next = head[v];
	head[v] = deg++;
}


void bfsc(const int v, const int d, int& maxd, int& t)
{
	vis[v] = false;
	if (d > maxd)
	{
		maxd = d;
		t = v;
	}
	for (int i = head[v]; ~i; i = G[i].next)
	{
		const int& to = G[i].to;
		if (vis[to])
		{
			bfsc(to, d + 1, maxd, t);
		}
	}
}