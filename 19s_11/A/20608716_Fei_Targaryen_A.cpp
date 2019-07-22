#include<bits/stdc++.h>
using namespace std;
int w[100005];
int main()
{
    int n;
    cin>>n;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
        sum+=w[i];
    }
    sort(w,w+n);
    long long ans=0;

    for(int i=n-1;i>=0;i--)
    {
        ans+=sum*w[i];
        ans+=(sum-w[i])*w[i];
        sum-=w[i];
    }
    cout<<ans<<endl;
}
