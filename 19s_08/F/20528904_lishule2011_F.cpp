#include <iostream>
#include <algorithm>
const int maxn=1e6+100;
using namespace std;
long long a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	int l=1,r=n,cnt=0;
	bool flag=n%2==1?1:0;
	for (int i=1;i<=n;i++)
		if (a[i]<0) cnt++;
	long long ans;
//cout << cnt;
	if(a[1]>=0){
		long long sum=-a[1];
		for(int i=2;i<=n;i++)sum+=a[i];
			cout<<sum<<endl;
		int tot=a[1];
		for(int i=n-1;i>1;i--){
			cout << tot << ' '<<a[i] <<endl;
			tot-=a[i];
		}
		
		cout << a[n]<<' '<<tot <<endl;
		return 0;
	}
	long long sum=a[n]-a[1];
	for(int i=2;i<n;i++)sum+= a[i]>=0?a[i]:-a[i];
	cout<<sum<<endl;
	long long tot=a[1];
	int i;
	for(i=n-1;i>1;i--){
			if(a[i]<0)break;
			cout << tot << ' '<<a[i] <<endl;
			tot-=a[i];
	}
	cout << a[n]<<' '<<tot<<endl;
	tot=a[n]-tot;
	
	while (i>1){
		//printf("%d %d\n",tot,a[i]);
		cout << tot << ' '<< a[i]<<endl;
		tot-=a[i];
		i--;
	}
	if (1) return 0;

	if (cnt<=n/2){
		ans=0;
		for (int i=1;i<=n;i++)
			ans+=i<=n/2?-a[i]:a[i];
		cout << ans << endl;
	// }
		for (;l<r;){
		if (flag){
			flag = 0;
			cout << a[l] << ' ' << a[r]<<endl;
			a[l] = a[l]-a[r--];
		}else{
			flag = 1;
			cout << a[r] << ' ' << a[l]<<endl;
			a[r] = a[r] - a[l++];
		}
	}

	}else{
		if (cnt == n) cnt--;
		ans=0;//puts("fuck");
		for (int i=1;i<=n;i++)
			ans+=i<=cnt?-a[i]:a[i];
		cout << ans << endl;
	// }
		flag=0;
		for (;l<r && l<n-cnt+1;){
		if (flag){
			flag = 0;
			cout << a[l] << ' ' << a[r]<<endl;
			a[l] = a[l]-a[r--];
		}else{
			flag = 1;
			cout << a[r] << ' ' << a[l]<<endl;
			a[r] = a[r] - a[l++];
	}
}
	int tot=flag?a[r]:a[l];
	for (int i=n-cnt+1;i<=cnt;i++){
		cout << tot <<' '<<a[i]<<endl;
		tot-=a[i];
		//cout << "fuck";
	}
}

	
		ans=0;
		for (int i=1;i<=n;i++)
			ans+=i<=n/2?-a[i]:a[i];
		cout << ans << endl;
	// }
	for (;l<r;){
		if (flag){
			flag = 0;
			cout << a[l] << ' ' << a[r]<<endl;
			a[l] = a[l]-a[r--];
		}else{
			flag = 1;
			cout << a[r] << ' ' << a[l]<<endl;
			a[r] = a[r] - a[l++];
		}
	}
}