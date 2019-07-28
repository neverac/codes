#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <queue>
struct node {
    int l , r ;
};

using namespace std;
int ma[205][205] ;
int ans[205] ;
int visit[205] ;
int dis[205] ;
int main()
{
    int n ;
    while (scanf("%d",&n)) {
        if (n==0) break ;
        int e ;
        scanf("%d",&e) ;
        memset(ma,0,sizeof(ma)) ;
        memset(ans,0,sizeof(ans)) ;
        int maxn = 1 ;
        for (int i = 0 ; i < e ; i++) {
            int a , b ;
            scanf("%d%d",&a,&b) ;
            ma[a][ ++ma[a][0] ] = b ;
            ma[b][ ++ma[b][0] ] = a ;
        }
        for (int i = 0 ; i < n ; i++) {
            memset(visit,0,sizeof(visit)) ;
            memset(dis,0,sizeof(dis)) ;
            visit[i] = 1 ;
            dis[i] = 0 ;
            queue<node> s ;
            for (int j = 1 ; j <= ma[i][0] ; j++) {
                node temp ;
                temp.l = i ;
                temp.r = ma[i][j] ;
                s.push(temp) ;
                visit[ma[i][j] ] = 1 ;
            }
            while(!s.empty()) {
                node temp = s.front() ;
                s.pop() ;
                dis[temp.r] = dis[temp.l] + 1 ;
                for (int j = 1 ; j <= ma[temp.r][0] ; j++ ) {
                    if (visit[ma[temp.r][j]]) continue ;
                    node temp1 ;
                    temp1.l =  temp.r ;
                    temp1.r = ma[temp.r][j] ;
                    s.push(temp1) ;
                    visit[ ma[temp.r][j] ] = 1 ;
                }
            }
            for (int j = 0 ; j < n ; j++) {
                ans[ dis[j] ] ++ ;
                maxn = max(maxn , dis[j]) ;
            }
        }
        for (int i = 1 ; i<= maxn ; i++) {
            printf("%d %d\n",i , ans[i]) ;
        }
    }
    return 0;
}
