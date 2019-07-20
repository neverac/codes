#include <iostream>
#define mo 998244353

using namespace std;

int main()
{
    string s;
    long long n,ans = 0,z,y;
    cin >> n >> s;
    z = 0;y = n-1;
    while(s[z] == s[z+1] && z+1 <n)
        z++;
    while(s[y] == s[y-1] && y-1 >= 0)
        y--;
    if(z >= y){
        ans = ((n%mo)*((n+1)%mo)/2)%mo;
    }else{
        if(s[z] == s[y]){
            ans += 1;
            ans += z + 1;
            ans += n-y;
            ans += (((z+1)%mo)*((n-y)%mo))%mo;
        }else{
            ans += z+n-y+1;
            ans += 1;
        }
    }
    ans %= mo;
    cout << ans << endl;
    return 0;
}
