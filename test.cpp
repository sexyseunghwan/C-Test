#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

int matrix[101][101];
int visit[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N;

void dfs(int x, int y, int min_val)
{
    visit[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= N || matrix[new_x][new_y] <= min_val || visit[new_x][new_y] == 1)
            continue;

        dfs(new_x, new_y, min_val);
    }
}

int main()
{
    int min_layer = INT_MAX;
    int max_layer = INT_MIN;
    int max_count = 1;

    cin >> N;

    for (int i = 0; i < N * N; i++)
    {
        int input;
        cin >> input;
        min_layer = min(min_layer, input);
        max_layer = max(max_layer, input);
        matrix[i / N][i % N] = input;
    }

    for (int i = min_layer; i <= max_layer; i++)
    {

        int count = 0;

        memset(visit, 0, sizeof(visit));

        for (int j = 0; j < N * N; j++)
        {
            int row = j / N;
            int col = j % N;

            if (matrix[row][col] > i && visit[row][col] == 0)
            {
                dfs(row, col, i);
                count++;
            }
        }
        max_count = max(max_count, count);
    }

    cout << max_count;

    return 0;
}
