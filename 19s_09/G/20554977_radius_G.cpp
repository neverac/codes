#include <iostream>
using namespace std;
const int m = 1e6+5 ;
long long arr[m] ;

int main()
{
    arr[1] = 1 ;
    arr[2] = 5 ;
    for (long long i = 3 ; i < m ; i++ ){
        arr[i] = arr[i-1] ;
        arr[i] += 2 * i - 1 ;
        arr[i] += i * (i-1) / 2 ;
        if (i%2==0) arr[i]+= (i/2-1) * (i/2-1) ;
        else arr[i] += (i-1)*(i-3) / 4 ;
    }
    int t ;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        cout << arr[n] << endl ;
    }
    return 0;
}
