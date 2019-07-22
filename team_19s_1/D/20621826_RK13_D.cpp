//#include <bits/stdc++.h>
//using namespace std;
//int main(){
//	int T;
//	scanf("%d", &T);
//	while(T--){
//		string str;
//		cin >> str;
//		int len = str.length();
//		bool check = 1;
//		string num;
//		for(int i = 0; i < len ;i++){
//			// printf("%d\n", i); 
//			if(i == 0){
//				if(str[i] == '?'){
//					str[i] = '1';
//					continue;
//				}else if(str[i] == '*' || str[i] == '+'){
//					printf("IMPOSSIBLE\n");
//					check = 0;
//					break;
//				}else{
//					
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
//				if(str[i] == '?'){
//					if(str[i - 1] == '*' || str[i - 1] == '+'){
//						str[i] = '1';
//						continue;
//					}
//					else if(str[i - 1] == '0'){
//						str[i] = '+';
//						continue;
//					}
//					else {
//						str[i] = '1';
//						continue;
//					}
//				}else if(str[i - 1] == '*' || str[i - 1] == '+'){
//					if(str[i] == '*' || str[i] == '+'){
//						printf("IMPOSSIBLE\n");
//						check = 0;
//						break;
//					}
//				}else{
//					if(str[i] == '0'){
//						if(str[i - 1] == '*' || str[i - 1] == '+'){
//							printf("IMPOSSIBLE\n");
//							check = 0;
//							break;
//						}
//					}
//				}
//			}
//		}
//		if(check)
//			cout << str << endl;
//		else continue;
//	}
//}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
ll n, m;
ll a[1005];
int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		 for(ll i = 1; i <= n; i++){
		 	ll t1, t2; 
		 	cin >> t1 >> t2;
		 	a[i] = t1 + t2;
		 }
		 sort(a + 1, a + 1 + n);
		 ll sum = 1;
		 int ans = 0;
		 for(int i = 1; i <= n; i++){
		 	sum *= a[i];
			 if(sum > m) break;
			 ans++; 
		 }
		 cout << ans << endl;
	}
	return 0;	
} 