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
#define mod 998244353
using namespace std;
int p[17]={90,60,45,36,30,20,18,15,12,10,9,6,5,4,3,2,1};
int main()
{
    int t;sf(t);
    while(t--){
        int ang;sf(ang);
        //int ang=t;cout<<ang<<"  ";
        int er=180;
        //bool flag=0;
        for(int i=0;i<17;i++){
            if(ang%p[i]==0){
                if(180/p[i]-ang/p[i]>=2){printf("%d\n",180/p[i]);break;}
                else{printf("%d\n",360/p[i]);break;}
            }
        }
    }
}
