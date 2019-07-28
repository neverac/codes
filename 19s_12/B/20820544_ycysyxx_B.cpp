#include <bits/stdc++.h>
using namespace std;
string str;
int len;
bool check(int begin, int last){
    while (begin < last) {
        if(str[begin] == str[last]){
            begin ++;
            last --;
        }else{
            return 0;
        }
    }
    return 1;
}
int main(){
    cin >> str;
    int begin = 0, last = str.length() - 1;
    int father[str.length()] = {0};
    father[0] = 0;
    father[str.length() - 1] = str.length() - 1;
    while (begin < last) {
        if(begin > 0 && last < (int)str.length() - 1){
            if(str[begin] == str[begin - 1])
                father[begin] = father[begin - 1];
            else father[begin] = begin;
        }
        if(str[begin] == str[last]){
            begin ++;
            last --;
        }else{
            if(str[begin + 1] == str[last]){
                if(check(begin + 1, last)){
                    printf("%d\n", father[begin] + 1);
                    return 0;
                }
            }
            if(check(begin, last - 1)){
                while(str[last - 1] == str[last])
                    last--;
                printf("%d\n", last + 1);
            }
            return 0;
        }
    }
    if(str.length() % 2 == 0){
        int sans = str.length() / 2 - 1;
        while(str[sans - 1] == str[sans])
            sans --;
        printf("%d\n",sans + 1);
    }
    else {
        int sans = str.length() / 2;
        while(str[sans - 1] == str[sans])
            sans --;
        printf("%d\n",sans + 1);
    }
}
