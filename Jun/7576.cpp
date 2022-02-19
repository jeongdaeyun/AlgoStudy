#include <iostream>
#include <deque>
#include <cstring>
#define INF 123456789
using namespace std;

int ripday[100][100][100];
int matrix[100][100][100];

int dx[6] = { 1,-1, 0, 0, 0, 0};
int dy[6] = { 0, 0, 1,-1, 0, 0};
int dz[6] = { 0, 0, 0, 0, 1,-1};

int width, height, level, nx, ny, nz, cx, cy, cz;

deque<int> dq;

void bfs();

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> width >> height >> level;

    for(int i = 0; i < level; i++)
    {
        for(int j = 0; j < height; j++)
        {
            for(int k = 0; k < width; k++)
            {
                cin >> matrix[i][j][k];
                if(matrix[i][j][k] == 1)
                {
                    dq.push_back(i * 10000 + j * 100 + k);
                }
            }
        }
    }

    bfs();

    int maxday = 0;
    bool check = false;
    for(int i = 0; i < level; i++)
    {
        for(int j = 0; j < height; j++)
        {
            for(int k = 0; k < width; k++)
            {
                if(matrix[i][j][k] == 0)
                {
                    check = true;
                    break;
                }
                maxday = max(maxday,ripday[i][j][k]);
            }
        }
    }

    if(!check) cout <<  maxday << '\n';
    else cout << -1 << '\n';

    return 0;    
}

void bfs()
{
    while(!dq.empty())
    {
        int pos = dq.front();
        dq.pop_front();

        cx = pos % 100;
        cy = (pos / 100) % 100;
        cz = pos / 10000;

        for(int i = 0; i < 6; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];
            nz = cz + dz[i];
            if (0 <= nx && nx < width && 0 <= ny && ny < height && 0 <= nz && nz < level && matrix[nz][ny][nx] == 0)
            {
                dq.push_back(nz * 10000 + ny * 100 + nx);
                ripday[nz][ny][nx] = ripday[cz][cy][cx] + 1;
                matrix[nz][ny][nx] = 1;
            }
        }
    }
}