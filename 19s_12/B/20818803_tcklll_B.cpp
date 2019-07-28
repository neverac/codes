#include <bits/stdc++.h>
#define ll long long
#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d",&a,&b)
#define MAXN 10005
#define INF 1000000000000000.
#define mod 998244353
using namespace std;
int f1[500005]={0};
int f2[500005]={0};
int f3[500005]={0};
int main()
{
    string x;cin>>x;
    int l=x.length();
    for(int i=0;i<l-1-i;i++){
        if(x[i]==x[l-1-i]){
            if(i==0)f1[i]=1;
            else f1[i]=f1[i-1]+1;
        }
        else{
            if(i==0)f1[i]=0;
            else f1[i]=f1[i-1];
        }
        //cout<<i<<"  "<<f1[i]<<endl;
    }
    //cout<<endl;
    for(int i=1;i<l-i;i++){
        if(x[i]==x[l-i]){
            if(i==1)f2[i-1]=1;
            else f2[i-1]=f2[i-2]+1;
        }
        else{
            if(i==1)f2[i-1]=0;
            else f2[i-1]=f2[i-2];
        }
        //cout<<i-1<<"  "<<f2[i-1]<<endl;
    }
    //cout<<endl;
    for(int i=0;i<l-2-i;i++){
        if(x[i]==x[l-2-i]){
            if(i==0)f3[i]=1;
            else f3[i]=f3[i-1]+1;
        }
        else{
            if(i==0)f3[i]=0;
            else f3[i]=f3[i-1];
        }
        //cout<<i<<"  "<<f3[i]<<endl;
    }
    int k1,k2;
    if(l%2==1){k1=l/2-1;k2=l/2+1;}
    else {k1=l/2-2;k2=l/2+1;}
    //cout<<k1<<"  "<<k2<<"???"<<endl;
    for(int i=0;i<l;i++){
        int sum1=0,sum2=0;
        if(i==0||i==l-1)sum1=0;
        else sum1=f1[min(l-2-i,i-1)];

        if(i<=k1){
            if(i==0)sum2=f2[k1];
            else sum2=f2[k1]-f2[i-1];
        }
        if(i>=k2){
            if(i==l-1)sum2=f3[k1];
            else sum2=f3[k1]-f3[l-2-i];
        }
        //cout<<i<<"  "<<sum1<<"  "<<sum2<<endl;
        if(sum1+sum2==(l-1)/2){printf("%d\n",i+1);break;}
    }
}
