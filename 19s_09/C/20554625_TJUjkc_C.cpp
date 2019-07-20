#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int t;
int ang;
int n;

int gcd(int a,int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    cin>>t;
    while(t--){
        cin>>ang;
        int cnt=0;
        for(int i=3;i<=180;i++){
            if(i*ang%180==0){
                cnt=i;
                break;
            }
        }
        n=cnt;
        while(ang>(n-2)*180/n){
            n+=cnt;
        }
        cout<<n<<endl;
    }
    return 0;
}
