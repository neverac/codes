#include <bits/stdc++.h>
using namespace std;
char s[2010];
int a[2010],b[2010];
int main(){
	int n;cin>>n;
	while (n--){
		scanf("%s",s+1);
		int len = strlen(s+1);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (int i=1; i<=len; i++){
			a[i]=a[i-1]+s[i]-'0';
			// printf("%d  ",a[i]);
		}
		if (a[len]==len || a[len]==0){
			puts("0");
			continue;
		}
		// puts("");
		for (int i=len; i; i--){
			b[i]=b[i+1]+s[i]-'0';
			// printf("%d  ",b[i]);
		}
		// puts("");
		int ans=len;
		for (int i=0; i<=len; i++){
			// printf("debug %d %d %d %d\n",i,a[i],len-i,b[i+1]);
			ans=min(ans,a[i]+(len-i-b[i+1]));
		}
		printf("%d\n",ans);
	}
	return 0;
}