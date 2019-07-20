#include<iostream>
#include<algorithm>
#include<cmath>
#include<memory.h>
using namespace std;

long long mod=998244353;
long long ans;
long long n;
string s;

int main(){
    ans=0;
    cin>>n;
    cin>>s;
    char first=s.at(0);
    char last=s.at(n-1);
    long long cntf=0;
    long long cntl=0;
    for(long long i=0;i<n;i++){
        if(s.at(i)==first) cntf++;
        else break;
    }
    for(long long i=n-1;i>=0;i--){
        if(s.at(i)==last) cntl++;
        else break;
    }
    if(first!=last){
        ans=(1+cntf+cntl)%mod;
    }
    else{
        if(cntf+cntl>=n){
            ans=((cntf+1)*cntf/2)%mod;
        }
        else{
            ans=((cntf+1)*(cntl+1))%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
