#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
char s[N];
// cout << ans << endl;
// cout << ans << endl;
// cout << ans << endl;
// cout << ans << endl;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int l = strlen(s);
    int ans = -1;
    bool flag = false;
    if (l % 2 == 1)
    {
        int p = l / 2, q = p + 1;
        for (int i = 0; i < l / 2; i++)
        {
            if (s[p - i] != s[q + i])
            {
                if (flag == true)
                {
                    ans = -1;
                    break;
                }
                ans = p - i;
    
                p--;i --;
                flag = true;
            }
        }
        if (flag == false)
            ans = 0;

        if (ans == -1)
        {
            p = l / 2 - 1, q = l / 2;
            for (int i = 0; i < l / 2; i++)
            {
                if (s[p - i] != s[q + i])
                {
                    ans = q + i;
                    q++;
                    break;
                }
            }
            if (ans == -1)
                ans = l - 1;
        }
    }
    else
    {
        int p = l / 2 - 1, q = p + 2;
        flag = false;
        for (int i = 0; i < l / 2 - 1; i++)
        {
            if (s[p - i] != s[q + i])
            {
                if (flag == true)
                {
                    ans = -1;
                    break;
                }
                ans = p - i;
                
// cout << ans << endl;
                p--;i --;
                flag = true;
            }
        }
        if (flag == false)
            ans = 0;
            
// cout << ans << endl;

        if (ans == -1)
        {
            p = l / 2 - 2, q = p + 3;
            flag = true;
            // ans = p + 1;
            for (int i = 0; i <= p; i++)
            {
                if (s[p - i] != s[q + i])
                {
                    ans == -1;
                    flag = false;
                    break;
                }
            }
            if (flag) ans = p+ 1;
        }
        
// cout << ans << endl;

        if (ans == -1)
        {
            int p = l / 2 - 2, q = p + 2;
            for (int i = 0; i <= p; i++)
            {
                if (s[p - i] != s[q + i])
                {
                    ans = q + i;
                    q++;
                    break;
                }
            }
            if (ans == -1)
                ans = l - 1;
                
// cout << ans << endl;
        }
    }
    cout << ans + 1 << endl;
}