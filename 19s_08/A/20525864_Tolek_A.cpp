#include <bits/stdc++.h>

using namespace std;
int op[500005], n;
vector<int> vvp[8];
int last[8], ans;

void DFS(int x, int b) {
    if (x == 7) {
        ++ans;
        return;
    }
    if (x == 1)for (int i = 0; i < vvp[1].size(); i++)DFS(2, vvp[1][i]);
    else {
        int l = last[x] - 1, r = vvp[x].size() - 1;//(,]
        while (l < r) {
            if (r == l + 1) {
                if (vvp[x][r] > b)DFS(x + 1, vvp[x][r]);
                last[x] = r + 1;
                return;
            }
            int mid = (l + r) >> 1;
            if (vvp[x][mid] > b)r = mid;
            else l = mid;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", op + i);
        if (op[i] == 4)vvp[1].push_back(i);
        else if (op[i] == 8)vvp[2].push_back(i);
        else if (op[i] == 15)vvp[3].push_back(i);
        else if (op[i] == 16)vvp[4].push_back(i);
        else if (op[i] == 23)vvp[5].push_back(i);
        else if (op[i] == 42)vvp[6].push_back(i);
    }
    DFS(1, -1);
    cout << n - ans * 6;
    return 0;
}