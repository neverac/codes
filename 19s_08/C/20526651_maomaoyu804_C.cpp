#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll k,a,b;
    cin>>k>>a>>b;
    ll ans=0;
    if(b<=a+2) ans+=k+1;
    else{
        if(k<=a-1) ans+=k+1;
        else{
            ans+=a;k-=(a-1);
            ans+=(k/2)*(b-a);
            if(k%2) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
