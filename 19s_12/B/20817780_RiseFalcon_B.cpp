#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=998244353;
const int MAXN=1E6+10;
const int INF=~0U>>1;
const TYPE x=13;
int input() {
	int x;scanf("%d",&x);
	return x;
}
char s[MAXN];
TYPE pw[MAXN],h[MAXN],f[MAXN];
TYPE code(int l,int r) {
	if(r<l)return 0;
	return (h[r]+mod-h[l-1]*pw[r-l+1]%mod)%mod;
}
TYPE rode(int l,int r) {
	if(r<l)return 0;
	return (f[l]+mod-f[r+1]*pw[r-l+1]%mod)%mod;
}
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	pw[0]=1;
	for(int i=1;i<=n;++i) {
		pw[i]=pw[i-1]*x%mod;
		h[i]=(h[i-1]*x%mod+s[i])%mod;
	} 
	for(int i=n;i>=1;--i) {
		f[i]=(f[i+1]*x%mod+s[i])%mod;
	}
	//printf("%lld %lld\n",(code(1,3)*pw[1]%mod+code(4,4))%mod,rode(5,8));
	if(n%2==1) {
		int mid=(n+1)/2,ans=n+1;
		for(int i=1;i<=mid-1;++i) {
			TYPE hl=(code(1,i-1)*pw[mid-i]%mod+code(i+1,mid))%mod;
			TYPE hr=rode(mid+1,n);
			if(hl==hr) {
				ans=std::min(i,ans);
			}
		}
		if(code(1,mid-1) == rode(mid+1,n)) {
			ans=std::min(mid,ans);
		}
		for(int i=mid+1;i<=n;++i) {
			TYPE hl=code(1,mid-1);
			TYPE hr=(rode(mid,i-1)+rode(i+1,n)*pw[i-mid]%mod)%mod;
			if(hl==hr) {
				ans=std::min(i,ans);
			}
		}printf("%d\n",ans);
	}
	else if(n%2==0) {
		int mid=(n+2)/2,ans=n+1;
		for(int i=1;i<=mid-1;++i) {
			TYPE hl=(code(1,i-1)*pw[mid-i-1]%mod+code(i+1,mid-1))%mod;
			TYPE hr=rode(mid+1,n);
			if(hl==hr) {
				ans=std::min(i,ans);
			}
		}
		if(code(1,mid-2) == rode(mid+1,n)) {
			ans=std::min(mid,ans);
		}
		for(int i=mid+1;i<=n;++i) {
			TYPE hl=code(1,mid-2);
			TYPE hr=(rode(mid,i-1)+rode(i+1,n)*pw[i-mid]%mod)%mod;
			if(hl==hr) {
			//	printf("%d\n",mid);
				ans=std::min(i,ans);
			}
		}printf("%d\n",ans);
	}
	return 0;
}
