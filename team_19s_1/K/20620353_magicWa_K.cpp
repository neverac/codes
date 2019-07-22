#include<bits/stdc++.h>
using namespace std;

char a[505];

bool judge(){
    int i, len = strlen(a);
    bool oflg = true, zflg = false;
    for(i = 0; i < len; i++){
		if(a[i] == '?'){
			if(zflg) a[i] = '+';
			else a[i] = '1';
		}
        if(oflg){
            if(a[i] == '+' || a[i] == '*') return false;
        }
		if(zflg){
			if(a[i] >= '0' && a[i] <= '9') return false;
		}
		oflg = zflg = false;
		if(a[i] == '+' || a[i] == '*') oflg = true;
		if(a[i] == '0' && i == 0) zflg = true;
		if(a[i] == '0' && (a[i - 1] == '+' || a[i - 1] == '*')) zflg = true;
		

    }
    if(oflg) return false;
    return true;
}



int main()
{
    int casen, i;
    scanf("%d", &casen);
    while(casen--){
        scanf("%s", a);
        if(judge()) printf("%s\n", a);
	    else printf("IMPOSSIBLE\n");
    }

    return 0;
}