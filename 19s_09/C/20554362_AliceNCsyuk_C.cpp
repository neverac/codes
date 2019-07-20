#include<iostream>
using namespace std;
int T;
int ang;
long long ans;
double temp;
int tempans;
double tempansd;
long long n;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>ang;
		n=3;
		while(1)
		{
			temp=180/(n*1.0);
			tempansd=ang/temp;
			tempans=tempansd;
			if(tempans==tempansd)
			{
				if(180-2*temp>=ang)
				{
					break;
				}
			}
			n++;
		}
		cout<<n<<endl;
	}
	return 0;
}