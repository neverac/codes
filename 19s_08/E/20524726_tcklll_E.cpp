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
        int n;sf(n);
        int a[105];
        int s[3]={0};
        for(int i=0;i<n;i++){
            int p;sf(p);
            a[i]=p%3;
            s[a[i]]++;
        }
        int sum=s[0];
        if(s[1]<s[2]){
            sum+=s[1];
            s[2]-=s[1];
            sum+=s[2]/3;
        }
        else{
            sum+=s[2];
            s[1]-=s[2];
            sum+=s[1]/3;
        }
        printf("%d\n",sum);
    }
}
