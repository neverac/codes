#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    long long p , q ;
    cin >> p >> q ;
    long long temp = p % q ;
    if (temp==0) {
        cout << 0 << endl ;
        return 0 ;
    }
    int arr[10] = {0} ;
    int t = 100 ;
    while(t--) {
        temp*=10 ;
        long long temp1 = temp ;
        int s = (temp1 / q)%10 ;
        if (s==0&&temp1%q==0) break ;
        if(!arr[s]) arr[s]++ ;
        temp = temp % q ;
    }
    for (int i = 0 ; i < 10 ; i++)
        if (arr[i]) cout << i ;
    cout << endl ;
    return 0;
}
