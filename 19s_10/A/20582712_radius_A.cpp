#include <iostream>
#include <string.h>
#include <queue>
struct node {
    int x , y , s ;
};

using namespace std;
int ma[1005][1005] ;
int main()
{
    queue<node> q ;
    int a , b ;
    cin >> a >> b ;
    int sum = a*b ;
    char ch ;
    node temp ;
    memset(ma,0,sizeof(ma)) ;
    for (int i = 0 ; i < a ; i++) {
        for (int j = 0 ; j < b ; j++) {
            cin >> ch ;
            if (ch=='#') {
                temp.x = i ;
                temp.y = j ;
                temp.s = 0 ;
                q.push(temp) ;
                sum-- ;
                ma[i][j] = 1 ;
            }
        }
    }
    if (sum==0) {
        cout << 0 << endl ;
        return 0 ;
    }
    node temp1 ;
    while(!q.empty()) {
        temp = q.front() ;
        q.pop() ;
        if (temp.x>0){
            if (!ma[temp.x-1][temp.y]) {
                ma[temp.x-1][temp.y] = 1 ;
                sum-- ;
                temp1.x = temp.x - 1;
                temp1.y = temp.y ;
                temp1.s = temp.s + 1 ;
                q.push(temp1) ;
            }
        }
        if (temp.x<a-1){
            if (!ma[temp.x+1][temp.y]) {
                ma[temp.x+1][temp.y] = 1 ;
                sum-- ;
                temp1.x = temp.x + 1;
                temp1.y = temp.y ;
                temp1.s = temp.s + 1 ;
                q.push(temp1) ;
            }
        }
        if (temp.y>0){
            if (!ma[temp.x][temp.y-1]) {
                ma[temp.x][temp.y-1] = 1 ;
                sum-- ;
                temp1.x = temp.x ;
                temp1.y = temp.y -1 ;
                temp1.s = temp.s + 1 ;
                q.push(temp1) ;
            }
        }
        if (temp.y<b-1){
            if (!ma[temp.x][temp.y+1]) {
                ma[temp.x][temp.y+1] = 1 ;
                sum-- ;
                temp1.x = temp.x ;
                temp1.y = temp.y + 1 ;
                temp1.s = temp.s + 1 ;
                q.push(temp1) ;
            }
        }
        if (sum==0) {
            cout << temp.s+1 << endl ;
            break ;
        }
    }
    return 0;
}
