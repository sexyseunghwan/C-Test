#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int N;
int map[501][501];
int dp[501][501];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int max_moving;

int dynamic_prog(int r, int c) {

    if (dp[r][c] != 0) return dp[r][c];
    dp[r][c] = 1;
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nc >= 0 && nr < N && nc < N && map[nr][nc] > map[r][c]) {
            dp[r][c] = max(dp[r][c],dynamic_prog(nr,nc) + 1);
        }
    }

    return dp[r][c];
}


int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;

    for (int i = 0; i < N*N; i++) cin >> map[i/N][i%N];

    for (int i = 0; i < N*N; i++) {
        max_moving = max(max_moving,dynamic_prog(i/N,i%N));    
    }    
    
    cout << max_moving;

    return 0;
}
