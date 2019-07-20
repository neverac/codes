#include <bits/stdc++.h>
using namespace std;
int n;
int a[100100];
struct node {
	int x,y;
}s[100100];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	int cnt=0,ans=0;
	sort(a+1,a+1+n);
	if (a[1]>=0){
	 	ans=a[1];
		for (int i=2;i<n;i++){
			s[++cnt].x=ans;
			s[cnt].y=a[i];
			ans=ans-a[i];
		}
		s[++cnt].x=a[n];
		s[cnt].y=ans;
		ans=a[n]-ans;
	}else if (a[n]<=0){
		ans=a[n];
		for (int i=n-1;i>=1;i--){
			s[++cnt].x=ans;
			s[cnt].y=a[i];
			ans=ans-a[i];
		}
	}
	if (a[1]<0&&a[n]>0){
		int w=1;
		while (a[w]<=0) w++;
		w--;
		for (int i=1;i<=n;i++)
			ans+=abs(a[i]);
		int ans1=a[1];
		for (int i=w+1;i<n;i++){
			s[++cnt].x=ans1;
			s[cnt].y=a[i];
			ans1=ans1-a[i];
		}
		int ans2=a[n];
		for (int i=2;i<=w;i++){
			s[++cnt].x=ans2;
			s[cnt].y=a[i];
			ans2=ans2-a[i];
		}
		s[++cnt].x=ans2;
		s[cnt].y=ans1;
			
	}

	cout<<ans<<endl;
	for (int i=1;i<=cnt;i++)
		cout<<s[i].x<<" "<<s[i].y<<endl;
	return 0;
}