#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std ;

int arr [ 100000 ] ;

int main()
{
    int n , cntp = 0 , cntn = 0 ; long long sum = 0 ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> arr [ i ] ;
        if ( arr [ i ] > 0 )
        {
            cntp ++ ;
            sum += arr [ i ] ;
        }
        else
        {
            cntn ++ ;
            sum -= arr [ i ] ;
        }
    }
    sort ( arr , arr + n ) ;
    if ( cntp && cntn )
    {
        cout << sum << endl ;
        for ( int i = cntn ; i < n - 1 ; i ++ )
        {
            cout << arr [ 0 ] << " " << arr [ i ] << endl ;
            arr [ 0 ] -= arr [ i ] ;
        }
        for ( int i = 0 ; i < cntn ; i ++ )
        {
            cout << arr [ n - 1 ] << " " << arr [ i ] << endl ;
            arr [ n - 1 ] -= arr [ i ] ;
        }
    }
    else if ( cntn == 0 )
    {
        sum -= 2 * arr [ 0 ] ;
        cout << sum << endl ;
        for ( int i = 1 ; i < n - 1 ; i ++ )
        {
            cout << arr [ 0 ] << " " << arr [ i ] << endl ;
            arr [ 0 ] -= arr [ i ] ;
        }
        cout << arr [ n - 1 ] << " " << arr [ 0 ] << endl ;
    }
    else
    {
        sum += 2 * arr [ n - 1 ] ;
        cout <<sum <<endl ;
        for ( int i = 0 ; i < n - 1 ; i ++ )
        {
            cout << arr [ n - 1 ] << " " << arr [ i ] << endl ;
            arr [ n - 1 ] -= arr [ i ] ;
        }
    }


}
