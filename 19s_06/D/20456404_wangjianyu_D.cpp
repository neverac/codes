#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define SIZE 1000100
#define MOD 1000000007

using namespace std;
int main()
{
    int g,b,p,a,d,m;
    scanf("%d%d%d",&a,&d,&m);
    scanf("%d%d%d",&g,&p,&b);
    if(a<=g && a+d<=g+p && a+d+m<=g+p+b)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}