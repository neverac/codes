#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str ;
    cin >> str ;
    int len = str.length() ;
    int i = 0 , j = len -1 ;
    if (len<=2) {
        cout << 1 << endl ;
        return 0 ;
    }
    while(i<=j) {
        if (str[i]==str[j]) {
            i++ ;
            j-- ;
        }
        else {
            if (str[i+1]==str[j]) {
                if (i+1==j) {
                    while(str[i]==str[i-1]) i-- ;
                    cout << i+1 << endl ;
                    return 0 ;
                }
                while(str[i-1]==str[i]) i-- ;
                cout << i+1 << endl ;
                return 0 ;
            }
            else {
                cout << j+1 << endl ;
                return 0 ;
            }
        }
        if (i==j) {
            while(str[i-1]==str[i]) i-- ;
            cout << i+1 << endl ;
            return 0 ;
        }
    }
    while(str[i-1]==str[i]) i-- ;
    cout << i+1 << endl ;
    return 0;
}
