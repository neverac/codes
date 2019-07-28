#include<bits/stdc++.h>
using namespace std;
int a[305][305];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,u,v,w;
        cin>>n;
        int tot=n*(n-1)/2;
        for(int i=1;i<=tot;i++)
        {
            cin>>u>>v>>w;
            a[u][v]=w;
            a[v][u]=w;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j==i) continue;
                for(int k=1;k<=n;k++)
                {
                    if(k==i||k==j) continue;
                    int tmp=a[i][j]+a[i][k]+a[j][k];
                    ans=max(ans,tmp);
                }
            }
        }
        cout<<ans<<endl;
    }
}
