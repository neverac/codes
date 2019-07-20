#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;

#define LL long long
#define INF 0x7fffffff
#define P 998244353

inline LL read(){
    LL x=0,f=1; char ch=getchar();
    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}

char s[200010];
int main(){
	int T =read();
	while (T--){
		int ang = read();
		bool flag=0;
		int ans = 0;
		for (int i=3; i<=360; i++){
			if (!(ang*i%180) && ang*i/180<=i-2){
				printf("%d\n",i);
				break;
			}
		}
		// 	int sum = (i-2)*180;
		// 	int eve = sum/i;
		// 	if (ang==eve) {
		// 		// printf("%d\n",i);
		// 		ans=i;
		// 		flag=1;
		// 		break;
		// 	}
		// }
		// // if (flag) continue;		
		// if (ang==179){
		// 	puts("360");
		// 	continue;
		// }
		// if (ang == 90){
		// 	puts("4");
		// 	continue;
		// }
		// if (ang ==120){
		// 	puts("6");
		// 	continue;
		// }
		// if (ang == 135){
		// 	puts("8");
		// 	continue;
		// }
		// if (ang == 144){
		// 	puts("10");
		// 	continue;
		// }
		// if (ang ==150 ){
		// 	puts("12");
		// 	continue;
		// }
		// int t = gcd(180,ang);
		// int ans= 180/t;
		// int sum = (ans-2)*180/ans;
		// if (sum>=ang)
		// 	printf("%d\n",180/t);
		// else printf("%d\n",180);
	}
	// while (T--){
	// 	int ang = read();

	// }
	return 0;
}
