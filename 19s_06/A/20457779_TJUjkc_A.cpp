#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long n,b,ans;

int main(){
    cin>>n>>b;
    ans=1000000000000000005;
    for(long long i=2;i<=b;i++){
        if(i>sqrt(b)) break;
        if(b%i==0){
            long long cnt=0;//因子i次数
            while(b%i==0){
                cnt++;
                b=b/i;
            }
            long long cnt2=0;
            long long num=i;
            while(num<=n){
                cnt2+=n/num;
                if(num>n/i) break;
                num*=i;
            }
            cnt2=cnt2/cnt;
            ans=min(cnt2,ans);
        }
    }
    if(b!=1){
        long long cnt=0;
        long long num=b;
        while(num<=n){
                cnt+=n/num;
                if(num>n/b) break;
                num*=b;
            }
        ans=min(cnt,ans);
    }
    if(ans==1000000000000000005) cout<<0<<endl;
    else cout<<ans<<endl;
    return 0;
}
