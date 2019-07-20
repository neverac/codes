#include <iostream>

using namespace std;
int a[10];
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
        for(int i = 0;i < n;i++){
            int temp ;
            cin >> temp;
            a[temp % 3]++;
        }
        int x1 = a[1];
        int x2 = a[2];
        int ans = a[0];
        if(x1 > x2){
            ans += x2;
            a[1] -= x2;
            a[2] = 0;
        }
        else{
            ans += x1;
            a[1] = 0;
            a[2] -= x1;
        }
        ans += a[1] / 3;
        ans += a[2] / 3;
        cout << ans << endl;

    }
    return 0;
}