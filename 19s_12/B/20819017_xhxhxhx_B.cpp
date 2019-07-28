#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAX_N = 500009;
char ch[MAX_N];

int main()
{
	scanf(" \n%s", ch);
	int len = -1;
	while (ch[++len]);

	int lb = 0, rb = len - 1;


	while (lb < rb)
	{
		if (ch[lb] != ch[rb])
		{
			bool C = true;
			if (ch[lb + 1] == ch[rb])
			{
				while (lb > 0 && ch[lb] == ch[lb - 1])
				{
					--lb;
				}
				printf("%d\n", lb + 1);
				return 0;
			}
			else
			{
				while (rb > 0 && ch[rb] == ch[rb - 1])
				{
					--rb;
				}
				printf("%d\n", rb + 1);
				return 0;
			}
		}
		++lb;
		--rb;
	}
	if (lb >= rb)
	{
		while (lb > 0 && ch[lb] == ch[lb - 1])
		{
			--lb;
		}
		printf("%d\n", lb + 1);
		return 0;
	}

	return 0;
}