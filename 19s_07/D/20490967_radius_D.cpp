#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;
struct node {
    int l , r ;
};
node ba[1005] ;
int main()
{
    int t ;
    cin >> t ;
    while(t--) {
        string str ;
        cin >> str ;
        int len = str.length() ;
        ba[1].l = str[0]- '0' ;
        for(int i = 2 ; i < len-1 ; i++)
            ba[i].l = ba[i-1].l + str[i-1]- '0' ;
        if ((str[len-1] - '0')==0 )
            ba[len-2].r = 1 ;
        else ba[len-2].r = 0 ;
        for(int i = len-3 ; i> 0 ; i--)
        {
            if ( (str[i+1] -'0')==0 )
                ba[i].r = 1 + ba[i+1].r ;
            else ba[i].r = ba[i+1].r ;
        }
        int mi = 10000 ;
        for (int i = 1 ; i< len-1 ; i++)
        {
            int c = ba[i].l+ba[i].r ;
            if (c<mi) {
                mi = c ;
            }
        }
        int flog = 1 ;
        for(int i = 1 ; i< len-2 ; i++) {
            if (str[i]!=str[i+1] ) {
                flog = 0 ;
                break ;
            }
        }
        if (len>2){
            if (flog) {
                int ans = 0 ;
                if (str[0]>str[1]) ans++ ;
                if (str[len-1]<str[len-2]) ans++ ;
                cout << ans << endl ;
            }
            else{
                int q = 0 ;
                for(int i = 0 ; i< len ; i++ ) {
                    if (str[i]=='0') q++ ;
                }
                cout << min( min(q,len-q) , mi ) << endl ;
            }
        }
        else if (len==1) cout << 0 << endl ;
        else {
            if (str=="10") cout << 1 << endl ;
            else cout << 0 << endl ;
        }
    }
    return 0;
}
