#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define SIZE 110
#define MOD 100

using namespace std;

int val[SIZE][SIZE];
int color[SIZE][SIZE];

int mix(int i,int k,int j)
{
    return val[i][k]+val[k+1][j]+color[i][k]*color[k+1][j];
}
int main()
{
    int n,len;
    int i,k;
    while(~scanf("%d",&n))
    {
        memset(val,0,sizeof(val));
        memset(color,0,sizeof(color));
        for(i=0;i<n;i++)
            scanf("%d",&color[i][i]);
        for(len=2;len<=n;len++)
        {
            for(i=0;i+len-1<n;i++)
            {
                int to=i+len-1;
                color[i][to]=(color[i][to-1]+color[to][to])%MOD;
          //      printf("color[%d][%d]=%d\n",i,to,color[i][to]);
                val[i][to]=99999999;
                for(k=i;k<to;k++)
                {
                    val[i][to]=min(val[i][to],mix(i,k,to));
                }
           //     printf("val[%d][%d]=%d\n",i,to,val[i][to]);
            }
        }
        printf("%d\n",val[0][n-1]);
    }

    return 0;
}

