#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> queenPos;
int cnt = 0;
int num_queen;

bool CheckPos(int cx, int cy)
{
    for(int i = 0; i < queenPos.size(); i++)
    {
        int lx = queenPos[i].first;
        int ly = queenPos[i].second;

        if(cx == lx || cy == ly || cx + cy == lx + ly || cx - cy == lx - ly)
            return false;
    }
    return true;
}

void PlaceQueen(int row){
    if(queenPos.size() == num_queen)
    {
        cnt += 1;
        return;
    }
    else
    {
        for(int i = 0; i < num_queen; i++)
        {
            if(CheckPos(row,i))
            {
                queenPos.push_back(make_pair(row,i));
                PlaceQueen(row+1);
                queenPos.pop_back();
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int size;

    cin >> size;
    num_queen = size;
    PlaceQueen(0);
    cout << cnt;
    return 0;
}