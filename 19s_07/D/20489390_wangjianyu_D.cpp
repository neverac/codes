#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define SIZE 1010

using namespace std;

char s[SIZE];
int num[SIZE][2];

int main()
{
    int i,j;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int ans;
        scanf("%s",s);
        if(s[0]=='0')
        {
            num[0][0]=1;
            num[0][1]=0;
        }
        else
        {
            num[0][0]=0;
            num[0][1]=1;
        }
        for(i=1;s[i];i++)
        {
            num[i][0]=num[i-1][0];
            num[i][1]=num[i-1][1];
            num[i][s[i]-'0']++;
        }
        int len=i;
        ans=num[len-1][0];
        for(i=0;i<len;i++)
        {
            ans=min(ans,num[i][1]+num[len-1][0]-num[i][0]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
