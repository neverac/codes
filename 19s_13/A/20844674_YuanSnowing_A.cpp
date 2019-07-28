#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cnp,cnn,n,x;
int main(){
	scanf("%d",&n);
	for(int i = 0;i <n;i ++){
		scanf("%d",&x);
		if(x>0) cnp ++;
		if(x < 0) cnn ++;
	} 
	if(cnp*2>=n) cout << 1;
	else if(cnn*2>=n) cout << -1;
	else cout<<0;
	return 0;
}
