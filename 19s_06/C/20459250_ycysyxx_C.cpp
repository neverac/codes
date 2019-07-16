#include <bits/stdc++.h>
using namespace std;
struct Node{
    int n;
    int index;
}sorted[200005];
bool cmp(Node a, Node b){
    return a.n > b.n;
}
bool cmpn(int a, int b){
    return a < b;
}
int pre[200005];
int indexmem[200005];
int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int allneed = m * k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        sorted[i].index = i + 1;
        sorted[i].n = pre[i];
    }
    sort(sorted, sorted + n, cmp);
    long long sum = 0;
    for (int i = 0; i < allneed; i++) {
        sum += (long long)sorted[i].n;
        indexmem[i] = sorted[i].index;
    }
    printf("%lld\n", sum);
    sort(indexmem, indexmem + allneed, cmpn);
    int cnt = 0;
    for (int i = m - 1; cnt < k - 1; i += m) {
        if (!cnt)
            printf("%d", indexmem[i]);
        else  printf(" %d", indexmem[i]);
        cnt++;
    }
}