#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define SIZE 100100

using namespace std;

int rec[SIZE];
int tmp1[SIZE];
int tmp2[SIZE];
vector<int> rec1,rec2;

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",rec+i);
        tmp1[i]=rec[i];
    }
    sort(tmp1+1,tmp1+n+1);
    for(i=1;i<=n;i++)
        tmp2[i]=tmp1[n+1-i];
    for(i=1;i<=n;i++)
    {
        if(rec[i]!=tmp1[i] && rec1.size()<3)
            rec1.push_back(i);
        if(rec[i]!=tmp2[i] && rec2.size()<3)
            rec2.push_back(i);
    }
    if(rec1.size()==0 || rec2.size()==0)
        puts("Nothing to do here");
    else if(rec1.size()==2)
        printf("YES\n""%d %d\n",rec1[0],rec1[1]);
    else if(rec2.size()==2)
        printf("YES\n""%d %d\n",rec2[0],rec2[1]);
    else
        puts("No hope");
    return 0;
}