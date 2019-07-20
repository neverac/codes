#include <iostream>
#include <cstdio>

using namespace std;

int num[3];

int main()
{
    int t,n,b,ans;
    cin >> t;
    for(int i = 0;i < t;i++)
    {
        ans = 0;
        num[0] = 0;
        num[1] = 0;
        num[2] = 0;
        cin >> n;
        for(int j = 0;j < n;j++)
        {
            cin >> b;
            b = b % 3;
            num[b]++;
        }
        ans = num[0];
        int he = min(num[1],num[2]);
        ans += he;
        num[1] -= he;
        num[2] -= he;
        ans += num[1]/3;
        ans += num[2]/3;
        cout << ans << endl;
    }
    return 0;
}
