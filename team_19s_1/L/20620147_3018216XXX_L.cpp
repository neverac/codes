#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
using namespace std;


int main(){
    int t;
    cin >> t;
    int a[100005];
    while(t--){
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i] ;
        }
        int ans = sqrt(abs(a[n] - a[1]));
        cout << ans << endl;
    }
    return 0;
}