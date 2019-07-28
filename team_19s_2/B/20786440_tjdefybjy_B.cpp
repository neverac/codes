#include<cstdio>
#include<algorithm>
#define SIZE 330

using namespace std;

int n,c;
int rec[SIZE][SIZE];
int main()
{
    int i,j,t,k;
    int tmp;
    int ii,jj;
    int ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=-1;
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                scanf("%d%d%d",&ii,&jj,&tmp);
                if(jj<ii)
                    swap(jj,ii);
                rec[ii][jj]=tmp;
            }
        }
        for(i=1;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<=n;k++)
                {
                    ans=max(ans,rec[i][j]+rec[i][k]+rec[j][k]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
