#include <iostream>
#include <algorithm>

using namespace std ;

long long arr [ 100000 ] ;
long long sum = 0 , res = 0 ;

int main()
{
    int n ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> arr [ i ] ;
        sum += arr [ i ] ;
    }
    sort ( arr , arr + n ) ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        res += sum * arr [ i ] ;
        sum -= arr [ i ] ;
        res += sum * arr [ i ] ;
    }
    cout << res << endl ;
}
