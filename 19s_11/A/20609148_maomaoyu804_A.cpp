#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll num[100005];

int main()
{
    int n;cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
    sort(num,num+n);
    for(int i=1;i<=n;i++){
        ll temp=num[i];
        num[i]+=num[i-1];
        ans+=temp*(temp+num[i-1]*2);
    }
    cout<<ans<<endl;
    return 0;
}
