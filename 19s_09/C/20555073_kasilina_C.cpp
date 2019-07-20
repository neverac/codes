#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int t;
int gcd(int a,int b)
{
	if(a<b) swap(a,b);
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
bool f;
int main(){
	cin >> t;
	while(t--)
	{ 
		f=0;
		scanf("%d",&n);
		int k;
		int p=gcd(n,180);
		int c=n/p;
		int q=180/p;
		for(int i=c;i<998244353;i+=c)
		{
			k=i/c*q;
			if((long long)(k-2)*180/k>=n)
			{
				cout << k << endl;
				f=1;
				break;
			}
		}
		if(!f)
		cout << -1 << endl;
	}
	return 0;
}
