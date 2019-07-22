#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        int f0=0,fop=0;
        if(s[0]=='+'||s[0]=='*')
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        else if(s[0]=='0') f0=1;
        else if(s[0]=='?') s[0]='1';
        int flag=1;
        int n=s.length();
        for(int i=1;i<=n-2;i++)
        {
            if(f0)
            {
                if('0'<=s[i]&&s[i]<='9')
                {
                    cout<<"IMPOSSIBLE"<<endl;
                    flag=0;
                    break;
                }
                else if(s[i]=='?')
                {
                    s[i]='+';
                    fop=1;
                    f0=0;
                }
                else
                {
                    f0=0;
                    fop=1;
                }
            }
            else if(fop)
            {
                if(s[i]=='+'||s[i]=='*')
                {
                    cout<<"IMPOSSIBLE"<<endl;
                    flag=0;
                    break;
                }
                else if(s[i]=='?')
                {
                    s[i]='1';
                    fop=0;
                    f0=0;
                }
                else if(s[i]=='0')
                {
                    fop=0;
                    f0=1;
                }
                else
                {
                    fop=0;
                    f0=0;
                }
            }
            else
            {
                if(s[i]=='?') s[i]='1';
                else if(s[i]=='+'||s[i]=='*')
                {
                    fop=1;
                    f0=0;
                }
                else
                {
                    f0=0;
                    fop=0;
                }
            }
        }
        if(flag)
        {
            if(f0)
            {
                cout<<"IMPOSSIBLE"<<endl;
                flag=0;
            }
            else if(s[n-1]=='?') s[n-1]='1';
            else if(s[n-1]=='+'||s[n-1]=='*')
            {
                cout<<"IMPOSSIBLE"<<endl;
                flag=0;
            }
            if(flag) cout<<s<<endl;
        }
    }
    return 0;
}
