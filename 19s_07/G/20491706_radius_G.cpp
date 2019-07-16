#include <iostream>
#include <cmath>

using namespace std;
int ma[1005][1005] , arr[1005][1005] ;
int main()
{
    int n ;
    cin >> n ;
    for(int i = 0 ; i< n ; i++) {
        for(int j = 0 ; j < n ; j++) cin >> ma[i][j] ;
    }
    int maxn = 1 ;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j< n ; j++) {
            if ( i == 0) arr[i][j] = 1 ;
            else if (ma[i][j]==ma[i-1][j]+1
                     && ma[i][j]==ma[i][j-1]+1 )
                arr[i][j] = min(arr[i-1][j] , arr[i][j-1]) +1 ;
            else arr[i][j] = 1 ;
            maxn = max(maxn ,arr[i][j]) ;
        }
    }

    cout << maxn << endl ;
    return 0;
}
