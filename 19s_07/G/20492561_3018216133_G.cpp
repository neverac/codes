#include <iostream>

using namespace std;

int table[1002][1002];

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> table[i][j];
    for(int i = n-1;i > 0;i--)
        for(int j = n-1;j>0;j--)
        {
            if(table[i-1][j]+1 == table[i][j]&&table[i][j-1]+1 == table[i][j]){
                table[i][j] = 2;
            }else if(table[i-1][j]+1 == table[i][j]&&table[i][j-1]+1 != table[i][j]){
                table[i][j] = 1;
            }else if(table[i-1][j]+1 != table[i][j]&&table[i][j-1]+1 == table[i][j]){
                table[i][j] = 0;
            }else{
                table[i][j] = -1;
            }
        }
    for(int j = n-1;j > 0;j--)
    {
        if(table[0][j] - table[0][j-1] == 1)table[0][j] = 2;
        else table[0][j] = 0;//zuo
    }
    for(int i = n-1;i > 0;i--)
     {
        if(table[i][0] - table[i-1][0] == 1)table[i][0] = 2;
        else table[i][0] = 1;//shang
     }
    int ans = 1;
    for(int i = n-1;i > 0;i--)
        for(int j = n-1;j>0;j--)
        {
            if(table[i][j] == 2){
                int s1 = 1,s2=1,k = i-1,l = j-1;
                while(table[k][j] == 2 || table[k][j] == 1)
                {
                    k--;
                    s1++;
                }
                if(table[k][j] == 0)s1++;
                while(table[i][l] == 2 || table[i][l] == 0)
                {
                    l--;
                    s2++;
                }
                if(table[i][l] == 1)s2++;
                ans = max(ans,min(s1,s2));
            }
        }
    cout << ans << endl;
    return 0;
}
