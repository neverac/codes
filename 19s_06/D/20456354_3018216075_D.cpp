//
// Created by Septieme on 2019/7/15.
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    int x, y, z, a, b, c;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if (a < x) {
        cout << "NO" << endl;
    } else {
        a -= x;
        if (a + b < y)
            cout << "NO" << endl;
        else {
            if (a + b + c >= y + z)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}