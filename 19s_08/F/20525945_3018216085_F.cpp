#include<bits/stdc++.h>
#define  MAX 100005
#define  MOD 1000000007
#define ll long long
using namespace std;

ll arr[100005];

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+1+n);
    ll ans=arr[n]-arr[1];
    for(int i=2;i<n;i++){
        if(arr[i]>0)ans+=arr[i];
        else ans-=arr[i];
    }
    cout<<ans<<endl;
    for(int i=2;i<n;i++){
        if(arr[i]>0){
            cout<<arr[1]<<" "<<arr[i]<<endl;
            arr[1]-=arr[i];
        }else{
            cout<<arr[n]<<" "<<arr[i]<<endl;
            arr[n]-=arr[i];
        }
    }
    cout<<arr[n]<<" "<<arr[1]<<endl;arr[n]-=arr[1];
}
