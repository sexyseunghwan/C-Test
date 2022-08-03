#include <iostream>
#include <queue>
#include <vector>
#include <climits>

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

        if (new_x < N && new_y < N && new_x >= 0 && new_y >= 0 && matrix[new_x][new_y] > min_val && visit[new_x][new_y] == 0)
            dfs(new_x, new_y, min_val);
    }
}

int main()
{
    int min_val = 101;
    int max_val = 0;
    int max_count = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input_num;
            cin >> input_num;
            min_val = min_val > input_num ? input_num : min_val;
            max_val = input_num > max_val ? input_num : max_val;
            matrix[i][j] = input_num;
        }
    }

    for (int s = min_val; s <= max_val; s++)
    {
        int count = 0;

        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 101; j++)
            {
                visit[i][j] = 0;
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visit[i][j] == 0 && matrix[i][j] > min_val)
                {
                    dfs(i, j, s);
                    count++;
                }
            }
        }
        cout << "\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << visit[i][j] << " ";
            }
            cout << "\n";
        }

        cout << count << "\n";
        max_count = max_count > count ? max_count : count;
    }

    cout << max_count;

    return 0;
}
