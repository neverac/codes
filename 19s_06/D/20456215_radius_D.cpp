#include <iostream>

using namespace std;

int main()
{
    int x , y , z ;
    cin >> x >> y >> z ;
    int sum1 = x + y + z ;
    int a , b , c ;
    cin >> a >> b >> c ;
    int sum2 = a + b + c ;
    if (sum1>sum2) cout << "NO" << endl ;
    else {
        if (x>a) cout << "NO" << endl ;
        else {
            a-=x ;
            if (y>(a+b)) cout << "NO" << endl ;
            else cout << "YES" << endl ;
        }
    }
    return 0;
}
