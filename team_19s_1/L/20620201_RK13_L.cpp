#include <bits/stdc++.h>
using namespace std;
//int main(){
//	int T;
//	scanf("%d", &T);
//	while(T--){
//		string str;
//		int len = str.length();
//		cin >> str;
//		bool check = 1;
//		for(int i = 0; i < len ;i++){
//			if(i == 0){
//				if(str[i] == '?'){
//					str[i] = 1;
//				}else if(str[i] == '*' || str[i] == '+'){
//					printf("IMPOSSIBLE\n");
//					check = 0;
//					break;
//				}
// 			}else if(i == len - 1){
// 				if(str[i] == '?'){
// 					if(str[i - 1] == '0'){
// 						printf("IMPOSSIBLE\n");
//						check = 0;
//						break;
//					}else str[i] = '1';
//				}else if(str[i] == '*' || str[i] == '+'){
//					printf("IMPOSSIBLE\n");
//					check = 0;
//					break;
//				}else{
//					if(str[i - 1]  == '0'){
//						printf("IMPOSSIBLE\n");
//						check = 0;
//						break;
//					}
//				}
//			}else{
//				if(str[i - 1]  == '0'){
//					printf("IMPOSSIBLE\n");
//					check = 0;
//					break;
//				}
//				if(str[i] == '?'){ 
//					if(str[i - 1]) 
//				} 
//			}
//		}
//	}
//}
const int maxn = 1e5+5 ;
int v[maxn];

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		for(int i = 1; i <= n ; i++){
			cin >> v[i];
		}
		int temp = pow( abs(v[n]-v[1]) , 0.5 ) ;
		cout << temp << endl ;
	}
}