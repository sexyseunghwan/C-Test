#include <iostream>

using namespace std;

int N;
int map[501][501];
int check[501][501];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int max_count;

int dp (int r, int c){

    if (check[r][c] != 0) return check[r][c];
    
    check[r][c] = 1;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nc >= 0 && nr < N && nc < N && map[nr][nc] > map[r][c]) {
            check[r][c] = max( check[r][c] , dp(nr,nc) + 1);
        }
    }
    
    return check[r][c];
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;


    for (int i = 0; i < N*N; i++) cin >> map[i/N][i%N];

    for (int i = 0; i < N*N; i++) {
        max_count = max(dp(i/N,i%N),max_count);
    }

    cout << max_count;
    
    
    return 0;
}

