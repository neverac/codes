#include <iostream>

using namespace std;

int main()
{
    int n ;
    cin >> n ;
    int a1=0 , a2=0 ,a3=0 ;
    for (int i = 0 ; i < n ; i++){
        int temp ;
        cin >> temp ;
        if (temp > 0 ) a1++ ;
        else if (temp<0) a2++ ;
    }
    int temp2 = n/2  ;
    if (n%2!=0) temp2++ ;
    if (a1>=temp2) cout << 1 << endl ;
    else if (a2>=temp2) cout << -1 << endl ;
    else cout << 0 << endl ;
}