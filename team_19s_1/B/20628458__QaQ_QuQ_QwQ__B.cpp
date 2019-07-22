#include <stdio.h>
#include <algorithm>
#include <cmath>
#include<iostream>
using namespace std;
const int mod=1000000007;
const int N=100005;
long long int a[N],b[N];
int t,num;

struct node 
{
    int l,r,no;
    long long int ans;
} q[N];

int cmp(node a, node b) 
{	
    return a.l/num==b.l/num?a.r<b.r:a.l<b.l;
} 

long long int ksm(long long int a, long long int b) 
{
    long long int ans = 1;
    while(b) 
	{
        if (b&1) 
		ans=ans*a%mod;
        a=a*a%mod;
        b=b>>1;
    }
    return ans;
} 

void niyuan() 
{
    a[1] = 1;
    for (int i=2;i<N;i++) 
	a[i]=(a[i-1]*i)%mod;//求阶乘
	 
    for (int i=1;i<N;i++) 
	b[i]=ksm(a[i],mod-2);
} //求逆元 

long long int zhs(int n,int m) 
{
    if (n<0||m<0||m>n) 
	return 0;
    if (m==n||m==0) 
	return 1;
    return a[n]*b[m]%mod*b[n-m]%mod;
}//组合数 

int main() 
{
	int i,t;
    niyuan();
    scanf("%d",&t);
    for (i=1;i<=t;i++) 
	{
        scanf("%d%d",&q[i].l,&q[i].r); 
        q[i].no=i,q[i].ans=0;
    }
    
    num = sqrt(N); 
    sort(q+1,q+1+t,cmp);
    
    long long int ans = 1;
    int l=1,r=0;
    for (i=1;i<=t;i++) 
	{
        while(l<q[i].l) 
		{
			ans=(2*ans-zhs(l,r)+mod)%mod;
			l++;
		}
        while(l>q[i].l) 
		{
			ans=(ans+zhs(l-1,r))%mod*b[2]%mod;
			l--;
		}
        while(r<q[i].r) 
		{
			ans=(ans+zhs(l,r+1))%mod;
			r++;
		}
        while(r>q[i].r) 
		{
			ans=(ans-zhs(l,r)+mod)%mod;
			r--;
		}
        q[q[i].no].ans=ans;
    }
    for (i=1;i<=t;i++) 
	printf("%lld\n",q[i].ans);
    return 0;
}