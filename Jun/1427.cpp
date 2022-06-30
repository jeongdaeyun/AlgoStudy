#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool compare(char a, char b)
{
    if (a > b) return true;
    if (a < b) return false;
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string numString;
    cin >> numString;
    // Iterator : 반복 가능하다 (딕셔너리, 배열, 리스트, 튜플 등등등)
    sort(numString.begin(), numString.end(), compare);
    cout << numString << endl;
}