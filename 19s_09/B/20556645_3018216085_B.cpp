#include<bits/stdc++.h>
#define  MAX 100005
#define  MOD 998244353
#define ll long long
using namespace std;

int main(){
    ll n;
    string s;
    cin>>n>>s;
    ll ans=0;
    ll len1=1,len2=1;
    while(len1<n&&s[len1]==s[0])len1++;
    while(len2<n&&s[n-1-len2]==s[n-1])len2++;
        ans=(len1+len2+1)%MOD;
    if(s[0]==s[n-1]){
        ans=(ans+len1*len2)%MOD;
    }
    cout<<ans%MOD<<endl;
}
