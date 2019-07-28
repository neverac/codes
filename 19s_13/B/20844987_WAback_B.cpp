#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int SIZEN = 200010;
int N,M;
struct Node{
	int data,loc;
	Node(int x,int y){
		data = x;
		loc = y;
	}
	Node(){;}
	bool operator < (const Node &A)const{
		if(data != A.data)return data  < A.data;
		else return loc < A.loc;
	}
}a[SIZEN];
LL F[SIZEN] = {0};
int main(){
	scanf("%d",&N);
	for(int i = 1;i <= 2*N;i++){
		int b;
		scanf("%d",&b);
		a[i] = Node(b,i);
	}
	sort(a+1,a+1+2*N);
	F[1] = a[1].loc + a[2].loc - 2;
	for(int i = 2;i <= N;i++){
		LL x1 = a[i*2-1].loc,y1 = a[i*2].loc;
		LL x2 = a[(i-1)*2-1].loc,y2 = a[(i-1)*2].loc;
		F[i] = min(F[i-1] + abs(x1 - x2) + abs(y1 - y2),F[i-1] + abs(x1-y2) + abs(y1-x2));
	}
	printf("%lld\n",F[N]);
	return 0;
}
/*
3
1 1 2 2 3 3
*/