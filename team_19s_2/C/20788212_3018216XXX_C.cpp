#include <iostream>
#include <string.h>
using namespace std;
struct bign{
    int d[1050];
    int len;
    bign (){
        memset(d,0,sizeof(d));
        len = 0;
    }
};
bign c[400][400];
int a,b,x;
void fun(){
    for(int i = 0;i <= a;i++){
        c[i][0].len = c[i][i].len = 1;
        c[i][0].d[0] = c[i][i].d[0] = 1;
    }

    for(int i = 2;i <= a;i++){
        for(int j = 0;j <= i / 2;j++){
            bign temp1 = c[i-1][j] ;
            bign temp2 = c[i-1][j-1];
            bign ans;
            int carry = 0;
            for(int k = 0;k < temp1.len || k < temp2.len;k++){
                int t = temp1.d[k] + temp2.d[k] + carry;
                ans.d[ans.len++] = t % x;
                carry = t / x;
            }
            if(carry != 0){
                ans.d[ans.len++] = carry;
            }
            c[i][j] = ans;
            c[i][i-j] = c[i][j];
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);
    int p;
    cin >> p;
    while(p--){
        memset(c,0,sizeof(c));
        cin >> a >> b >> x;
        fun();
        //cout << c[a][b].len << endl;
        for(int i = c[a][b].len - 1;i >= 0;i--){
            cout << c[a][b].d[i];
        }
        cout << endl;
    }
    return 0;
}