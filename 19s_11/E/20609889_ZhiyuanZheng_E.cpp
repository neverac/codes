#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int h,pos;
};
node a[110000],b[110000];
bool cmp(node x,node y){
	if (x.h!=y.h) return x.h<y.h;
	return x.pos<y.pos;
}
bool cmp2(node x,node y){
	if (x.h!=y.h) return x.h>y.h;
	return x.pos<y.pos;
}
int main(){
	cin>>n;
	int w=0,e=0;
	for (int i=1;i<=n;i++){
		cin>>a[i].h;
		a[i].pos=i;
		b[i]=a[i];
		if (a[i].h>=a[i-1].h&&i!=1) w++;
		if (a[i].h<=a[i-1].h&&i!=1) e++;
	}
	if (w==n-1||e==n-1) cout<<"Nothing to do here"<<endl;
	else {
		int k1=0,k2=0;
		sort(a+1,a+1+n,cmp);
		int p1=0,p2=0;
		for (int i=1;i<=n;i++){
			if (a[i].h!=b[i].h) {
				k1++;
				if (p1==0) p1=i;
				else p2=i;
			} 
		}
		if (k1==2){
			cout<<"Yes"<<endl;
			cout<<p1<<" "<<p2<<endl;
			return 0;
		}else {
			p1=0,p2=0;
			sort(a+1,a+1+n,cmp2);
			for (int i=1;i<=n;i++){
			if (a[i].h!=b[i].h) {
				k2++;
				if (p1==0) p1=i;
				else p2=i;
			} 
		}
		if (k2==2){
			cout<<"Yes"<<endl;
			cout<<p1<<" "<<p2<<endl;
			return 0;
		} else {
			cout<<"No hope"<<endl;
		}
		}
	}
	return 0;
}

