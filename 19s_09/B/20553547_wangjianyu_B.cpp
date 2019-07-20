#include<cstdio>
#include<algorithm>
#include<cstring>
#define SIZE 200010
#define MOD 998244353

using namespace std;

char s[SIZE];
int main()
{
    int t,n;
    int i,j;
    scanf("%d",&n);
    scanf("%s",s);
    for(i=1;s[i]==s[i-1];i++);
    for(j=n-2;s[j]==s[j+1];j--);
    if(s[0]==s[n-1])
        printf("%lld\n",(i+1)*1LL*(n-j)%MOD);
    else
        printf("%d\n",(i+n-j)%MOD);
   // printf("%d\n",);
    return 0;
}
