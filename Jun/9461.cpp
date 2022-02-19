#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TEST_CASE, tri;
    cin >> TEST_CASE;

    long long arr[101];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;

    for(int i = 3; i < 101; i++)
    {
        arr[i] = arr[i-2] + arr[i-3];
    }

    for(int i = 0; i < TEST_CASE; i++)
    {
        cin >> tri;
        cout << arr[tri-1] << '\n';
    }
    return 0;
}