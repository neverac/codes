// #include <bits/stdc++.h>
// using namespace std;
// int cntPo = 0;
// int main(){
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         int x;
//         scanf("%d", &x);
//         if (x > 0)
//             cntPo ++;
//     }
//     int com = (n % 2 == 0)? n / 2 : (int)(n / 2) + 1;
//     // cout << com << endl;
//     if (cntPo >= com)
//         printf("4\n");
//     else printf("0\n");
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int x;
    int y;
}Nodes[100005];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        int xi;
        scanf("%d", &xi);
        if(Nodes[xi].x == 0){
            Nodes[xi].x = i;
        }else Nodes[xi].y = i;
    }
    long long ans = 0;
    int posA = 0, posB = 0;
    for(int i = 1; i <= n; i++){
        if (abs(Nodes[i].x - posA) + abs(Nodes[i].y - posB) < abs(Nodes[i].y - posA) + abs(Nodes[i].x - posB)){
            ans += abs(Nodes[i].x - posA) + abs(Nodes[i].y - posB);
            posA = Nodes[i].x;
            posB = Nodes[i].y;
        }else{
            ans += abs(Nodes[i].y - posA) + abs(Nodes[i].x - posB);
            posA = Nodes[i].y;
            posB = Nodes[i].x;
        }
    }
    printf("%lld\n", ans);

}
