#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 30;
bool ok;
int n, ans;
int color[N];
bool g[N][N];

bool can(int x, int c){
    for(int i = 0;i < x;i++)
    	if(g[x][i] && color[i]==c){
    		return 0;
    	} 		
    return 1;
}

void dfs(int x){
	if(ok) return;
    if(x == n){
        ok = true;
        return;
    }
    for(int j = 1; j < 4; j++){
        if(can(x, j)){
			color[x] = j;
			dfs(x+1);
			if(ok) return;
        }
        
    }
}

int main()
{
    int i, j, l,t,m;
    scanf("%d",&t);
    
    while(t--){
    	scanf("%d",&n);	
        memset(g,0,sizeof(g));
        memset(color,0,sizeof(color));
        ok = false;
        scanf("%d",&m);
        for(i=0;i < m;i ++){
        	int a,b;
        	scanf("%d%d",&a,&b);
        	g[a][b] = g[b][a] = 1;
		}
		if(n < 4){
			printf("Y\n");
			continue;
		}
		dfs(0);
        if(ok) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}