#include <iostream>
#include <string>

using namespace std ;

int coun [ 1001 ] [ 2 ] ;

int main()
{
    int t ;
    cin >> t ;
    string s ;
    for ( int i = 0 ; i < t ; i ++ )
    {
        cin >> s ;
        int siz = s.size() ;
        coun [ 0 ] [ 0 ] = 0 ;
        coun [ siz ] [ 1 ] = 0 ;
        for ( int j = 0 ; j < siz ; j ++ )
        {
            if ( s [ j ] == '1' )
                coun [ j + 1 ] [ 0 ] = coun [ j ] [ 0 ] + 1 ;
            else
                coun [ j + 1 ] [ 0 ] = coun [ j ] [ 0 ] ;
        }
        for ( int j = siz - 1 ; j >= 0 ; j -- )
        {
            if ( s [ j ] == '0' )
                coun [ j ] [ 1 ] = coun [ j + 1 ] [ 1 ] + 1 ;
            else
                coun [ j ] [ 1 ] = coun [ j + 1 ] [ 1 ] ;
        }
        int mi = 1000 ;
        for ( int j = 0 ; j <= siz ; j ++ )
        {
            if ( coun [ j ] [ 0 ] + coun [ j ] [ 1 ] < mi )
                mi = coun [ j ] [ 0 ] + coun [ j ] [ 1 ] ;
        }
        cout << mi << endl ;
    }
}
