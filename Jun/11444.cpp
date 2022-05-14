#include <iostream>
#include <cstring>
#include <map>

// #define MOD 1000000007
using namespace std;

map<long long, long long> fibo;

int docagne(long long num){
    if(num < 0) return 0;
    else if (fibo.count(num) > 0) return fibo[num];
    else
    {
        if (num % 2 == 0)
        {
            long long even = docagne(num / 2);
            long long odd = docagne(num / 2 - 1);
            fibo[num] = even * (2 * odd + even);
            return fibo[num];
        }
        else
        {
            long long even = docagne(num / 2);
            long long odd = docagne(num / 2 + 1);
            fibo[num] = (even * even) + (odd * odd);
            return fibo[num];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    fibo[0] = 0;
    fibo[1] = 1;
    cout << docagne(n)<< '\n';
}