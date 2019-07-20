#include<bits/stdc++.h>
using namespace std;
long long  const maxn=998244353;
long long n,ans=0;
string s;
void work(){
	long long qian=1,wei=1,hou=1,wei2=n-2;
	while(wei<n&&s[wei]==s[wei-1])qian++,wei++;
	while(wei2>=0&&s[wei2]==s[wei2+1])hou++,wei2--;
	ans=(ans+hou+1)%maxn;
	//cout<<qian<<' '<<hou<<endl;
	if(s[0]!=s[n-1]){
		ans=(ans+qian)%maxn;
		return ;
	}
	else {
		ans=(ans+(qian*(hou+1))%maxn)%maxn;
	}
}
int main(){
	scanf("%lld",&n);
	cin>>s;
	work();
	cout<<ans<<endl;
	return 0;
}