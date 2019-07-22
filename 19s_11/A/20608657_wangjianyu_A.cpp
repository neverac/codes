#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define SIZE 100100

using namespace std;

int n;
int rec[SIZE];

int main()
{
    int i;
    scanf("%d",&n);
    long long wei=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",rec+i);
        wei+=rec[i];
    }
    sort(rec,rec+n);
    long long ans=0;
    for(i=0;i<n;i++)
    {
        ans+=rec[i]*wei;
        wei-=rec[i];
        ans+=rec[i]*wei;
    }
    printf("%lld\n",ans);
    return 0;
}
