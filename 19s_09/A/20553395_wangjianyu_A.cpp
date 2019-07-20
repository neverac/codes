#include<cstdio>
#include<algorithm>
#include<cstring>
#define SIZE 40010

using namespace std;


int main()
{
    int t;
    int l,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        printf("%d %d\n",l,l+l);
    }
   // printf("%d\n",);
    return 0;
}
