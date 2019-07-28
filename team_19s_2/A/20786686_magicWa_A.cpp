#include <bits/stdc++.h>
#define ll long long
#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d",&a,&b)
#define MAXN 10005
#define INF 1000000000000000
#define mod 998244353
using namespace std;
int main()
{
    int n,d;
    while(1){
        sf(n);if(n==0)break;
        sf(d);
        int a[1005];
        int b[1005];
        for(int i=0;i<n;i++){
            sf(a[i]);
        }
        for(int i=0;i<n-1;i++){
            b[i]=a[i]-a[i+1];
        }
        bool flag=0,fl=0;
        if(n<=2){
            printf("Y\n");
            continue;
        }
        for(int i=0;i<n-1;i++){
            //cout<<i<<"  "<<b[i]<<endl;
            if(b[i]<=d&&b[i]>=-d){
                continue;
            }
            else if(flag==0){
                flag=1;
                //cout<<i<<endl;
                if(i==0){
                    if(b[1]<=d&&b[1]>=-d)continue;
                    else if(!(a[i]-d>a[i+2]+d||a[i]+d<a[i+2]-d)){
                        //cout<<"??"<<endl;
                        i++;continue;
                    }
                    else{
                        fl=1;break;
                    }
                }
                else if(i==n-2){
                    break;
                }
                else{
                    if(!(a[i-1]-d>a[i+1]+d||a[i-1]+d<a[i+1]-d)){
                        if(b[i+1]<=d&&b[i+1]>=-d)continue;
                    }
                    if(!(a[i]-d>a[i+2]+d||a[i]+d<a[i+2]-d)){
                        i++;continue;
                    }
                    fl=1;break;
                }
            }
            else{
                fl=1;break;
            }
        }
        if(fl)printf("N\n");
        else printf("Y\n");
    }
}
/*
5 2
100 0 100 102 102
*/
