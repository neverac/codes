#include<cstdio>
#include<algorithm>
#define SIZE 230

using namespace std;

int n,c;
int map[SIZE][SIZE];
int rec[SIZE];

int main()
{
    int i,j,t,k,m;
    int top;
    int ii,jj;
    int ans;
    while(scanf("%d",&n))
    {
        if(n==0)
            return 0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                map[i][j]=(i==j)?0:500;
        for(i=1;i<=n;i++)
            rec[i]=0;
        top=0;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&ii,&jj);
            map[ii][jj]=map[jj][ii]=1;
        }
        for(k=0; k<n; k++)
            for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                    if(map[i][k]+map[k][j]<map[i][j])
                        map[i][j]=map[i][k]+map[k][j];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                rec[map[i][j]]++;
                if(map[i][j]<500)
                    top=max(top,map[i][j]);
            }
        for(i=1;i<=top;i++)
        {
            printf("%d %d\n",i,rec[i]);
        }
    }
    return 0;
}
