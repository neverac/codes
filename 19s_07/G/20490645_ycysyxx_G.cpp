#include <bits/stdc++.h>
using namespace std;
int matrix[1005][1005];
// bool checkable[1005][1005];
int n;
bool check(int i, int j, int ni){
    if (j + ni > n || i + ni > n)
        return false;
    bool checksuccess = 1;
    for (int k = 1; k < ni; k++) {
        for (int m = 0; m < ni; m++) {
            if(matrix[i + k][j + m] != matrix[i + k - 1][j + m] + 1)
                checksuccess = 0;
        }
    }
    return checksuccess;
}
int main(){
    // int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int ans = 0;
    int cnt = 0;
    int lastNum = 0;
    int beginI = 0;
    int beginJ = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!cnt){
                beginI = i;
                beginJ = j;
                lastNum = matrix[i][j];
                cnt++;
            }else{
                if (matrix[i][j] == lastNum + 1){
                    lastNum = matrix[i][j];
                    cnt++;
                }else{
                    if(cnt == 1){
                        beginI = i;
                        beginJ = j;
                        lastNum = matrix[i][j];
                    }else{
                        if(check(beginI, beginJ, cnt)){
                            ans = max(ans, cnt);
                        }
                        cnt = 1;
                        beginI = i;
                        beginJ = j;
                        lastNum = matrix[i][j];
                    }
                }
            }
        }
        if(cnt >= 1){
            if(check(beginI, beginJ, cnt)){
                ans = max(ans, cnt);
            }
        }
        cnt = 0;
    }
    printf("%d\n", ans);
}
