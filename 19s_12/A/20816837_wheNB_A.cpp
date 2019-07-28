#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int p,q;
int vis[1000005];
int a[15];
int main()
{
	scanf("%d%d",&p,&q);
	p*=10;
	while(1)
	{
		a[p/q]=1;
		int r=p%q;
		if(vis[r]||r==0)
		break;
		vis[r]=1;
		r*=10;
		p=r;
	}
	for(int i=0;i<10;i++)
	{
		if(a[i])
		cout << i;
	}
	cout << endl;
    return 0;
}