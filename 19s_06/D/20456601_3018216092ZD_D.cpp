#include <iostream>

using namespace std;

int main()
{
    int x,y,z;
    int a,b,c;
    cin >> x >> y >> z;
    cin >> a >> b >> c;

    if(a < x){
        cout << "NO" << endl;
        return 0;
    }
    if(a + b < y + x){
        cout << "NO" << endl;
        return 0;
    }
    if(a + b + c < x + y +z){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}