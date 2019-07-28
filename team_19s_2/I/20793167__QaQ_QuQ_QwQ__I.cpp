#include<stdio.h>
#include<string.h>
const int MAXN=100;
int uN,vN;  //u,v数目
int g[MAXN][MAXN];//编号是0~n-1的
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    int v;
    for(v=1;v<=vN;v++)
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }   
        }
    return false; 
}   

int hungary()

{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=1;u<=uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u))  res++;
    }
    return res;  
} 

int main()
{
    int k;
    int u,v,n,m;
    while(1)
    {
    	scanf("%d",&uN);
    	if(uN==0)
    	break;
        scanf("%d%d",&vN,&k);
        memset(g,0,sizeof(g));
        while(k--)
        {
            scanf("%d%d",&u,&v);
            g[u+1][v+1]=1;
        }
        printf("%d\n",hungary());  
    } 
    return 0; 
} 