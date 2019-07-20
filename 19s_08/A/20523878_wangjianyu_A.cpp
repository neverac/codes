#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 50010
using namespace std;

int num[6]={4,8,15,16,23,42};
//int rec[SIZE];
int nums[6];

int pos(int num)
{
    if(num==4)
        return 0;
    if(num==8)
        return 1;
    if(num==15)
        return 2;
    if(num==16)
        return 3;
    if(num==23)
        return 4;
    return 5;
}

int main()
{
    int i,j,n,tmp;
    int ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        if(tmp==4)
            nums[0]++;
        else
        {
            int po=pos(tmp);
            if(nums[po-1]>0)
            {
                nums[po-1]--;
                if(po!=5)
                    nums[po]++;
            }
            else
            {
                ans++;
            }
        }
    }
    for(i=0;i<5;i++)
        ans+=nums[i]*(i+1);
    printf("%d\n",ans);
    return 0;
}
