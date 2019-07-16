#include <bits/stdc++.h>
using namespace std;
int t;
char s[1005];
long long dfs(int i,int j)
{
	if(i>j) return 0;
	while(s[i]=='0') i++;
	while(s[j]=='1') j--;
	if(i>j) return 0;
	int ans1=0;
	int ans2=0;
	for(int k=i;k<=j;k++)
	{
		if(s[k]=='0') ans1++;
		else ans2++; 
	}
	if(ans1==1||ans2==1) return 1;
	if(ans1<=ans2) return 1+dfs(i,j-1);
	else return 1+dfs(i+1,j);
}
int main()
{
    cin >> t;
    while(t--)
    {
    	scanf("%s",&s);
    	long long ans=dfs(0,strlen(s)-1);
    	int ans1=0;
		int ans2=0;
		for(int k=0;k<strlen(s);k++)
		{
			if(s[k]=='0') ans1++;
			else ans2++; 
		}
		if(ans>min(ans1,ans2))
		{
			cout << min(ans1,ans2) << endl;
		}
		else cout << ans << endl;
	}
	return 0;
}