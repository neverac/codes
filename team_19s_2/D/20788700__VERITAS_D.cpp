#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int mmp[1000][1000];
int cnt[1005];
int main()
{
    int k,i,j,n,m;
    while(cin>>n&&n){
        cin>>m;
        memset(cnt,0,sizeof(cnt));
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(i==j)
                    mmp[i][j]=0;
                else
                    mmp[i][j]=inf;
        int a,b;
        for(i=1; i<=m; i++)
        {
            scanf("%d %d",&a,&b);
            mmp[a+1][b+1]=mmp[b+1][a+1]=1;
        }

        for(k=1; k<=n; k++)
            for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                    if(mmp[i][j]>mmp[i][k]+mmp[k][j] )
                        mmp[i][j]=mmp[i][k]+mmp[k][j];


        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cnt[mmp[i][j]]++;
            }
        }
        for(int i=1;i<n&&cnt[i];i++){
            cout<<i<<" "<<cnt[i]<<endl;
        }
    }
    return 0;
}
