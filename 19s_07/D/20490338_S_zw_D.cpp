#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#define N 1000010
using namespace std;int stop;
int t;

int main(){
    int i;
	scanf("%d",&t);
    getchar();
    char s[1010];
    while(t>0){
        t--;
        scanf("%s",s);
        getchar();
        int len = strlen(s);
        int zuoone[1010];
        memset(zuoone,0,sizeof(zuoone));
        if(s[0] == '1'){
            zuoone[0] = 1;
        }else{
            zuoone[0] = 0;
        }
        for(i=1;i<len;i++){
            if(s[i] == '1'){
                zuoone[i] = zuoone[i-1]+1;
            }else{
                zuoone[i] = zuoone[i-1];
            }
        }

        int youzore[1010];
        memset(youzore,0,sizeof(youzore));
        if(s[len-1] == '0'){
            youzore[len-1] = 1;
        }else{
            youzore[len-1] = 0;
        }
        for(i=len-1;i>=0;i--){
            if(s[i] == '0'){
                youzore[i] = youzore[i+1] +1;
            }else{
                youzore[i] = youzore[i+1];
            }
        }
        int Min = youzore[0];
        for(i=0;i<len;i++){
            Min = min(Min,youzore[i+1] + zuoone[i]);
        }
        printf("%d\n",Min);
    }
    return 0;
}