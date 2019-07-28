#include <bits/stdc++.h>
using namespace std;
// int main(){
//     string str;
//     cin >> str;
//     int begin = 0, last = str.length() - 1;
//     int ans = 0;
//     while(begin < last){
//         if(str[begin] == str[last]){
//             begin++;last--;
//             continue;
//         }else{
//             if(str[begin + 1] == str[last])
//                 begin++;
//
//         }
//     }
// }
vector<int> beidi;
bool ans[10];
bool find(int n){
    vector<int>::iterator iter;
    for(iter = beidi.begin(); iter !=beidi.end(); iter++){
        if(*iter == n)
            return 1;
    }
    return 0;
}
int main(){
    int n, m;
    int now;
    scanf("%d %d", &n, &m);
    n = n % m;
    beidi.push_back(n * 10);
    int cnt = 0;
    while(true){
        n = 10 * n;
        now = n / m;
        if(!ans[now]){
            ans[now] = 1;
            cnt++;
        }
        n = n % m;
        if(find(n * 10) || n == 0 || cnt == 10){
            break;
        }
        beidi.push_back(n * 10);
    }
    for (size_t i = 0; i < 10; i++) {
        if(ans[i])
            printf("%ld", i);
    }
    printf("\n");
}
