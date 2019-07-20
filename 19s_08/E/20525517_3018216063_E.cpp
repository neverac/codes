#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,t;

    cin>>t;
    while(t--)
    {
        int a[110]={};
    int b[110]={};
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i]%3;
            if(b[i]==1) cnt1++;
            else if(b[i]==2) cnt2++;
            else if(b[i]==0) cnt3++;
        }
        if(cnt1>cnt2) cout<<cnt3+cnt2+(cnt1-cnt2)/3<<endl;
        else if(cnt2>cnt1) cout<<cnt3+cnt1+(cnt2-cnt1)/3<<endl;
        else if(cnt2==cnt1) cout<<cnt3+cnt1<<endl;
  /*      for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(b[i]==1&&b[j]==2)
                {
                    b[i]+=b[j];
                    b[j]=0;
                }
                else if()
            }
        }*/
    }
    return 0;
}
