#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <cmath>
#include<stdio.h>
#include <map>
//#define lowbit(i) (i&(-i))
//#define  ll long long
const int INF = 999999999;
using namespace std;
struct node{
    int pos;
    int cnt;
};
int main(){

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        node a[1005];
        node b[1005];
        int len = s.length();
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0;i < len;i++){
            if(s[i] == '1') cnt1++;
            if(s[i] == '0'){
                a[cnt2].pos = i;
                a[cnt2++].cnt = cnt1;
            }
        }
        int cnt3 = 0;
        int cnt4 = 0;
        for(int i = len - 1;i >= 0;i--){
            if(s[i] == '0') cnt3++;
            if(s[i] == '1'){
                b[cnt4].pos = i;
                b[cnt4++].cnt = cnt3;
            }
        }
        int ans = 0;
        int d0 = 0;
        int d1 = 0;

        while(cnt4 >= 1 && cnt2 >= 1 && b[cnt4-1].pos < a[cnt2-1].pos){
            //cout << cnt2 << " " <<  a[cnt2-1].pos<< " " << a[cnt2-1].cnt << " " <<
            //cnt4 << " " <<  b[cnt4-1].pos << " " << b[cnt4-1].cnt << endl;
            if(b[cnt4-1].cnt - d0 > a[cnt2-1].cnt - d1){
                cnt4--;
                d1++;
                ans++;
            }
            else{
                cnt2--;
                d0++;
                ans++;
            }
        }
        cout << ans << endl;


    }
    return 0;
}