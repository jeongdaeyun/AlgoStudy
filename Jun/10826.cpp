#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string fibo[20001];
string string_add(string num1, string num2);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fibo[0] = "0";
    fibo[1] = "1";
    for(int i = 2; i <= n; i++) fibo[i] = string_add(fibo[i-1],fibo[i-2]);
    cout << fibo[n] << '\n';    
}

string string_add(string num1, string num2)
{
    int size1 = num1.length(), size2 = num2.length();
    int isCarry = 0, char1, char2, sum;
    string result = "";

    // 자리수 맞추기
    for (int i = 0; i < size1 - size2; i++)
    {
        num2.insert(num2.begin(),'0');
    }

    for (int i = size1 - 1; i >= 0; i--)
    {
        char1 = num1[i] - '0';
        char2 = num2[i] - '0';
        sum = char1 + char2 + isCarry;

        if(sum < 10)
        {
            isCarry = 0;
            result += (sum + '0');
        }
        else
        {
            isCarry = 1;
            result += (sum - 10 + '0');
            if(i == 0) result += '1';
        }
    }
    reverse(result.begin(), result.end());
    return result;
}