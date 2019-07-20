#include <iostream>

using namespace std;

int main()
{
    int t ;
    cin >> t ;
    while(t--){
        int a , b ;
        cin >> a >> b ;
        int c = a+1 ;
        if (b/c<2) cout << a << " "<< 2* a << endl ;
        else {
            int d = b/c ;
            cout << c << " "<< d*c << endl ;
        }
    }
    return 0;
}
