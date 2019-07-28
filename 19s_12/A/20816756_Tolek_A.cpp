#include <bits/stdc++.h>

using namespace std;
set<int> ssp;
int op[50];

int main() {
    int a, b;
    cin >> a >> b;
    while (true) {
        a *= 10;
        op[a / b] = 1;
        a = a % b;
        if (a == 0)break;
        else if (ssp.count(a) == 0)ssp.insert(a);
        else break;
    }
    for (int i = 0; i < 10; i++)if (op[i])cout << i;
    return 0;
}