#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long
#define N 500010
using namespace std;int stop;
int len1,len2;
char s[N];
char b[N];
//int a[N<<1];

bool check(int i){
    int j;
    int len = len1-1;
    int cnt = -1;
    for(j=0;j<len1;j++){
        if(j != i){
            cnt++;
            b[cnt] = s[j];
        }
    }
    for(j=0;j<len/2;j++){
        if(b[j] != b[len-1-j]){
            break;
        }
    }

    if(j == len/2){
        return 1;
    }
    return 0;
}

int main(){
    int i,j;
    bool suc = 0;
    scanf("%s",s);
    len1 = strlen(s);
    for(i=0;i<len1/2;i++){
        if(s[i] != s[len1-1-i]){
            int j = i;
            while (j>=0 && s[j] == s[i])
            {
                j--;
            }
            j++;
            if(check(j)){
                printf("%d\n",j+1);
                suc = 1;
                break;
            }
            if(check(len1-1-i)){
                printf("%d\n",len1-1-i+1);
                suc = 1;
                break;
            }
        }
    }
    if(!suc){
        j = len1/2;
        while ( j>=0 && s[j] == s[len1/2])
        {
            j--;
        }
        j++;
        printf("%d\n",j+1);
    }
    return 0;
}