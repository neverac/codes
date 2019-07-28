//
// Created by Septieme on 2019/7/27.
//
#include "bits/stdc++.h"

using namespace std;

int a[110];

int main() {
    int N, pos = 0, neg = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] > 0)
            pos++;
        if (a[i] < 0)
            neg++;
    }
    int num = (N + 1) / 2;
    if (pos >= num)
        cout << 1 << endl;
    else if (neg >= num)
        cout << -1 << endl;
    else
        cout << 0 << endl;


    return 0;
}
