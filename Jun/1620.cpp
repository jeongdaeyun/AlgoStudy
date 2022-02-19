#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int pokenum, quesnum;
    cin >> pokenum >> quesnum;

    // Declaring Data-Structures
    map<string,int> pokeMap;
    string pokeArr[pokenum+1];
    
    // Insert Part
    string pokename;
    for(int i = 1; i <= pokenum; i++)
    {
        cin >> pokename;
        pokeMap[pokename] = i;
        pokeArr[i] = pokename;
    }

    // Question Part
    string question;
    for(int i = 0; i < quesnum; i++)
    {
        cin >> question;
        // A: 64 / Z:90 / a:97 / z:122
        if (64 < question[0] && question[0] < 123)
        {
            cout << pokeMap[question] << '\n';
        }
        else
        {
            cout << pokeArr[stoi(question)] << '\n';
        }
    }
}