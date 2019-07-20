#include<iostream>

using namespace std;

long long a,b,k;
//long long check=48518828981938099;


int main(){
    cin>>k>>a>>b;
    if(a>=b-2) cout<<1+k<<endl;
    else{
        if(k<=a-1){
            cout<<1+k<<endl;
        }
        else{
            long long ans=(k-a+1)/2*(b-a)+a;
            if((k-a+1)%2!=0) ans++;
            //cout<<ans-check<<endl;
            cout<<ans<<endl;
        }
    }
    return 0;
}
