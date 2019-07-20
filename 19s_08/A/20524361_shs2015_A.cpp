#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int SIZEN = 500010;
int N;
int a[SIZEN] = {0};
int b[50][SIZEN] = {0};
int len[50] = {0};
int now[50] = {0};
int mp[100] = {0};
int con[] = {0,4,8,15,16,23,42};
int main(){
	mp[4]  = 1;
	mp[8] = 2;
	mp[15] = 3;
	mp[16] = 4;
	mp[23] = 5;
	mp[42] = 6;
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		scanf("%d",&a[i]);
		b[a[i]][++len[a[i]]] = i;
	}
	bool flag = true;
	int sum = 0;
	while(flag && now[4] != len[4]){
		now[4]++;
		int loc = b[4][now[4]];
		for(int i = 2;i <= 6;i++){
			int x = con[i];
			bool tmp = false;
			while(len[x]!=now[x]){
				now[x]++;
				if(b[x][now[x]] > loc){
					loc = b[x][now[x]];
					tmp = true;
					break;
				}
			}
			if(!tmp){flag = false;break;}
		}
		if(flag)sum++;
	}
	printf("%d\n",N - 6 * sum);
	return 0;
}