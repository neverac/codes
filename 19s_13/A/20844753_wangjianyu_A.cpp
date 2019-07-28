#include<cstdio>

using namespace std;

int main()
{
    int i,n;
    int tmp;
    int pos=0;
    int neg=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        if(tmp<0)
            neg++;
        else if(tmp>0)
            pos++;
    }
    if(pos>=(n+1)/2)
        puts("1");
    else if(neg>=(n+1)/2)
        puts("-1");
    else
        puts("0");
    return 0;
}
