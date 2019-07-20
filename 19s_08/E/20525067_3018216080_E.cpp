#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    int t , n , cnt0 , cnt1 , cnt2 , num ;
    cin >> t ;
    while ( t -- )
    {
        cnt0 = 0 ; cnt1 = 0 ; cnt2 = 0 ;
        cin >> n ;
        for ( int i = 0 ; i < n ; i ++ )
        {
            cin >> num ;
            if ( num % 3 == 0 )
            {
                cnt0 ++ ;
            }
            else if ( num % 3 == 1 )
            {
                cnt1 ++ ;
            }
            else
            {
                cnt2 ++ ;
            }
        }
        cout << ( cnt0 + min ( cnt1 , cnt2 ) + int ( abs ( cnt1 - cnt2 ) / 3 ) ) << endl ;
    }
}
