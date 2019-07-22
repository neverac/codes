#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
using namespace std;

long long a[100005];
int main(){
    int n;
    cin >> n;
    long long now = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        now += a[i];
    }
    sort(a,a+n);
    long long ans = 0;
    for(int i = 0;i < n;i++){
        ans += now*a[i];
        now -= a[i];
        if(i != n - 1){
            ans += now*a[i];
        }
    }
    cout << ans << endl;
    return 0;
}