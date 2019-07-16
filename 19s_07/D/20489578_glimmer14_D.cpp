#include <iostream>
#include <string>
using namespace std;
string s;
int pos[1010];

int main()
{
    int t;
    scanf("%d", &t);
    while (t --)
    {
        cin >> s;
        int l = s.size();
        int num = 0;
        for (int i = 0; i < l; i ++)
            if (s[i] == '0') pos[num ++] = i;
        
        pos[num] = l;
        int ans = num, tt, cc = 0;
        for (int i = 0; i < l; i ++)
        {
            if (pos[cc] == i) cc ++;
            tt = (i + 1 - cc) + (num - cc);
            if (tt < ans) ans = tt;
        }
        printf("%d\n", ans);
    }
    
}