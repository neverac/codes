#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct node
{
    int id;ll s;
};
node num[200005];
int ans[200005];
int cmp1(node a,node b)
{
    return a.s>b.s;
}
int cmp2(node a,node b)
{
    return a.id<b.id;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) {scanf("%lld",&num[i].s);num[i].id=i;}
    sort(num,num+n,cmp1);
    int temp=m*k;
    ll sum=0;
    for(int i=0;i<temp;i++){
        sum+=num[i].s;
        ans[i]=num[i].id;
    }
    sort(ans,ans+temp);
    //for(int i=0;i<temp;i++) cout<<ans[i]<<endl;
    cout<<sum<<endl;
    for(int i=m-1;i<temp-1;i+=m) cout<<ans[i]+1<<" ";
    return 0;
}
