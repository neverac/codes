#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		string str;
		cin >> str;
		int len = str.length();
		bool check = 1;
		string num;
		for(int i = 0; i < len ;i++){
			if(i == 0){
				if(str[i] == '?'){
					str[i] = '1';
					num += str[i];
					continue;
				}else if(str[i] == '*' || str[i] == '+'){
					printf("IMPOSSIBLE\n");
					check = 0;
					break;
				}else{
					num += str[i];	
				}
 			}else if(i == len - 1){
 				if(str[i] == '?'){
 					str[i] = '1';
 					num += str[i];
 					if(num.length() != 1 && num[0] == '0'){
						printf("IMPOSSIBLE\n");
						check = 0;
						break;
					}
				}else if(str[i] == '*' || str[i] == '+'){
					printf("IMPOSSIBLE\n");
					check = 0;
					break;
				}else{
					num += str[i];
					if(num.length() != 1 && num[0] == '0'){
						printf("IMPOSSIBLE\n");
						check = 0;
						break;
					}
				}
			}else{
				if(str[i] == '?'){
					if(num.length() == 1 && num[0] == '0'){
						str[i] = '+';
						num = "";
					}
					else {
						str[i] = '1';
						num += str[i];
						continue;
					}
				}else if(str[i] == '*' || str[i] == '+'){
					if(str[i-1] == '*' || str[i-1] == '+'){
						printf("IMPOSSIBLE\n");
						check = 0;
						break;
					}
					if(num.length() != 1 && num[0] == '0'){
						
						printf("IMPOSSIBLE\n");
						check = 0;
						break;
					}else num = "";
				}else{
					num += str[i];
					if(num.length() != 1 && num[0] == '0'){

						printf("IMPOSSIBLE\n");
						check = 0;
						break;
					}
				}
			}
		}
		if(check)
			cout << str << endl;
		else continue;
	}
}