#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define SIZE 50
#define MOD

using namespace std;

int m;
long long rec[SIZE][SIZE];
int l[SIZE];

void p()
{
    int i,j;
    for(i=0;i<m+m;i++)
    {
        for(j=0;j<m+m;j++)
        {
            printf("%5d ",rec[i][j]);
        }
        putchar('\n');
    }
}
void pre()
{
    int i,j;
    int cursor = 0;
    for (i = 0; i<4*m-1; ++i)
    {
        for (j = 0; j <= i; ++j)
        {
            rec[j][i - j] = l[cursor];
            cursor = (cursor + 1) % m;
        }
    }
  //  p();
    for(i=1;i<m+m;i++)
        rec[0][i]+=rec[0][i-1];
    for(i=1;i<m+m;i++)
    {
        rec[i][0]+=rec[i-1][0];
        for(j=1;j<m+m;j++)
        {
            rec[i][j]+=rec[i-1][j]+rec[i][j-1]-rec[i-1][j-1];
        }
    }
 //   p();
}
long long ss(long long x,long long y)
{
    if(x==-1)
        return 0;
    if(y==-1)
        return 0;
    long long tmpx=x%(m+m);
    long long tmpy=y%(m+m);
    long long numx=x/(m+m);
    long long numy=y/(m+m);
    long long ret=numx*numy*rec[m+m-1][m+m-1]
        +numx*rec[m+m-1][tmpy]+numy*rec[tmpx][m+m-1];
    ret+=rec[tmpx][tmpy];
 //   printf("x=%lld y=%lld s=%lld\n",x,y,ret);
    return ret;
}
int main()
{
    int a,b;
    int n,i,t;
    long long ans;
    int x0,y0,x1,y1,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d",l+i);
        pre();
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
            x0--;
            y0--;
            ans=ss(x1,y1)-ss(x1,y0)-ss(x0,y1)+ss(x0,y0);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
