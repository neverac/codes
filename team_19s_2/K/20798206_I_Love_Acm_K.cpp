#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<iostream>
using namespace std;
int m,n,k;
int map_[30][30];
int color[30];
int ans;
int t;
void a(int p)
{
    if(ans!=0) return;
    if(p == n)
    {
        ans++;
        return;
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            if(ans!=0) return;
            int mmp = false;
            for(int j=0;j<p;j++)
            {
                if(ans!=0) return;
                if(map_[p][j] == 1 && color[j] == i)
                {
                    mmp = true;
                    break;
                }
            }
            if(mmp == true) continue;
            color[p] = i;
            a(p+1);
            color[p] = 0;
        }
    }
}
int main()
{
//    freopen("color.in","r",stdin);
//    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        memset(map_,0,sizeof(map_));
        memset(color,0,sizeof(color));
        scanf("%d%d",&n,&k);
        m=3;
        ans=0;
        for(int i=0;i<k;i++)
        {
            int d1,d2;
            scanf("%d%d",&d1,&d2);
            map_[d1][d2] = 1;
            map_[d2][d1] = 1;
        }
    a(0);
    if(ans!=0) cout<<"Y"<<endl;
    else cout<<"N"<<endl;
    }
    return 0;
}
