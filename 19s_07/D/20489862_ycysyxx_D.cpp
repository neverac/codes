#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    string str;
    while(T--){
        cin >> str;
        int l = str.length();
        int ans = INT_MAX;
        int now = 0;
        for (int i = 0; i <= l; i++) {
            now = 0;
            for (int j = 0; j < l; j++) {
                if (j >= l - i){
                    if(str[j] != '1')
                        now++;
                }else{
                    if(str[j] != '0')
                        now++;

                }
            }
            ans = min(ans, now);
            if(ans == 0)
                break;
        }
        printf("%d\n", ans);
    }
}
