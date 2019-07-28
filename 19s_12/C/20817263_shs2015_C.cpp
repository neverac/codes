#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int SIZEN = 200010;
int N,M;
struct Node{
	int data,id;
	Node(int x,int y){
		data = x;
		id = y;
	}
	Node(){;}
	bool operator < (const Node &A)const{
		if(data != A.data)return data < A.data;
		return id < A.id;
	}
}t[SIZEN];
int tot = 0;
int sum[SIZEN] = {0},cnt = 0;
bool Check(int x){
	memset(sum,0,sizeof sum);
	cnt = 0;
	int p = 0;
	for(int i = 1;i <= tot;i++){
		while(t[p+1].data <= t[i].data + x && p+1 <= tot){
			p++;
			sum[t[p].id]++;
			if(sum[t[p].id] == 1)cnt++;
		}
		if(cnt == N)return true;
		sum[t[i].id]--;
		if(sum[t[i].id] == 0)cnt--;
	}
	return false;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= M;j++){
			int a;scanf("%d",&a);
			t[++tot] = Node(a,i);
		}
	}
	sort(t+1,t+1+tot);
	int l = 0,r = 1000000,mid,ans = 0;
	while(l <= r){
		mid = (l + r)/2;
		if(Check(mid))ans = mid,r = mid-1;
		else l = mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
/*
3 3  
8 1 6      
3 5 7  
4 9 2
*/