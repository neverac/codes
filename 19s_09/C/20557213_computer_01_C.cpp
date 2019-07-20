#include<bits/stdc++.h>

using namespace std;

int T;
int n;

int getDivisor(int x, int y)
{
    if(x < y)
    {
        swap(x, y);
    }

    return y == 0 ? x : getDivisor(y, x % y);
}

int main()
{
	cin>>T;

	while(T--)
    {
        cin>>n;

		int answer = getDivisor(n, 180);

		answer = 180 / answer;

		while(180 - 360 / answer < n)
            answer *= 2;

		cout<<answer<<endl;
	}

	return 0;
}
