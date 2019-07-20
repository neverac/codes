#include<bits/stdc++.h>
#define  MAX 100005
#define  MOD 1000000007
#define ll long long
using namespace std;

int main() {
    ll k,a,b,ans=1,yen=0;
    cin>>k>>a>>b;
    if(b-a<2){
        ans=ans+k;
    }
    else{
        while(k){
            if(yen==0){
                if(ans<a)
                    while(ans<a&&k)ans++,k--;
                if(ans>=a&&k>1)ans-=a,yen++,k--;
                else if(k==1)ans++,k--;

            }
            while(yen&&k){
                ans+=b;yen--;k--;
            }
        }
    }
    cout<<ans<<endl;
}
