#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int h, w, cnt = 0, color = 1;

int a[1010][1010];
struct node {
    int i, j;
} res[1000010];

void change(int i, int j) {
    if (i - 1 >= 1 && !a[i - 1][j]) {
        a[i - 1][j] = color;
        res[cnt].i = i - 1;
        res[cnt++].j = j;
    }
    if (i + 1 <= h && !a[i + 1][j]) {
        a[i + 1][j] = color;
        res[cnt].i = i + 1;
        res[cnt++].j = j;
    }
    if (j - 1 >= 1 && !a[i][j - 1]) {
        a[i][j - 1] = color;
        res[cnt].i = i;
        res[cnt++].j = j - 1;
    }
    if (j + 1 <= w && !a[i][j + 1]) {
        a[i][j + 1] = color;
        res[cnt].i = i;
        res[cnt++].j = j + 1;
    }
}

int main() {
    int pos = 0;
    char temp;
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> temp;
            if (temp == '.')
                a[i][j] = 0;
            else {
                a[i][j] = -1;
                res[cnt].i = i;
                res[cnt++].j = j;
            }
        }
    }
    while (cnt < h * w) {
        int num = cnt;
        for (; pos < num; pos++) {
            change(res[pos].i, res[pos].j);
        }
        color++;
    }

    cout << color - 1 << endl;


    return 0;
}