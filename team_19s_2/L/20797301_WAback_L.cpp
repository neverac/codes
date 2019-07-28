#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 1000000 + 10;
char str[N];
int Next[N];
void makeNext(char *str)
{
    int i=0,j=-1;
    Next[0] = -1;
    while(str[i])
    {
        if(j==-1||str[i]==str[j])
        {
            i++;
            j++;
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}
char s[100010];
int f[100010];
#define INF 0x7fffffff
int main()
{
	int cas; scanf("%d",&cas);
	while (cas--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		f[0]=0;
		for (int i=1; i<=n; i++) f[i]=INF;
		for (int i=1; i<=n; i++){
			makeNext(s+i);
			for (int j=i; j<=n; j++){
				int t = j-i+1-Next[j-i+1],k=0;
				if ((j-i+1)%t==0) k=t;
				else k=j-i+1;
				f[j]=min(f[j],f[i-1]+k);
				//printf("debug %d %d %d\n",i,j,k);
			}
			//printf("fuck %d %d\n",i,f[i]);
		}
		printf("%d\n",f[n]);
	}
    return 0;
}