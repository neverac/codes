#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t ;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        int l1=0 ;
        int l2=0 ;
        int ans = 0 ;
        while(n--){
            int temp ;
            cin >> temp ;
            int q = temp % 3 ;
            if (q==0) ans ++ ;
            else if (q==1) l1++ ;
            else if (q==2) l2++ ;
        }
        int t = l1 ;
        ans+= min(l1,l2) ;
        l1 -= min(l1,l2) ;
        l2 -= min(t,l2) ;
        if (l1!=0) ans+= l1 / 3 ;
        if (l2!=0) ans += l2 / 3 ;
        cout << ans << endl ;
    }
    return 0;
}
