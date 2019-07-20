#include <bits/stdc++.h>
using namespace std;
int n;
int a[500005];
queue<int> Q[7];
int main(){
    cin >> n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);	
    	if(a[i]==4)
    	{
    		Q[1].push(i);
		}
		else if(a[i]==8)
		{
			Q[2].push(i);
		}
		else if(a[i]==15)
		{
			Q[3].push(i);
		}
		else if(a[i]==16)
		{
			Q[4].push(i);
		}
		else if(a[i]==23)
		{
			Q[5].push(i);
		}
		else
		{
			Q[6].push(i);
		}
	}
	int s;
	int cnt=0;
	bool f=0;
	while(!Q[1].empty())
	{
		s=Q[1].front();
		Q[1].pop();
		for(int i=2;i<=6;i++)
		{
			if(Q[i].empty())
			{
				f=1;
				break;
			}
			while(Q[i].front()<s&&!Q[i].empty())
			Q[i].pop();
			if(Q[i].empty()) 
			{
				f=1;break;
			}
			s=Q[i].front();
			Q[i].pop();
		}
		if(f) break;
		cnt++;
	}
	cout << n-cnt*6 << endl;
    return 0;
}
