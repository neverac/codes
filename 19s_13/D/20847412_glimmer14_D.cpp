#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 102;
vector<int> v[N];
priority_queue<int> q[N];
int ccp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, sum = 0, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i ++)
    {
        cin >> a >> b;
        b = (b + n - a) % n;
        if (b != 0) v[a - 1].push_back(b), sum++;
    }
    int ans = 0, ss;
    vector<int>::iterator it;
    for (int i = 0; i < n; i ++)
    {
        // cout << i << endl;
        ss = sum, cnt = 0;
        
        for (int j = 0; j < n;j ++)
        {
            for (it = v[j].begin(); it != v[j].end(); it ++)
            {
                q[j].push(*it);
            }
        }
        // int bb = 0;
        ans = 0;
        for (int j = i; ss || cnt; j = (j + 1) % n)
        {
            // bb ++;
            // if (bb == 30) break;
            // cout << j << ' ' << ss << cnt <<  endl;
            if (!q[j].empty())
            {
                b = q[j].top();
                q[j].pop();
                b = (b + j) % n;
                ccp[b] ++;
                cnt ++;
                ss --;
            }
            cnt -= ccp[j];
            ccp[j] = 0;
            ans++;
            // cout << ans << endl;
        }
        cout << ans  - 1;
        if (i != n - 1) cout << " ";
        // if (i == 2)
        // break;
    }
    cout << endl;
}