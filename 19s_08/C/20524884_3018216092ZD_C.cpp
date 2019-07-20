#include <iostream>

using namespace std;

int main()
{
    long long k,a,b;
    long long now = 1;
    cin >> k >> a >> b;
    if(b - a <= 1){
        cout << 1 + k << endl;
        return 0;
    }
    now = a;
    k = k - a + 1;
    if(k % 2 == 0){
        now = a + k / 2 *(b - a);
    }
    else{
        now = a + (k-1) / 2 * (b - a) + 1;
    }
    cout << now << endl;
    return 0;
}