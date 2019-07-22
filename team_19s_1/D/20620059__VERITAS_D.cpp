#include <bits/stdc++.h>
#include <string.h>
#define ll long long

using namespace std ;

ll m,ans,c,w,t,n,a[110],top;
int main(){
    cin >> t;
    while(t--){
        ans=1;top=1;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            cin >> c >> w;
            a[i]=c+w;
        }
        sort(a+1,a+n+1);
        while(ans*a[top]<=m && top<=n){
            ans*=a[top];
            top++;
        }
        cout << top-1 << endl;
    }
    return 0;
}
