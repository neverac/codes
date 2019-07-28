#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;
typedef long long ll;
string S;
int len,ans;
int main(){
    getline(cin,S);
    len=S.length();
    for (int i=0; i<len/2; i++){
        if (S[i]!=S[len-i-1]) {
            bool f=true;
            for (int j=i; j<(len-1)/2; j++){
                if (S[j]!=S[len-j-2]){
                    f=false;
                    break;
                }
            }
            if (f) ans=len-i-1;
            f=true;
            for (int j=i+1; j<(len+1)/2; j++){
                if (S[j]!=S[len-j]){
                    f=false;
                    break;
                }
            }
            if (f) ans=i;
            break;
        }
    }
    if (ans==0) {
        ans=len/2;
    }
    int count=0;
     for (int i=ans-1; i>=0; i--){
        if (S[ans]==S[i]) {
            count++;
        }
        else break;
    }
    printf("%d\n",ans-count+1);
    return 0;
}