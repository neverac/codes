#include <iostream>

using namespace std ;

int main()
{
    int t ;
    int ang ;
    cin >> t ;
    while ( t -- )
    {
        cin >> ang ;
        for ( int i = 3 ; i <= 360 ; i ++ )
        {
            if ( (( ang * i ) % 180 == 0) && (ang * i <= ( i - 2 ) * 180 ))
            {
                 cout << i << endl ;
                 break ;
            }
        }
    }
}
