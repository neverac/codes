#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int SIZEN = 110;
int N,M;
vector<int> v[SIZEN];
bool flag[SIZEN][SIZEN*2]={0};
int sum[SIZEN] = {0};
int p[SIZEN];
bool Cmp(const int &A,const int &B){return A > B;}
int main(){
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	}
	
	for(int i = 1;i <= N;i++){
		int now = 0,loc = i,ans = 0;
		memset(sum,0,sizeof sum);
		memset(p,0,sizeof p);
		memset(flag,0,sizeof flag);
		while(now != M){
			if(v[loc].size() != p[loc]){
				p[loc]++;
				int tmp = -1,dis = 0;
				for(int j = 0;j < v[loc].size();j++){
					int x = v[loc][j];
					if(flag[loc][j])continue;
					if(tmp==-1){
						tmp = j;
						if(x >= loc)dis = x-loc;
						else dis = N-loc + x;
					}
					else{
						int tmpdis = 0;
						if(x >= loc)tmpdis = x-loc;
						else tmpdis = N-loc+x;
						if(tmpdis > dis)tmp = j,dis = tmpdis;
					//	printf("--> x = %d,tmpdis = %d\n",x,tmpdis);
					}
				}
				//printf("loc = %d,x = %d\n",loc,v[loc][tmp]);
				flag[loc][tmp] = true;
				sum[v[loc][tmp]]++;
			}
			now += sum[loc];
			sum[loc] = 0;
		//	printf("%d %d\n",now,loc);
			loc++;ans++;
			if(loc == N+1)loc = 1;
		}
		printf("%d ",ans-1);
	}
} 