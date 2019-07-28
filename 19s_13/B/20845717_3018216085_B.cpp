#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;

ll p1[maxn],p2[maxn],arr[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>arr[i];
        if(!p1[arr[i]])p1[arr[i]]=i;
        else p2[arr[i]]=i;
    }
    ll ans=0;
    ll b1=1,b2=1;
    for(int i=1;i<=n;i++){
        ans=ans+abs(p1[i]-b1)+abs(p2[i]-b2);
        b1=p1[i],b2=p2[i];
    }
    cout<<ans<<endl;
}
