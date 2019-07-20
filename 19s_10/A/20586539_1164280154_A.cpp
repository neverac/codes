#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

int  A[1005][1005];

struct node {
	int i;
	int j;
	int step;
}find1[1000001];;
const int movex[] = { -1,0,0,1 };
const int movey[] = { 0,1,-1,0 };
int k = 1;

int main() {
	int H, W;
	cin >> H >> W;
	char c;
	
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> c;
			if (c == '#') { A[i][j] = 1; find1[k].i = i; find1[k].j = j; find1[k].step = 0; k++; }
			if (c == '.') { A[i][j] = 0; }

		}
	}
	int p = 1;
	int ans = 0;
	k --;
	while (p<=k) {
		ans = max(ans, find1[p].step);
		for (int i = 0; i < 4; i++) {
			int x = movex[i] + find1[p].i;
			int y = movey[i] + find1[p].j;
			if (x >= 1 && x <= H && y >= 1 && y <= W && A[x][y] == 0) {
				A[x][y] = 1;
				k++;
				find1[k].i = x;
				find1[k].j = y;
				find1[k].step = find1[p].step + 1;
			}
		}
		p++;
	}
	cout << ans << endl;
	return 0;
}