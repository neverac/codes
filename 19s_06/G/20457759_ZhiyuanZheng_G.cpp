#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200],s[200],f[200][200];

int main(){
	while (cin>>n){
		memset(a,0,sizeof a);
		memset(s,0,sizeof s);
		memset(f,0x3f3f3f3f,sizeof f);
		for (int i=1;i<=n;i++){
			cin>>a[i];
			s[i]=s[i-1]+a[i];
		}
		for (int i=0;i<=n;i++) f[i][i]=0;
		for (int j=1;j<=n;j++){
			for (int i=1;i<=n;i++){
				if (i+j>n) break;
				for (int k=i;k<=i+j;k++){
					f[i][i+j]=min(f[i][k]+f[k+1][i+j]+((s[k]-s[i-1])%100)*((s[i+j]-s[k])%100),f[i][i+j]);
				}
			}
		}
		cout<<f[1][n]<<endl;
	}
	return 0;
} 

