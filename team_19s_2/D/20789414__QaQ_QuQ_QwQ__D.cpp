#include<cstdio>
#include<iostream>
#include<memory.h>
using namespace std;
#define MAX 205
#define INFE 1<<29
 
int N; 
int map[MAX][MAX],b[MAX];  //path[i][j]记录路径
 
//void init()
//{
//       int i,j;
//       for(i=1;i<=N;i++)
//       for(j=1;j<=N;j++)
//     {
//        map[i][j]=INFE;
//     }
//}
 
void floyd()
{
       int i,j,k;
       for(k=1;k<=N;k++)
       for(i=1;i<=N;i++)
       for(j=1;j<=N;j++)
       if(map[i][j]>map[i][k]+map[k][j])
        {
            map[i][j]=map[i][k]+map[k][j];
       }
}
 
int ans[205];
int main()
{
       int m,u,v,len,i,j;
       while(1) //输入城市数量 和 道路数量
       {
       	      scanf("%d",&N);
       	      if(N==0)
       	      break;
       		  memset(ans,0,sizeof(ans));
			  scanf("%d",&m);       	
              memset(map,0x3f,sizeof(map));
              while(m--)
              {
                scanf("%d%d",&u,&v);
                map[u+1][v+1]=map[v+1][u+1]=1;
              }
//              printf("22");
              floyd();//进行每对节点的求最小路径
 			  int tt=0;
			  for(i=1;i<N;i++)
			  for(j=i+1;j<=N;j++)
			  if(map[i][j]<N)    
			  {
			  	ans[map[i][j]]++;
			    tt=max(tt,map[i][j]);
			   }
			  for(i=1;i<=tt;i++)
			  printf("%d %d\n",i,2*ans[i]);
       }
       return 0;
}
