#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
const int INF = 1 << 24;
const int MAX_N = 200008;

int A[MAX_N];

struct P
{
	int num;
	int p;
	int v;
	int nxv;
	bool operator< (const P& Ri)const
	{
		return v < Ri.v || v == Ri.v && nxv < Ri.v;
	}
	P() {}
	P(const int& num, const int& p, const int& v, const int& nxv)
		:num(num), p(p), v(v), nxv(nxv) {}
};
P su[MAX_N];
vector<int> v[MAX_N];

int cnt[MAX_N];

int main()
{
	int N, M, x;
	scanf("%d%d", &N, &M);

	int xxcnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &x);
			v[i].push_back(x);
		}
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j + 1 < M; j++)
		{
			su[xxcnt++] = P(i, j, v[i][j], v[i][j + 1]);
		}
		su[xxcnt++] = P(i, M - 1, v[i][M - 1], INF);
	}
	sort(su, su + xxcnt);
	
	int ct = 0;
	int ans = INF;
	int lb = 0, rb = 0;
	for (int i = 0; rb <= xxcnt; i++)
	{
		if (ct < N)
		{
			const P& cur = su[rb++];
			if (!cnt[cur.num])
			{
				++ct;
			}
			++cnt[cur.num];
			
		}
		else
		{
			int ma = su[rb - 1].v - su[lb].v;
			if (ma < ans) ans = ma;

			const P& cur = su[lb++];
			if (!(--cnt[cur.num]))
			{
				--ct;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}

/*

3 3
0 1 6
3 5 7
4 9 2

*/