#include <iostream>

using namespace std ;

int main()
{
    int cntp = 0 , cntn = 0 ;
    int n , num ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> num ;
        if ( num > 0 )
            cntp ++ ;
        else if ( num < 0 )
            cntn ++ ;
    }
    n = ( n + 1 ) / 2 ;
    if ( cntp >= n )
        cout << 1 << endl ;
    else if ( cntn >= n )
        cout << -1 << endl ;
    else cout << 0 << endl ;

}
