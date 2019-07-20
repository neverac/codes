#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,sum;
int a[500500];
int cnt[50],tmp;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	sum = n;
	tmp = 0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] == 4){
			cnt[4] ++;
		}
		else if(a[i] == 8 && cnt[4]>0){
			cnt[8] ++;
			cnt[4] --;
		}
		else if(a[i]==15 && cnt[8]>0){
			cnt[15]++;
			cnt[8] --;
		}
		else if(a[i]==16 && cnt[15]>0){
			cnt[16] ++;
			cnt[15] --;
		}
		else if(a[i]==23 && cnt[16]>0){
			cnt[23] ++;
			cnt[16] --;
		}
		else if(a[i]==42 && cnt[23]>0){
			cnt[42] ++;
			cnt[23] --;
			tmp ++;
		}
	}
	cout << n-tmp*6 <<endl;
    return 0;
}
