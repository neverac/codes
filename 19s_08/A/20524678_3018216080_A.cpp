#include <iostream>

using namespace std ;

int arr [ 500000 ] ;
int cnt [ 6 ] ;

int main()
{
    int n , c ;
    cin >> n ;
    int status = 4 , t = 0 ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> c ;
        switch ( c )
        {
            case 4: cnt [ 0 ] ++ ; break ;
            case 8: if ( cnt [ 0 ] > cnt [ 1 ] ) cnt [ 1 ] ++ ;else t ++ ; break ;
            case 15: if ( cnt [ 1 ] > cnt [ 2 ] ) cnt [ 2 ] ++ ;else t ++ ; break ;
            case 16: if ( cnt [ 2 ] > cnt [ 3 ] ) cnt [ 3 ] ++ ;else t ++ ; break ;
            case 23: if ( cnt [ 3 ] > cnt [ 4 ] ) cnt [ 4 ] ++ ;else t ++ ; break ;
            case 42: if ( cnt [ 4 ] > cnt [ 5 ] ) cnt [ 5 ] ++ ;else t ++ ; break ;
        }
    }
    cout << n - 6 * cnt [ 5 ] << endl ;

}
