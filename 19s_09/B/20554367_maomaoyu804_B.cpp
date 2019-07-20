#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    long long n;
    string s;
    cin>>n>>s;
    long long p1=0,p2=n-1;
    while(s[p1]==s[p1+1]) p1++;
    while(s[p2]==s[p2-1]) p2--;
    p2=n-p2;
    p1=p1+1;
    long long ans=0;
    if(s[0]==s[n-1]) ans=(p1+1)*(p2+1);
    else{
        ans=p1+p2+1;
    }
    cout<<ans%998244353<<endl;
    return 0;
}
