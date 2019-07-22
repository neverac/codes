#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

ll arr[100005];
int main(){
    ll n,cnt=0,ans=0;
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>arr[i],cnt+=arr[i];
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++){
        ans+=arr[i]*cnt+arr[i]*(cnt-arr[i]);
        cnt-=arr[i];
    }
    cout<<ans<<endl;

}

