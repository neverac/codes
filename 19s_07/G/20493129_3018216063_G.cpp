#include <iostream>

using namespace std;
int a[1100][1100];
bool dfs(int x,int y,int n)
{
    for(int i=x;i<n;i++)
    {
        if(a[i][y]!=a[i+1][y]-1) return false;

    }
    for(int i=y;i<n;i++)
    {
        if(a[x][i]!=a[x][i+1]-1) return false;

    }
    return true;
}
int main()
{


    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int cnt=1;
            //cout<<a[i][j]<<" "<<a[i+1][j+1]<<endl;
            while(a[i][j]==a[i+1][j+1]-2&&i+1<=n&&j+1<=n)
            {
                //cout<<a[i][j]<<" "<<a[i+1][j+1]<<endl;
                cnt++;
                i++;
                j++;
            }
           // cout<<cnt<<"a";
            if(dfs(i,j,cnt)==true) ans=max(ans,cnt);
          //  cout<<ans<<endl;

        }
    }
    cout<<ans;
    return 0;
}
