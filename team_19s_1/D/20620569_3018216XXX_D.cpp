#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int t,n,m;
ll a[105];

int main()
{
    cin >> t;
    int b;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 0;i < n;i++)
            cin >> b >> a[i];
        sort(a,a+n);
        a[0]++;
        for(int i = 1;i < n;i++)
            a[i] = (a[i] + 1)*a[i-1];
        int i;
        for(i = 0;i < n;i++)
            if(a[i] > m){
                break;
            }
        cout << i <<endl;
    }
    return 0;
}
