#include<bits/stdc++.h>
using namespace std;
int main() {
    long long k,a,b;
    scanf("%lld%lld%lld",&k,&a,&b);
    long long ans=1;
    if(b-a<=2||(k+1)<a) {
        printf("%lld\n",k+1);
    }
    else {
        if(a>1) {
            k-=(a-1);
        }
        ans=a;
        if(k%2==0) {
            ans+=(k/2)*(b-a);
        }
        else {
            ans+=(k/2)*(b-a)+1;
        }
        printf("%lld\n",ans);
    }
}
