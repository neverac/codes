#include <iostream>
#define z 1000000
using namespace std ;

long long r [ z ] , s [ z ] , q [ z ] , A , S , M , t ;
#define e( n ) for( int j = 1 ; j <= n ; j ++ )
#define h q[ j ]

int main()
{
    cin >> t ;
    e ( t )
    {
        cin >> h ; if ( h > M ) M = h ;
    }
    e ( M )
    {
        S += j ;
        A += S + 2 * ( s [ ( j - 1 ) / 2 ] ) ;
        if ( j % 2 == 0 ) A += j / 2 ;
        r [ j ] = A ; s [ j ] = S ;
    }
    e ( t ) cout << r [ h ] << endl ;
}
