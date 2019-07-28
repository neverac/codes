#include <bits/stdc++.h>
using namespace std;

string str1;
int len;
void check(int x){
    int l=0, r=len-1;
    while(l<r){
        if(l==x) l++;
        if(str1[l]==str1[r]) l++, r--;
        else break;
    }
    if(l>=r) return ;
    else x=len-1-x;
    return ;
}
int main(){
    cin >> str1;
    len=str1.length();
    int index;
    for(index=0;index<len/2 && str1[index]==str1[len-1-index];index++) ;
    if(index>=len/2) index=len/2;
    else check(index);
    for(index;str1[index]==str1[index-1];index--);
    cout << index+1 << endl;
    return 0;
}
