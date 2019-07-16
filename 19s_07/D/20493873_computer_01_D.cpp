#include<iostream>
#include<string>

using namespace std;

int T;
string integer;

int main()
{
    cin>>T;

    while(T--)
    {
        cin>>integer;
        int len = integer.length();
        int getAnswer[1000][2] = {0};

        if(integer[0] == '0')
        {
            getAnswer[0][0] = 0;
            getAnswer[0][1] = 1;
        }

        else
        {
            getAnswer[0][0] = 1;
            getAnswer[0][1] = 0;
        }

        for(int i = 1; i < len; i++)
        {
            if(integer[i] == '0')
            {
                getAnswer[i][0] = getAnswer[i - 1][0];
                getAnswer[i][1] = min(getAnswer[i - 1][0], getAnswer[i - 1][1]) + 1;
            }

            else
            {
                getAnswer[i][0] = getAnswer[i - 1][0] + 1;
                getAnswer[i][1] = min(getAnswer[i - 1][0], getAnswer[i - 1][1]);
            }
        }

        cout<<min(getAnswer[len - 1][0], getAnswer[len - 1][1])<<endl;
    }
}
