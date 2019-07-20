#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e6+100;

long long A,B,k,ans,res;

int main()
{
	cin>>k>>A>>B;
	ans = k+1;
	if(B<=A){
		cout<<ans<<endl;
		return 0;
	}
	k = k-(A-1);
	if(k<=0){
		cout<<ans<<endl;
		return 0;
	}
	long long sum = k/2;
	res=A;
	res += sum*(B-A);
	if(k&1) res++;
	cout<<max(res,ans)<<endl;
	return 0;
}
/*
7 3 4
 */