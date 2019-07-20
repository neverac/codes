#include<bits/stdc++.h>
#define  MAX 100005
#define  MOD 998244353
#define ll long long
using namespace std;

int main(){
    int t,a;

    cin>>t;
    while(t--){
        cin>>a;
        int i=a;
        for(;i>=1;i--){
            if(180%i==0&&a%i==0)break;
        }
        int t=180/i;
        if(a>180-360/t)cout<<2*t<<endl;
        else cout<<t<<endl;
    }

}
