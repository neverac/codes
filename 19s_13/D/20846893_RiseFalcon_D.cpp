#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=300+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int n=input();
int m=input();
int train[MAXN],count[MAXN];
int size[MAXN],js[MAXN],xxx;
int received[MAXN],answer[MAXN];
std::vector<int>station[MAXN];
int ghi(const int&i) {
	return i>xxx ?i-xxx : n+i-xxx;
}
bool cmp(const int&i,const int &j) {
	return ghi(i)> ghi(j);
}
int main() {
	for(int i=0;i<m;++i) {
		int f=input()-1;
		int t=input()-1;
		size[f]++;
		station[f].push_back(t);
		count[t]++;
	}
	for(int i=0;i<n;++i) {
		xxx=i;
		std::sort(station[i].begin(),station[i].end(),cmp); 
	//	for(int j=0;j<size[i];++j) {
	//		printf("%d ",station[i][j]);
	//	}printf("\n");
	}
	for(int start=0;start<n;++start) {
		memset(js,0,sizeof js);
		memset(train,0,sizeof train);
		memset(received,0,sizeof received);
		for(int T=0,i=start,cw=0;cw<n;++T,i=(i+1)%n) {
			received[i]+=train[i];train[i]=0;
			if(count[i]==received[i]) {
				++cw;received[i]+=1;
				if(count[i]!=0) {
					answer[start]=std::max(answer[start],T);				
				}
			}
			if(js[i]!=size[i]) {
				train[station[i][js[i]]]++;
				js[i]++;
			}
		}	
	}
	for(int i=0;i<n;++i) {
		printf("%d ",answer[i]);
	}
	return 0;
}
