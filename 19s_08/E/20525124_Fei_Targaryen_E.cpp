#include<bits/stdc++.h>
using namespace std;
int a[105],num[3];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            a[i]%=3;
            num[a[i]]++;
        }
        //cout<<num[0]<<num[1]<<num[2]<<endl;
        int ans=num[0];
        if(num[1]>num[2])
        {
            ans+=num[2];
            num[1]-=num[2];
            ans+=num[1]/3;
        }
        else
        {
            ans+=num[1];
            num[2]-=num[1];
            ans+=num[2]/3;
        }
        cout<<ans<<endl;
    }
}
