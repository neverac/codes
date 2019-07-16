#include <iostream>

using namespace std;

int a0[1005];
int b1[1005];

int main()
{
    string s;
    int t,le;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int ans = 10000;
        le = s.length();
        int zuo1 = 0,you0 = 0;
        for(int i = 0;i < le;i++)
        {
            b1[i] = zuo1;
            if(s[i] == '1')zuo1++;
        }
        for(int i = le-1;i >= 0;i--)
        {
            a0[i] = you0;
            if(s[i] == '0')you0++;
        }
        int s;
        for(int i = 0;i < le;i++)
        {
            s = b1[i] + a0[i];
            ans = min(ans,s);
        }
        cout << ans << endl;
    }
    return 0;
}
