#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    int a[100100]={};
    int b[100100]={};
    int cnt1=0;int cnt2=0;
    cin>>n;
    int te1=-1;int te2=-1;int te3=-1;int te4=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int bo=1;int b2=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])
        {
            cnt1++;
            if(te1==-1)  te1=i;
            else te2=i;
        }
        if(cnt1>2)
        {
            bo=0;
            break;
        }
    }
    if(cnt1>0) bo=0;
    if(bo==0)
    {
        sort(b+1,b+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=b[i])
            {
                cnt2++;
                if(te3==-1)  te3=i;
                else te4=i;
            }
            if(cnt2>2)
            {
                b2=0;
                break;
            }
        }
    }
    else
    {
        cnt2=-1;
    }
    int b3=0;
    if((cnt1==0||cnt2==0)&&b3==0)
    {
        cout<<"Nothing to do here";
        b3=1;
    }
    else if(cnt1==2&&b3==0)
    {
        cout<<"Yes"<<endl;
        cout<<te1<<" "<<te2;
        b3=1;
    }
    else if(cnt2==2&&b3==0)
    {
        cout<<"Yes"<<endl;
        cout<<te3<<" "<<te4;
        b3=1;
    }
    else if(cnt1>2&&cnt2>2&&b3==0)
    {
        cout<<"No hope";
    }
   // cout<<cnt1<<" "<<cnt2;
    return 0;
}
