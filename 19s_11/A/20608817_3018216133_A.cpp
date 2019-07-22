#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll arr[100005];
ll sum;

int main()
{
    int n;
    ll ans = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr,arr+n);
    ll huo = sum;
    for(int i = 0;i < n;i++)
    {
        ans += huo * arr[i];
        huo -= arr[i];
        ans += huo * arr[i];
    }
    cout << ans <<endl;
    return 0;
}
