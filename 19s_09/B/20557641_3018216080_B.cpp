#include <iostream>
#include <string>

using namespace std ;

string s ; long long n , f , b , res ; char F , B ;

int main()
{
    cin >> n >> s ;
    F = s [ 0 ] ; B = s [ n - 1 ] ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        if ( s [ i ] != F )
        {
            f = i + 1 ;
            break ;
        }
    }
    for ( int i = n - 1 ; i >= 0 ; i -- )
    {
        if ( s [ i ] != B )
        {
            b = n - i ;
            break ;
        }
    }
    if ( F == B )
    {
        res = f * b ;
    }
    else res = f + b - 1 ;
    cout << res % 998244353 << endl ;
}
