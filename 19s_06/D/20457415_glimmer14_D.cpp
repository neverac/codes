#include <iostream>
using namespace std;

int main()
{
    int hh[2][3];
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j < 3; j++)
            cin >> hh[i][j];
    int aa = 0, bb = 0;
    bool ans = true;
    for (int i = 0; i < 3; i++)
    {
        aa += hh[0][i];
        bb += hh[1][i];
        if (aa > bb)
        {
            ans = false;
            break;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
}