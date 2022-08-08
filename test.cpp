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
}

int main()
{
    cin >> N;

    for (int i = 0; i < N * N; i++)
        cin >> matrix[i / N][i % N];

    return 0;
}
