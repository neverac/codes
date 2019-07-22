#include<bits/stdc++.h>
using namespace std;
char s[505];
bool f;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
	{
        scanf("%s", s);
        int l=strlen(s);
        f=1;
        for(int i=0;i<l;i++){
            if(s[i]=='+'||s[i]=='*')
			{
                if(i==0||i==l-1)
				{
                    f=0;
                    break;
                }
                else if(s[i+1]=='+'||s[i+1]=='*')
				{
                    f=0;
                    break;
                }
            }
            else if(s[i]=='0'){
                if(i==0||s[i-1]=='+'||s[i-1]=='*')
				{
                    if(i<l-1&&s[i+1]>='0'&&s[i+1]<='9')
					{
                        f=0;
                        break;
                    }
                    else if(i<l-1&&s[i+1]=='?')
					{
                        s[i+1]='+';
                    }
                }
            }
            else if(s[i]=='?')
			{
                s[i]='1';
            }
        }

        if(f) printf("%s\n", s);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}