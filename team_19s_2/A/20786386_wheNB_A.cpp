#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d;
int a[1005];
int ans[10];
int main(){
    while(scanf("%d",&n)!=EOF&&n)
    {
    	scanf("%d",&d);
    	int t=0;
    	for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    	bool f1=0;
    	bool f2=1;
    	for(int i=2;i<=n;i++)
    	{
    		if(a[i]-a[i-1]>d)
    		ans[t++]=i;
    		if(t>2) break;
		}
		if(t>2) cout << "N" << endl;
		else if(t==2)
		{
			if(ans[0]+1==ans[1]&&abs(a[ans[0]-1]-a[ans[1]])<=2*d) cout << "Y" << endl;
			else cout << "N" << endl; 
		}
		else if(t==1)
		{
			if(ans[0]==2||ans[0]==n)
			cout << "Y" << endl;
			else if(abs(a[ans[0]-1]-a[ans[0]+1])<=2*d||abs(a[ans[0]-2]-a[ans[0]])<=2*d)
			cout << "Y" << endl;
			else cout << "N" << endl;
		}
		else cout << "Y" << endl;
	}
    return 0;
}



 