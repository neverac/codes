#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int a[10000];
int main()
{
    int n;
    cin >> n;
    int len1 = 0;
    int len2 = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i] > 0) len1++;
        if(a[i] < 0) len2++;
    }
    if(n % 2 == 0){
        if(len1 >= n / 2){
            cout << 1 << endl;
            return 0;
        }
        if(len2 >= n / 2){
            cout << -1 << endl;
            return 0;
        }
        cout << 0 << endl;
    }
    else{
        if(len1 >= n / 2 + 1){
            cout << 1 << endl;
            return 0;
        }
        if(len2 >= n / 2 +1){
            cout << -1 << endl;
            return 0;
        }
        cout << 0 << endl;
    }
    return 0;
}