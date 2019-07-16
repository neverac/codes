#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define SIZE 100100

using namespace std;

char s[SIZE];
char ans[SIZE];
int num[26];
int len;

bool can(int pos,int j)
{
    if(num[j]==0)
        return false;
    if(ans[pos-1]=='a'+j)
        return false;
    for(int i=0;i<26;i++)
    {
        if(i!=j && num[i]>(len-pos+1)/2)
            return false;
        else if(i==j && num[j]-1>(len-pos)/2)
            return false;
    }
    return true;
}
int main()
{
    int i,j,n;
    scanf("%s",s+1);
    for(i=1;s[i];i++)
    {
        num[s[i]-'a']++;
    }
    len=i-1;
    for(i=0;i<26;i++)
    {
        if(num[i]>(len+1)/2)
        {
            puts("INVALID");
            return 0;
        }
    }
    for(i=1;i<=len;i++)
    {
        for(j=0;j<26;j++)
        {
            if(can(i,j))
            {
                ans[i]='a'+j;
                num[j]--;
                break;
            }
        }
    }
    ans[len+1]='\n';
    puts(ans+1);
    return 0;
}
