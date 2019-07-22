#include<iostream>
#include<algorithm>
#define N 510
using namespace std;
int t;
char s[510];
int main()

{
	bool fuck = 0;
	int i, j, k;
	scanf("%d", &t);
	while (t > 0) {
		fuck = 0;
		t--;
		bool guer = 0;
		scanf("%s", s);
		int len = strlen(s);

		if (s[0] == '+' || s[0] == '*') {
			printf("IMPOSSIBLE\n");
			fuck = 1;
		}
		if (s[0] == '0') {
			if (len >= 2) {
				guer = 1;
			}
		}
		if (s[0] == '?') {
			s[0] = '1';
		}

		for (i = 1; i < len-1 && !fuck; i++) {
			//符号
			if (s[i] == '*' || s[i] == '+') {
				if (s[i - 1] == '*' || s[i - 1] == '+') {
					printf("IMPOSSIBLE\n");
					fuck = 1;
					break;
				}
				if (s[i - 1] == '0') {
					guer = 0;
				}
			}
			//如果是0
			if (s[i] == '0') {
				if (guer) {
					printf("IMPOSSIBLE\n");
					fuck = 1;
					break;
				}
				if (s[i - 1] == '*' || s[i - 1] == '+') {
					guer = 1;
				}
			}
			//如果前面是1
			if (s[i] >= '1' && s[i] <= '9') {
				if (guer) {
					printf("IMPOSSIBLE\n");
					fuck = 1;
					break;
				}
			}

			if (s[i] == '?') {
				if (guer) {
					s[i] = '+';
					guer = 0;
				}
				else {
					s[i] = '1';
				}
			}
		}
		if (!fuck) {
			if (s[len - 1] == '?') {
				if (guer) {
					printf("IMPOSSIBLE\n");
					fuck = 1;
				}
				else {
					s[len - 1] = '1';
				}
			}
			else if (s[len - 1] == '*' || s[len - 1] == '+') {
				printf("IMPOSSIBLE\n");
				fuck = 1;
			}
			else {
				if (guer) {
					printf("IMPOSSIBLE\n");
					fuck = 1;
				}
			}
		}

		if (!fuck) {
			printf("%s\n", s);
		}
		
	}
	return 0;
}