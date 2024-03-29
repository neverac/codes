#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int INF = 1 << 24;
const int MAX_N = 200008;


struct P
{
	int num;
	int v;
	bool operator< (const P& Ri)const
	{
		return v < Ri.v;
	}
	P() {}
	P(const int& num, const int& v)
		:num(num), v(v) {}
};
P su[MAX_N];
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
			su[xxcnt++] = P(i, x);
		}
	}
	sort(su, su + xxcnt);
	
	int ct = 0;
	int ans = INF;
	int lb = 0, rb = 0;
	while (rb <= xxcnt)
	{
		if (ct < N)
		{
			const P& cur = su[rb++];
			if (!(cnt[cur.num]++))
			{
				++ct;
			}			
		}
		else
		{
			int m = su[rb - 1].v - su[lb].v;
			if (m < ans) ans = m;

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
