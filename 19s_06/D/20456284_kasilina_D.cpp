#include <bits/stdc++.h>
using namespace std;
int x,y,z,a,b,c;
int main()
{
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&a,&b,&c);
	a-=x;
	if(a<0) {
	cout << "NO" << endl;
	return 0;
	}
	if(a) y-=a;
	if(b<y) 
	{
		cout << "NO" << endl;
		return 0;
	}
	else b-=y;
	if(b) z-=b;
	if(c<z)
	{
		cout << "NO" << endl;
		return 0;
	}
	else
	cout << "YES" << endl;
    return 0;
}