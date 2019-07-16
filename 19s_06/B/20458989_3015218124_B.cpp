#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#include<time.h>

using namespace std;

int n;
long long t,gg,ans;
long long a1=0,a2=1e9;
long long a[30];

long long gcd(long long a,long long b)
{
    long long c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    srand((int)time(0));
    cin>>n;
    while(a1<a2)
    {
        long long mid=(a1+a2)/2;
        cout<<"> "<<mid<<endl;
        cout.flush();
        cin>>t;
        if(t==0) a2=mid;
        else a1=mid+1;
    }
    int cnt1=0;
    for(int i=0;i<25;i++)
    {
        long long int k=(long long)rand()*rand()%n+1;
        cout<<"? "<<k<<endl;
        cout.flush();
        cin>>t;
        a[cnt1]=t;
        cnt1++;
    }
    sort(a,a+cnt1);
    if(cnt1==1)
    {
        cout<<"! "<<a1<<' '<<0<<endl;
    }
    else
    {   gg=a[1]-a[0];
        for(int i=1;i<cnt1;i++)
            gg=gcd(gg,a[i]-a[i-1]);
        ans=a1-(n-1)*gg;
        cout<<"! "<<ans<<' '<<gg<<endl;
    }
    return 0;
}
