#include<bits/stdc++.h>
using namespace std;
long long a[12];
long long A[25][25];
long long sumx[25];
long long sumy[25];
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long l=2*n;
        for(long long i=0;i<n;i++) cin>>a[i];
        for(long long i=0;i<2*n;i++)
        {
            for(long long j=0;j<2*n;j++)
            {
                long long cnt=(i+j+1)*(i+j)/2+i;
                cnt%=n;
                A[i][j]=a[cnt];
            }
        }
        for(long long i=0;i<2*n;i++)
        {
            sumx[i]=0;
            sumy[i]=0;
            for(long long j=0;j<2*n;j++)
            {
                sumx[i]+=A[i][j];
                sumy[i]+=A[j][i];
            }
        }
        long long sum=0;
        for(long long i=0;i<l;i++)
        {
            sum+=sumx[i];
        }
        long long q;
        cin>>q;
        while(q--)
        {
            long long x0,x1,y0,y1;
            cin>>x0>>y0>>x1>>y1;
            long long ans=0;
            long long y=(y1-y0)/(2*n);
            long long x=(x1-x0)/(2*n);
            long long tot=x*y;
            ans+=tot*sum;
            long long remainx=x0+x*(2*n);
            long long remainy=y0+y*(2*n);
            for(long long i=remainx;i<=x1;i++) ans+=y*sumx[i%(2*n)];
            for(long long i=remainy;i<=y1;i++) ans+=x*sumy[i%(2*n)];
            for(long long i=remainx;i<=x1;i++)
            {
                for(long long j=remainy;j<=y1;j++)
                {
                    ans+=A[i%l][j%l];
                }
            }
            cout<<ans<<endl;
        }
    }
}
