#include <iostream>

using namespace std ;

int occ [ 10 ] ;

int main()
{
    int p , q ;
    cin >> p >> q ;
    int i = 0 ;
    while ( i < 500 )
    {
        p *= 10 ;
        i ++ ;
        occ [ p / q ] ++ ;
        p %= q ;
    }
    for ( int j = 0 ; j < 10 ; j ++ )
    {
        if ( occ [ j ] )
            cout << j ;
    }
    cout << endl ;
}
