#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
char _ch[10000];
char* const ch = _ch + 1000;
bool C(const int n);

int main()
{
	int T;
	scanf("%d", &T);


	while (T--)
	{
		scanf(" \n%s", ch + 1);
		int n = 0;
		while (ch[++n]);
		--n;

		for (int i = 1; i <= n; ++i)
		{
			if (ch[i] == '?')
			{
				if (ch[i - 1] == '0' && !('0' <= ch[i - 2] && ch[i - 2] <= '9'))
				{
					ch[i] = '+';
				}
				else
				{
					ch[i] = '1';
				}
			}
		}
		if (C(n))
		{
			printf("%s\n", ch + 1);
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}


	return 0;
}

bool C(const int n)
{
	if (ch[1] == '+' || ch[n] == '+' || ch[1] == '*' || ch[n] == '*')
	{
		return false;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (ch[i] == '0')
		{
			if (ch[i + 1] && ch[i + 1] != '+' && ch[i + 1] != '*')
			{
				return false;
			}
		}
		else if ('1' <= ch[i] && ch[i] <= '9')
		{
			while (ch[i] && ch[i] != '+' && ch[i] != '*')
			{
				++i;
			}
			--i;
		}
		else if (ch[i] == '+' || ch[i] == '*')
		{
			if (ch[i + 1] == '+' || ch[i + 1] == '*')
			{
				return false;
			}
		}
	}
	return true;
}
