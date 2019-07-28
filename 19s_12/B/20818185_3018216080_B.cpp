#include <iostream>
#include <string>

using namespace std ;

int isR ( string s )
{
    int siz = s.size() ;
    for ( int i = 0 ; i <= ( siz - 1 ) / 2 ; i ++ )
    {
        if ( s [ i ] != s [ siz - 1 - i ] )
            return 0 ;
    }
    return 1 ;
}

int main()
{
    string s ;
    cin >> s ;
    int len = s.size() ;
    for ( int i = 0 ; i <= ( len - 1 ) / 2 ; i ++ )
    {
        if ( s [ i ] != s [ len - 1 - i ] )
        {
            if ( isR ( s.substr ( i + 1 , len - 2 * i - 1 ) ) )
            {
                for ( int j = i ; j >= 0 ; j -- )
                {
                    if ( s [ j ] != s [ i ] )
                    {
                        cout << j + 2 << endl ;
                        return 0 ;
                    }
                }
                cout << 1 << endl ;
                return 0 ;
            }
            else if ( isR ( s.substr ( i , len - 2 * i - 1 ) ) )
            {
                cout << len - i << endl ;
                return 0 ;
            }
        }
    }
    for ( int j = len / 2 ; j >= 0 ; j -- )
    {
        if ( s [ j ] != s [ len / 2 ] )
        {
            cout << j + 2 << endl ;
            return 0 ;
        }
    }
    cout << 1 << endl ;
    return 0 ;

}
