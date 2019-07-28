#include <iostream>

using namespace std;

int num[10];

int main()
{
    int p,q,re;
    cin >> p >> q;
    int n = 60;
    while(p<=q)
    {
        p*=10;
    }
    while(n--&&p!=0)
    {num[p/q]++;
        p = p % q;
        p*=10;
    }


    for(int i = 0;i < 10;i++)
        if(num[i] > 0)cout << i;
    cout << endl;
    return 0;
}
