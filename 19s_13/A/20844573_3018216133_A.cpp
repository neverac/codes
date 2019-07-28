#include <iostream>

using namespace std;

int a[200];

int main()
{
    int n,cnt1,cnt2;
    cnt1 = cnt2 = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >>a[i];
        if(a[i] > 0)cnt1++;
        if(a[i] < 0)cnt2++;
    }
    if(cnt1 * 2 >= n)cout << 1 << endl;
    else{
        if(cnt2 * 2 >= n)cout << -1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
