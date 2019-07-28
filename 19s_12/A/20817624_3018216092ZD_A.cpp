#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int a[20];
int main()
{
    ios::sync_with_stdio(0);
    double p,q;
    cin >> p >> q;
    int cnt = 0;
    while(p < q){
        p *= 10;
        cnt++;
    }
    if(cnt >= 2) a[0]++;
    cnt = 0;
    while(1){
        int t = p / q;
        a[t]++;
        p -= t*q;
        p *= 10;
        cnt++;
        if(p == 0 || cnt > 100000) break;
    }
    for(int i = 0;i < 10;i++){
        if(a[i] != 0){
            cout << i;
        }
    }
    cout << endl;
    return 0;
}