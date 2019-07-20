#include <iostream>
#include <cstdio>

using namespace std;

long long ans;

int main()
{
    int k,a,b;
    ans = 1;
    scanf("%d%d%d",&k,&a,&b);
    if(b-a<=2){
        ans += k;
    }else{
        if(k+1 >= a){
            ans = a;
            k = k - (a-1);
        }else{
            ans += k;
            cout << ans << endl;
            return 0;
        }
        long long kk = k /2;
        k = k % 2;
        ans += kk*(b-a);
        ans+=k;
    }
    cout << ans << endl;
    return 0;
}
