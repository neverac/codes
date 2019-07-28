#include <iostream>

using namespace std;

int main()
{
    int n;
    int a[110]={};
    int sum1=0;
    int sum2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>0) sum1++;
        else if(a[i]<0) sum2++;
    }
    if(n%2==0)
    {
        if(sum1>=n/2) cout<<"1";
        else if(sum2>=n/2) cout<<"-1";
        else cout<<"0";
    }
    else if(n%2==1)
    {
        if(sum1>=n/2+1) cout<<"1";
        else if(sum2>=n/2+1) cout<<"-1";
        else cout<<"0";
    }
    return 0;
}
