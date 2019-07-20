#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int INF = 999999999;


int main(){

    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        long long a,b;
        cin >> a >> b;
        cout << a << " " << 2 * a << endl;
    }
    return 0;
}