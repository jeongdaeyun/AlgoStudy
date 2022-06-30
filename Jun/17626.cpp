#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int arr[50001];

    cin >> n;
    for(int i = 0 ; i < 50001; i++)
    {
        arr[i] = 5;
    }
    arr[0] = 0;
    arr[1] = 1;
    int low = 5;
    for(int i = 2; i < n+1; i++)
    {
        low = 5;
        for (int j = 0; j < i; j++){
            if(j * j > i) break;
            int tmp = i - (j*j);
            low = min(low,arr[tmp]);
        }
        arr[i] = low + 1;
    }
    cout << arr[n] << endl;
    return 0;
}