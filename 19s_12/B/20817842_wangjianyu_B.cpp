#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define SIZE 500500

using namespace std;

int len;
char s[SIZE];

bool trying(int pos)
{
    int i,j;
    for(i=1,j=len;i<j;i++,j--)
    {
        if(i==pos)
            i++;
        else if(j==pos)
            j--;
        if(s[i]!=s[j])
            return false;
    }
    return true;
}
int main()
{
    int m,n,t,k;
    int i,j,tmp;
    s[0]='$';
    bool findinf=false;
    scanf("%s",s+1);
    len=strlen(s+1);
    for(i=1,j=len;i<j;i++,j--)
    {
        if(s[i]!=s[j])
        {
        //    printf("i=%d j=%d\n",i,j);
            findinf=trying(i);
            if(!findinf)
                i=j;
            break;
        }
    }
    while(s[i-1]==s[i])
        i--;
    printf("%d\n",i);
    return 0;
}
