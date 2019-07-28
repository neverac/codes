#include <bits/stdc++.h>

#define ll long long
using namespace std;

bool judge_reversal(string s) {
    int n = s.length();
    int front = 0, back = n - 1;
    while (front < back) {
        if (s[front] != s[back]) {
            return false;
        }
        ++front;
        --back;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int i = 0, j, len;
    len = s.length();
    j = len - 1;
    while (i < j) {
        if (s[i] != s[j])
            break;
        i++;
        j--;
    }
    int l = i, r = j;
    string t = s;
    t = s.substr(0, i) + s.substr(i+1, len);
    if (judge_reversal(t)) {
        while (s[l - 1] == s[l])
            l--;
        cout << l + 1 << endl;
    } else {
        while (s[r - 1] == s[r])
            r--;
        cout << r + 1 << endl;
    }

    return 0;

}
