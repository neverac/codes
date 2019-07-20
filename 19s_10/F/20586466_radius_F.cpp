#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

const int maxn = 1005 ;
const int mn = 1e8 ;
int ma[maxn][maxn] = {0} ;
int visit[maxn] = {0} ;
int sd[maxn] ;
int td[maxn] ;
int dis[maxn] ;
int main()
{
    int n , m , s , t ;
    cin >> n >> m >> s >> t ;
    if (s>t) swap(s,t) ;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++) ma[i][j] = mn ;
    for (int i = 0 ; i < m ; i++) {
        int a , b ;
        scanf("%d%d",&a,&b) ;
        ma[a][b] = 1 ;
        ma[b][a] = 1 ;
    }

    memset(visit,0,sizeof(visit)) ;
    for (int i = 1 ; i <= n ; i++) {
        dis[i] = ma[s][i] ;
        sd[i] = mn ;
    }
    visit[s] = 1 ;
    sd[s] = 0 ;
    for (int i = 1 ; i < n ; i++) {
        int mi = mn ;
        int l = 0 ;
        for (int j = 1 ; j<= n ; j++) {
            if (mi>dis[j]&&!visit[j])
            {
                mi = dis[j] ;
                l = j ;
            }
        }
        sd[l] = dis[l] ;
        visit[l] = 1 ;
        for (int j = 1 ; j<= n ; j++) {
            if (!visit[j]&& dis[l]+ma[l][j]<dis[j])
                dis[j] = dis[l]+ma[l][j] ;
        }
    }

    memset(visit,0,sizeof(visit)) ;
    for (int i = 1 ; i <= n ; i++) {
        dis[i] = ma[t][i] ;
        td[i] = mn ;
    }
    visit[t] = 1 ;
    td[t] = 0 ;
    for (int i = 1 ; i < n ; i++) {
        int mi = mn ;
        int l = 0 ;
        for (int j = 1 ; j<= n ; j++) {
            if (mi>dis[j]&&!visit[j])
            {
                mi = dis[j] ;
                l = j ;
            }
        }

        td[l] = dis[l] ;
        visit[l] = 1 ;
        for (int j = 1 ; j<= n ; j++) {
            if (!visit[j]&& dis[l]+ma[l][j]<dis[j])
                dis[j] = dis[l]+ma[l][j] ;
        }
    }

    int ans = 0 ;
    for (int i = 1 ; i<=n ; i++) {
        for (int j = i+1 ; j <= n ; j++) {
            if (ma[i][j]==1) continue ;
            if (sd[i] + td[j] + 1 >= sd[t]
              && sd[j] + td[i] + 1 >= sd[t]) ans++ ;
        }
    }
    cout << ans << endl ;
    return 0;
}
