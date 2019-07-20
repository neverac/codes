#include<cstdio>
#include<algorithm>
#include<cstring>
#define SIZE 100010
#define MOD 998244353

using namespace std;

int gcd(int x,int y)
{
    int c=y;
    while(c)
    {
        c=x%y;
        x=y;
        y=c;
    }
    return x;
}
int main()
{
    int t;
    int ang;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&ang);
        int tmp=gcd(180,ang);
        if(180/tmp==ang/tmp+1)
            printf("%d\n",180/tmp*2);
        else
            printf("%d\n",180/tmp);
    }
    return 0;
}