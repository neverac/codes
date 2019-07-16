#include <cstring>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int cnt;
int binary_search(int l, int h){
	int rep, res;
	while(h >= l){
		if(l == h) return l;
		int mid = (l + h) >> 1;
		printf("> %d\n", mid);
		cnt++;
		fflush(stdout);
		scanf("%d", &rep);
		if(rep){
			res = mid + 1;
			l = mid + 1;
		}
		else{
			h = mid;
		}
	}
	return res;
}


int gcd(int a, int b){
	int tmp;
	if(a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	while(b != 0){
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}


int oc[1000010];
int store[66], tp;

int main()
{
	srand(time(0));
	int n, top, rnd, i, a, mx = 0;
	scanf("%d", &n);
	
	while(cnt < 30 && tp < n){
		cnt++;
		do{
			rnd = (long long)rand() * rand() % n + 1;
		}while(oc[rnd]);
		oc[rnd] = 1;
		printf("? %d\n", rnd);
		fflush(stdout);
		scanf("%d", &rnd);

		store[tp++] = rnd;
		if(rnd > mx) mx = rnd;
	}

	top = binary_search(mx, 1000000000);

	while(cnt < 60 && tp < n){
		cnt++;
		do{
			rnd = (long long)rand() * rand() % n + 1;
		}while(oc[rnd]);
		oc[rnd] = 1;
		printf("? %d\n", rnd);
		fflush(stdout);
		scanf("%d", &rnd);

		store[tp++] = rnd;
	}





	for(i = 0; i < tp - 1; i++){
		store[i] = abs(store[i + 1] - store[i]);
	}
	tp--;

	int d = store[0];
	
	for(i = 0; i < tp; i++){
		d = gcd(d, store[i]);
	}
	a = top - d * (n - 1);
	printf("! %d %d\n", a, d);

	return 0;
}
