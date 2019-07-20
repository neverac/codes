#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n;
string str;
int main(){
    IO;
    cin >> n;
    cin >> str;
    int i,j;
    for(i=1;i<n&&str[i]==str[i-1];i++);
    for(j=n-2;j>=0&&str[j]==str[j+1];j--);j++;
    j=n-j;
    if(i==n) cout << (1ll*n*(n+1)/2)%mod << endl;
    else if(str[0]==str[n-1]) cout << (1ll*i*j+i+j+1)%mod << endl;
    else cout << (i+j+1)%mod << endl;
    return 0;
}
