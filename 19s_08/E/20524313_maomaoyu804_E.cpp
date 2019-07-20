#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int main()
{
    int t;cin>>t;
    while(t--){
        ll sum1=0,sum2=0,sum0=0;
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++){
            int num;scanf("%d",&num);
            if(num%3==1) sum1++;
            else if(num%3==2) sum2++;
            else sum0++;
        }
        ll ans=sum0;
        if(sum1>sum2){
            ans+=sum2;
            ans+=(sum1-sum2)/3;
        }
        else{
            ans+=sum1;
            ans+=(sum2-sum1)/3;
        }
        cout<<ans<<endl;
    }
}
