#include<iostream>

using namespace std;

typedef long long ll;
int n;
int matrix[1000][1000];

int temp(int x, int y, int value)
{
    if(matrix[x + 1][y + 1] == matrix[x][y] + 2 &&
        matrix[x + 1][y] == matrix[x][y] + 1 &&
        matrix[x][y + 1] == matrix[x][y] + 1)
    {
        value++;
        return temp(x + 1, y + 1, value);
    }

    return value;
}

int getAnswer()
{
    int largest = temp(0, 0, 1);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(temp(i, j, 1) > largest)
                largest = temp(i, j, 1);
        }
    }

    return largest;
}

int main()
{
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
    }

    cout<<getAnswer()<<endl;

    return 0;
}
