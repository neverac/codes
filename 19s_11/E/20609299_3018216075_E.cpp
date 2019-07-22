#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[100010], b[100010];
queue<int> in, dis;

int main() {
    int n;
    cin >> n;
    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            count1++;
            in.push(i);
        }
        if (a[i] != b[n - i - 1]) {
            count2++;
            dis.push(n - i - 1);
        }
        if (count1 > 2 && count2 > 2) {
            cout << "No hope" << endl;
            return 0;
        }
    }
    int id1, id2;
    if (!count1 || !count2) {
        cout << "Nothing to do here" << endl;
    } else if (count1 == 2 || count2 == 2) {
        if (count1 == 2) {
            id1 = in.front();
            in.pop();
            id2 = in.front();
        } else {
            id1 = dis.front();
            dis.pop();
            id2 = dis.front();
        }
        if (id1 > id2)
            swap(id1, id2);
        cout << "Yes" << endl;
        cout << id1 + 1 << " " << id2 + 1 << endl;
    } else
        cout << "No hope" << endl;
    return 0;
}