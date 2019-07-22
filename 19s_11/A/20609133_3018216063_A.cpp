#include <iostream>
#include <algorithm>
using namespace std;
/*struct node
{
    int in,d,cos;
}e[10100];
bool cmp(node a,node b)
{
    if(a.cos==b.cos) return a.in>b.in;
    else return a.d<b.d;
}*/
int main()
{
    int n;
    int d[101000]={};

    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       // cin>>e[i].d; //e[i].in=i;
//e[i].cos=e[i].d*i;
        cin>>d[i];
        ans+=d[i];
    }
    sort(d+1,d+n+1);
    long long sum=0;
    for(int i=n;i>0;i--)
    {
        sum+=ans*d[i];
        ans-=d[i];
        sum+=ans*d[i];//cout<<e[i].in<<endl;
    }
    cout<<sum;
    return 0;
}
