#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n;
    cin>>n;
    int p=0,m=0,n0=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>0) p++;
        else if(a[i]<0) m++;
        else n0++;
    }
    int num=ceil(n*1.0/2.0);
    if(p>=num) cout<<1<<endl;
    else if(m>=num) cout<<-1<<endl;
    else cout<<0<<endl;
    return 0;
}
