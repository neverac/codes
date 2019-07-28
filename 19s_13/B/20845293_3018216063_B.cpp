#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int a[200100]={};
    int cnt1[100100]={};
    int cnt2[100100]={};
    long long sum1=0;
    long long sum2=0;
    cin>>n;
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i];
        if(cnt1[a[i]]==0) cnt1[a[i]]=i;
        else cnt2[a[i]]=i;
    }
    sum1=cnt1[1]-1;
    sum2=cnt2[1]-1;
    for(int i=2;i<=n;i++)
    {
        sum1+=abs(cnt1[i]-cnt1[i-1]);
        sum2+=abs(cnt2[i]-cnt2[i-1]);

    }
    cout<<sum1+sum2;
    return 0;
}
