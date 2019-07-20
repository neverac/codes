#include <iostream>

using namespace std ;

int main()
{
    int k , a , b ;
    cin >> k >> a >> b ;
    if ( ( a >= b - 2 ) || ( k - 1 < a ) )
    {
        cout << k + 1 << endl ;
        return 0 ;
    }
    else
    {
        long long j = ( k - a + 1 ) / 2 , s = b - a , f = j * s ;

        cout << f + ( k - ( k - a + 1 ) / 2 * 2 ) + 1 << endl ;
    }
}
