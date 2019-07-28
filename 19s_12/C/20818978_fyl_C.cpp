#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}
const int maxn = 201000;
std::vector<int> c[maxn];

struct Node{
	int c,pi,pj;
	Node(int x,int y,int z){
		c=x,pi=y,pj=z;
	}
	bool operator < (const Node &x)const{
		return c>x.c;
	}
};
priority_queue<Node>q;

int main(){
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			c[i].push_back(read());
		sort(c[i].begin(),c[i].end());
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		q.push(Node(c[i][0],i,0));
		mx=max(mx,c[i][0]);
	}
	int ans=mx-q.top().c;
	//printf("---%d\n",ans);
	
	while(!q.empty()){
		Node x=q.top();q.pop();
		//printf("%d\n",x.c);
		if(x.pj==m-1) break;
		q.push(Node(c[x.pi][x.pj+1],x.pi,x.pj+1));
		mx=max(mx,c[x.pi][x.pj+1]);
		ans=min(ans,mx-q.top().c);
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