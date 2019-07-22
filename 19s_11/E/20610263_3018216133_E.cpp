#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100005];
int a[100005];
int b[100005];

int cmp(int a,int b)
{
    if(a > b)return 1;
    else return 0;
}

int main()
{
    cin >> n;
    //cin >> arr[0];
    //a[0] = 1;
    for(int i = 0;i < n;i++)
    {
        cin >> arr[i];
        a[i] = arr[i];
        b[i] = arr[i];
    }
    sort(a,a+n);
    sort(b,b+n,cmp);
    //cout << b[0] << b[1] << endl;
    int cnt1 = 0,cnt2 = 0;
    int sw1[2],sw2[2];
    for(int i = 0;i < n;i++)
    {
        if(a[i] != arr[i]){
            cnt1++;
            if(cnt1 >= 3)break;
            sw1[cnt1-1] = i+1;
        }
    }
    for(int i = 0;i < n;i++)
    {
        if(b[i] != arr[i]){
            cnt2++;
            if(cnt2 >= 3)break;
            sw2[cnt2-1] = i+1;
        }
    }
    //cout << cnt1 << endl;
    if(cnt1 >= 3&& cnt2 >=3){
        cout << "No hope" << endl;
    }else if(cnt1 == 0 || cnt2 == 0){
        cout << "Nothing to do here" << endl;
    }else{
        cout << "YES" << endl;
        if(cnt1 == 2){
            cout << sw1[0] << " " << sw1[1] << endl;
        }else{
            cout << sw2[0] << " " << sw2[1] << endl;
        }
    }
    return 0;
}
