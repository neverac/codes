#include<bits/stdc++.h>
using namespace std;
const int maxn=5000005;
//int a[1000005];
int num[10];
int main()
{
    int p,q;
    cin>>p>>q;
    for(int i=0;i<maxn;i++)
    {
        int tmp=p*10/q;
        num[tmp]++;
        p=p*10%q;
    }
    for(int i=0;i<10;i++)
    {
        if(num[i]) cout<<i;
    }
    cout<<endl;
}
