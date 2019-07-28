#include <bits/stdc++.h>
using namespace std;
int cntPo = 0;
int cntUn = 0;
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x > 0)
            cntPo ++;
        else if(x < 0)
            cntUn ++;
    }
    int com = (n % 2 == 0)? n / 2 : (int)(n / 2) + 1;
    // cout << com << endl;
    if (cntPo >= com)
        printf("1\n");
    else if(cntUn >= com)
        printf("-1\n");
    else printf("0\n");
    return 0;
}