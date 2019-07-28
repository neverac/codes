#include <bits/stdc++.h>
#define ll long long
#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d",&a,&b)
#define MAXN 10005
#define INF 1000000000000000.
#define mod 998244353
using namespace std;
vector<int>a[105];
int f[105];
int main()
{
    int n,m;sff(n,m);
    for(int i=0;i<m;i++){
        int p,q;sff(p,q);
        a[p].push_back(q);
    }
    for(int i=1;i<=n;i++){
        int mmin=i-1;
        if(mmin==0)mmin=n;
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]>i){
                if(mmin>i){
                    mmin=min(mmin,a[i][j]);
                }
                else{
                    mmin=a[i][j];
                }
            }
            else{
                if(mmin>i){
                    mmin=mmin;
                }
                else{
                    mmin=min(mmin,a[i][j]);
                }
            }
        }
        //cout<<i<<"  "<<mmin<<endl;
        if(a[i].size()==0)f[i]=0;
        else f[i]=(a[i].size()-1)*n+(mmin-i+n)%n;
    }
    for(int i=1;i<=n;i++){
        int mmax=f[i];
        for(int j=i+1;;j++){
            if(j>n)j-=n;
            if(j==i)break;
            if(f[j]==0)continue;
            mmax=max(mmax,f[j]+(j-i+n)%n);
        }
        printf("%d ",mmax);
    }
    printf("\n");
}
