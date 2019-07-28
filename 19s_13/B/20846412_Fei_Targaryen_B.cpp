#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num,id;
}a[200005];
int vis[200005];
int cmp(node a, node b)
{
    if(a.num==b.num) return a.id<b.id;
    return a.num<b.num;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        cin>>a[i].num;
        a[i].id=i+1;
        vis[i]=0;
    }
    sort(a,a+2*n,cmp);
    long long ans=0;
    int tmp1=1;
    int tmp2=1;
    int d1,d2;
    for(int i=0;i<2*n;i+=2)
    {
        d1=abs(a[i].id-tmp1);
        d1+=abs(a[i+1].id-tmp2);
        d2=abs(a[i].id-tmp2);
        d2+=abs(a[i+1].id-tmp1);
        if(d1<d2)
        {
            ans+=d1;
            tmp1=a[i].id;
            tmp2=a[i+1].id;
        }
        else
        {
            ans+=d2;
            tmp1=a[i+1].id;
            tmp2=a[i].id;
        }
    }
    cout<<ans<<endl;
}
