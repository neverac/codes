#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int t;
    cin>>t;
    int ang;
    while(t--)
    {
        cin>>ang;
        int g=gcd(180,ang);
        int i=ang/g;
        int n=180/g;
        if(n-i<=0) cout<<-1<<endl;
        else if(n-i==1) cout<<2*n<<endl;
        else cout<<n<<endl;
    }
}
