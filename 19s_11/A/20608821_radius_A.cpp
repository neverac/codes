#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1e5+5 ;
long long arr[maxn] ;
int main()
{
    int n ;
    long long sum = 0 ;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) {
        cin >> arr[i] ;
        sum += arr[i] ;
    }
    sort(arr+1,arr+n+1) ;
    long long ans = sum*arr[1] ;
    sum-=arr[1] ;
    for (int i = 2 ; i <=n ; i++) {
        ans+= (arr[i-1]+arr[i])*sum ;
        sum-=arr[i] ;
    }
    cout << ans << endl ;
    return 0;
}
