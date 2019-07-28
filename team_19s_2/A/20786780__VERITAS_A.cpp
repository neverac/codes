#include <bits/stdc++.h>
#define maxn 500005
#define ll long long
using namespace std;

int n,cnt,d,arr[10005];
int main()
{
    while(cin>>n&&n){
        cin>>d;
        cnt=0;
        cin>>arr[1];
        for(int i=2;i<=n;i++){
            cin>>arr[i];
            if(abs(arr[i]-arr[i-1])>d){
                cnt++;
                if(cnt==2&&abs(arr[i]-arr[i-2])>2*d)cnt++;
            }
        }
        if(cnt==2&&abs(arr[n]-arr[n-1])>d&&abs(arr[2]-arr[1])>d){
            if(n!=3){
                cnt++;
            }
        }
        if(cnt<=2)cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
}
