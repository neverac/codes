#include<bits/stdc++.h>
using namespace std;
int s0[1005],s1[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int ls=s.length();
        memset(s0,0,sizeof(s0));
        memset(s1,0,sizeof(s1));
        int sum0=0;
        int sum1=0;
        if(s[0]=='0')
        {
            s0[0]++;
            sum0++;
        }
        else
        {
            s1[0]++;
            sum1++;
        }
        for(int i=1;i<ls;i++)
        {
            if(s[i]=='0')
            {
                s0[i]=s0[i-1]+1;
                s1[i]=s1[i-1];
                sum0++;
            }
            else
            {
                s0[i]=s0[i-1];
                s1[i]=s1[i-1]+1;
                sum1++;
            }
        }
        if(sum0==0||sum1==0) cout<<0<<endl;
        else
        {
            int dp=10005;
            for(int i=0;i<ls;i++)
            {
                dp=min(dp,s1[i]+sum0-s0[i]);
                //cout<<s0[i]<<" "<<s1[i]<<endl;
            }
            //cout<<sum0<<sum1<<endl;
            int ans=min(sum0,sum1);
            dp=min(dp,ans);
            cout<<dp<<endl;
        }
    }
    return 0;
}
