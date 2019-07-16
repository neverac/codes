#include <bits/stdc++.h>
using namespace std;
char s[2010];
int a[2010][1010],b[2010][1010],n;
int l[1010][1010],r[1010][1010],h[1010][1010];

inline bool check(int x){
	for (int i=1; i<=n-x+1; i++){
		for (int j=1; j<=n-x+1; j++){
			bool flag=1;
			// printf("debug %d %d %d\n",i,j,x);
			for (int l=0; l<x; l++){
				if (!flag) break;
				for (int r=0; r<x; r++){
					if ( (l==0 || a[l+i-1][r+j]+1==a[l+i][r+j])&&(r==0 || a[l+i][r+j-1]+1==a[l+i][r+j]) )
						continue;
					else{
						flag=0;
						break;
					}
				}
			}
			if (flag) {
				// printf("good %d %d %d\n",i,j,x);
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	cin>>n;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	int l=1,r=n,ans=1;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid)) ans=max(ans,mid),l=mid+1;
		else r=mid-1;
	}
    printf("%d\n",ans);
	return 0;
}