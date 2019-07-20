#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 5e5 + 77;

ll N;
int a, b;
bool flag;

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        flag = true;
        for (int j = a; j < b && flag; ++j)
        {
            for (int k = 2; k <= b/a && flag; ++k)
            {
                if (j * k <= b)
                {
                    cout << j << " " << j * k << endl;
                    flag = false;
                }
            }
        }
    }
    return 0;
}