#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int N;
int matrix[501][501];
int dp[501][501];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int max_count = 0;

int dynamic_programing(int r, int c)
{

    if (dp[r][c] != 0)
        return dp[r][c];
    dp[r][c] = 1;

    for (int i = 0; i < 4; i++)
    {
        int new_r = r + dr[i];
        int new_c = c + dc[i];

        if (new_r >= 0 && new_c >= 0 && new_r < N && new_c < N && matrix[new_r][new_c] > matrix[r][c])
        {
            dp[r][c] = max(dp[r][c], dynamic_programing(new_r, new_c) + 1);
        }
    }

    return dp[r][c];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;

    for (int i = 0; i < N * N; i++)
        cin >> matrix[i / N][i % N];

    for (int i = 0; i < N * N; i++)
    {
        max_count = max(max_count, dynamic_programing(i / N, i % N));
    }

    cout << max_count;

    return 0;
}