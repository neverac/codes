#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define SIZE 22000

using namespace std;

long long p,q;
bool discover[10];

int main()
{
    int m,n,t,k;
    int i,j,tmp;
    bool can=false;
    scanf("%lld%lld",&p,&q);
    for(i=0;i<=q;i++)
    {
        p*=10;
     //   printf("p=%lld\n",p);
        while(p<q)
        {
            discover[0]=true;
            p*=10;
       //     printf("p=%lld\n",p);
        }
        discover[p/q]=true;
        p%=q;
        if(p==0)
            break;
    }
    for(i=0;i<10;i++)
        if(discover[i])
            putchar('0'+i);
    putchar('\n');
    return 0;
}
