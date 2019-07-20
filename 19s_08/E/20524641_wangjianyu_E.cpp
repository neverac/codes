#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 50010
using namespace std;

//int rec[3][SIZE];
int cnt[3];

int main()
{
    int n,t,i;
    int tmp,pos;
    long long total;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cnt[0]=cnt[1]=cnt[2]=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&tmp);
        //    total+=tmp;
            pos=tmp%3;
        //    rec[pos][cnt[pos]]=tmp;
            cnt[pos]++;
        }
        total=cnt[0];
        if(cnt[1]>cnt[2])
        {
            total+=cnt[2];
            total+=(cnt[1]-cnt[2])/3;
        }
        else
        {
            total+=cnt[1];
            total+=(cnt[2]-cnt[1])/3;
        }
        printf("%lld\n",total);
    }
    return 0;
}
