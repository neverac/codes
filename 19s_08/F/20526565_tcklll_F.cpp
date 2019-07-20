#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#define sf(n) scanf("%d",&n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define ll long long
#define MAXL 1000000
#define eps 1e-6
#define MAXV 10005
#define INF 1000000005
#define mod 1000000007
using namespace std;
int a[100005];
bool f[100005];
int k[2][100005];
int main(){
    int n;sf(n);
    int mmin,mmax;
    int pmin=0,pmax=0;
    for(int i=0;i<n;i++){
        sf(a[i]);
        if(i==0){
            mmin=a[0];
            mmax=a[0];
        }
        else{
            if(mmin>a[i]){
                mmin=a[i];
                pmin=i;
            }
            if(mmax<a[i]){
                mmax=a[i];
                pmax=i;
            }
        }
    }
    if(pmin==pmax){
        if(a[0]>0){
            f[0]=0;
            for(int i=1;i<n;i++)f[i]=1;
            pmin=0;
            pmax=1;
        }
        else{
            f[0]=1;
            for(int i=1;i<n;i++)f[i]=0;
            pmin=1;
            pmax=0;
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(i==pmin){
                f[i]=0;
            }
            else if(i==pmax){
                f[i]=1;
            }
            else{
                if(a[i]>=0)f[i]=1;
                else f[i]=0;
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(f[i])sum+=a[i];
        else sum-=a[i];
    }
    printf("%d\n",sum);
    for(int i=0;i<n;i++){
        if(i==pmin||i==pmax)continue;
        if(f[i]==0){printf("%d %d\n",a[pmax],a[i]);a[pmax]-=a[i];}
        else {printf("%d %d\n",a[pmin],a[i]);a[pmin]-=a[i];}
    }
    printf("%d %d\n",a[pmax],a[pmin]);
}
