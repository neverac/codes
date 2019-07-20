#include <bits/stdc++.h>
using namespace std;
char amap[1005][1005];
int allb = 0;
struct Node{
    int x;
    int y;
    Node(int xi, int yi){
        x = xi; y = yi;
    }
};
queue<Node> man;
const int arr[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int main(){
    int H, W;
    scanf("%d %d", &H, &W);
    getchar();
    for (size_t i = 0; i < (size_t)H; i++) {
        for (size_t j = 0; j < (size_t)W; j++) {
            amap[i][j] = getchar();
            if(amap[i][j] == '#'){
                allb++;
                Node node(i, j);
                man.push(node);
            }
        }
        getchar();
    }
    // for (size_t i = 0; i < (size_t)H; i++) {
    //     for (size_t j = 0; j < (size_t)W; j++) {
    //         printf("%c", amap[i][j]);
    //     }
    //     printf("\n");
    // }
    int ans = 0;
    while(allb < H * W){
        int l = man.size();
        for (size_t i = 0; i < (size_t)l; i++) {
            Node node = man.front();
            man.pop();
            for (size_t j = 0; j < 4; j++) {
                if(node.x + arr[0][j] < H && node.x + arr[0][j] >= 0 && node.y + arr[1][j] >= 0 && node.y + arr[1][j] < W && amap[node.x + arr[0][j]][node.y + arr[1][j]] == '.'){
                    amap[node.x + arr[0][j]][node.y + arr[1][j]] = '#';
                    allb++;
                    Node newnode(node.x + arr[0][j],node.y + arr[1][j]);
                    man.push(newnode);
                }
            }
        }
        ans++;
    }
    printf("%d\n", ans);
}