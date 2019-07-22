#include<iostream>
#include<algorithm>
using namespace std;

long long n;
long long sum;
long long ans;
long long d[100005];

int main(){
    cin>>n;
    sum=0;
    for(long long i=0;i<n;i++){
        cin>>d[i];
        sum+=d[i];
    }
    sort(d,d+n);
    ans=d[n-1]*sum;
    sum-=d[n-1];
    for(long long i=n-2;i>=0;i--){
        ans+=(d[i+1]+d[i])*sum;
        sum-=d[i];
    }
    cout<<ans<<endl;
    return 0;
}
