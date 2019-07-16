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
int main()
{
    int t;sf(t);
    while(t--){
        string x;cin>>x;
        int l=x.length();
        int a[1005]={0};
        a[0]=x[0]-'0';
        for(int i=1;i<l;i++){
            if(x[i]=='1')a[i]=a[i-1]+1;
            else a[i]=a[i-1];
            //cout<<a[i]<<endl;
        }
        int mmin=min(l-a[l-1],a[l-1]);
        for(int i=1;i<l;i++){
            int p=a[i-1]+l-i-(a[l-1]-a[i-1]);
            //cout<<i<<"  "<<p<<endl;
            mmin=min(mmin,p);
        }
        printf("%d\n",mmin);
    }
}
/*
100
000111001101
*/

