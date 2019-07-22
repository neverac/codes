#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int  T;
int n, m;
int cuo[110];

int main()
{
	cin >> T;
	while (T--)
	{
		int i, j, x, y;
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++) {
			scanf("%d%d", &x, &y);
			cuo[i] = y + 1;
		}
		sort(cuo + 1, cuo + 1 + n);
		ll k = 1;
		for (i = 1; i <= n; i++) {
			if (k*cuo[i] <= m) {
				k *= cuo[i];
			}
			else {
				break;
			}
		}
		printf("%d\n", i - 1);
	}
	return 0;
}