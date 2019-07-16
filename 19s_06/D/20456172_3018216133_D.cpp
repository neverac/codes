#include <iostream>

using namespace std;

int main()
{
    int x,y,z,a,b,c;
    bool is = 1;
    cin >> x >> y >> z >> a >> b >>c;
    if(a + b + c < x + y + z)is = 0;
    if(a < x){
        is = 0;
    }else{
        if(a - x + b < y)is = 0;
    }
    if(is == 1)cout << "YES" <<endl;
    else cout << "NO" << endl;
    return 0;
}
