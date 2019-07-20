#include<iostream>

using namespace std;

typedef long long ll;
ll K, A, B;
ll biscuit;

int main()
{
    cin>>K>>A>>B;

    if(A >= B)
    {
        biscuit = K + 1;
        cout<<biscuit<<endl;
    }

    else
    {
        if(B - A < 2)
        {
            biscuit = K + 1;
        }

        else
        {
            if(K == A + 1)
            {
                biscuit = B;
            }

            else if(K < A + 1)
            {
                biscuit = K + 1;
            }

            else
            {
                ll time = (K - A - 1) / 2;
                ll modify = (K - A - 1) % 2;

                biscuit = B + time * (B - A);

                biscuit += modify;
            }
        }
        cout<<biscuit<<endl;
    }

    return 0;
}
