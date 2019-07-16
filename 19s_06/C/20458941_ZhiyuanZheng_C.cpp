#include <bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+100;
int n,m,k;
struct node{
	int x;
	int num;
}a[maxn];
bool cmp(node x,node y){
	return x.x>y.x;
}
bool cmp2(node x,node y){
	return x.num<y.num;
}
int main(){
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) cin>>a[i].x;
	for (int i=1;i<=n;i++) a[i].num=i;
	sort(a+1,a+1+n,cmp);
	long long ans=0;
	for (int i=1;i<=m*k;i++)
		ans+=a[i].x;
	cout<<ans<<endl;
	sort(a+1,a+1+m*k,cmp2);
	for (int i=m;i<m*k;i+=m){
		cout<<a[i].num<<" ";
	}
	cout<<endl;
	return 0;
}

