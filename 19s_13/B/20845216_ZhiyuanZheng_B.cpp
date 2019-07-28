#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int n;
struct node{
	int n,pos;
}a[2*maxn];

bool cmp(node x,node y){
	if (x.n==y.n) return x.pos<y.pos;
	return x.n<y.n;
}
int main(){
	cin>>n;
	for (int i=1;i<=2*n;i++) {
		cin>>a[i].n;
		a[i].pos=i;	
	}
	sort(a+1,a+1+2*n,cmp);
	int cnt=1;
	long long ans=0,p1=1,p2=1;
	while (cnt<=2*n){
		int d11=abs(p1-a[cnt].pos);
		int d21=abs(p2-a[cnt].pos);
		int d12=abs(p1-a[cnt+1].pos);
		int d22=abs(p2-a[cnt+1].pos);
		if (d11+d22<=d21+d12) {
			ans+=d11+d22;
			p1=a[cnt].pos;
			p2=a[cnt+1].pos;
		}else {
			ans+=d21+d12;
			p1=a[cnt+1].pos;
			p2=a[cnt].pos;	
		}
		cnt+=2;
	}
	cout<<ans<<endl;
	return 0;
}
