#include <iostream>
#include <algorithm>

using namespace std ;

int arr [ 200006 ] ;
int brr [ 200006 ] ;

int main()
{
    int n , m , k ;
    cin >> n >> m >> k ;
    for ( int i = 1 ; i <= n ; i ++ )
    {
        cin >> arr [ i ] ;
        brr [ i ] = arr [ i ] ;
    }
    sort ( brr + 1 , brr + n + 1 ) ;
    int s = brr [ n - m * k + 1 ] , cnt = 0 ; long long sum = 0 ;
    for ( int i = n - m * k + 1 ; i <= n ; i ++ )
    {
        if ( brr [ i ] == s )
        {
            cnt ++ ;
        }
        sum += brr [ i ] ;
    }
    cout << sum << endl ;
    int ind = 0 ; bool flag = 0 ;
    for ( int i = 0 ; i < k - 1 ; i ++ )
    {
        for ( int j = 0 ; j < m ; )
        {
            ind ++ ;
            if ( arr [ ind ] > s )
                j ++ ;
            else if ( arr [ ind ] == s && cnt )
            {
                j ++ ;
                cnt -- ;
            }
        }
        if ( flag )
            cout << " " ;
        else flag = 1 ;
        cout << ind ;
    }
    cout << endl ;
}
