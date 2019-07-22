#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int sta = 0, l = s.size();
        bool f = true;
        for (int i = 0; i < l; i ++)
        {
            if (sta == 0)
            {
                if (s[i] == '0')
                {
                    sta = 1;
                }
                else if (s[i] == '+' || s[i] == '*')
                {
                    f = false;
                    break;
                }
                else if (s[i] == '?')
                {
                    s[i] = '1';
                    sta = 2;
                } else{
                    sta = 2;
                }
            }
            else if (sta == 1)
            {

                if (s[i] == '+' || s[i] == '*')
                {
                    sta = 0;
                }
                else if (s[i] == '?')
                {
                    s[i] = '+';
                    sta = 0;
                } else{
                    f = false;
                    break;
                }
            }
            else
            {
                if (s[i] == '+' || s[i] == '*')
                {
                    sta = 0;
                }
                else if (s[i] == '?')
                {
                    s[i] = '1';
                    sta = 2;
                } else{
                    sta = 2;
                }
            }
        }
        if (f && sta != 0) cout << s << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}