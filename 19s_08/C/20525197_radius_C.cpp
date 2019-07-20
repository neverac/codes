#include <iostream>

using namespace std;

int main()
{
    int k , a , b ;
    cin >> k >> a >> b ;
    if (b-a>2) {
        if (k+1<=a) cout << k+1 << endl ;
        else {
            k -= (a-1) ;
            long long ans = a ;
            long long q = k / 2 ;
            ans += q * (b-a) ;
            ans+= k%2 ;
            cout << ans << endl ;
        }
    }
    else cout << k+1 << endl ;
    return 0;
}
