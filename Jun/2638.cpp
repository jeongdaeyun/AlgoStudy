#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int matrix[100][100];
int visited[100][100];
int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int time_count = 0;
deque<pair<int,int>> queue;


void bfs(int cx, int cy)
{
    int x;
    int y;
    pair<int,int> tmp;

    queue.push_back(make_pair(cx,cy));
    visited[cx][cy] = 1;

    while(!queue.empty())
    {
        tmp = queue.front();
        queue.pop_front();
        x = tmp.first;
        y = tmp.second;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(matrix[nx][ny] == 0 && visited[nx][ny] == 0)
                {
                    queue.push_back(make_pair(nx,ny));
                    visited[nx][ny] = 1;
                }
                if(matrix[nx][ny] > 0)
                {
                    matrix[nx][ny] += 1;
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> m;

    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    bool isEnd = false;

    while(!isEnd)
    {
        bfs(0,0);
        isEnd = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                visited[i][j] = 0;
                if(matrix[i][j] > 0)
                {
                    isEnd = false;
                    if(matrix[i][j] > 2) matrix[i][j] = 0;
                    else matrix[i][j] = 1;
                }
            }
        }
        time_count += 1;
    }
    cout << time_count - 1;
    return 0;
}