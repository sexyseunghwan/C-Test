#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int N;
int matrix[501][501];
int visit[501][501];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int max_count = 0;
int per_max_count;

void dfs(int r, int c, int cnt) {
    visit[r][c] = 1;
    per_max_count = max(per_max_count,cnt);

    for (int i = 0; i < 4; i++) {
        int new_r = r + dr[i];
        int new_c = c + dc[i];
        
        if (new_r >= 0 && new_c >= 0 && new_r < N && new_c < N && matrix[new_r][new_c] > matrix[r][c] && visit[new_r][new_c] == 0) {
            dfs(new_r,new_c,cnt+1);
        }
    }
    //visit[r][c] = 0;
}

int main() {

    cin >> N;

    for (int i = 0; i < N*N; i++) cin >> matrix[i/N][i%N];

    for (int i = 0; i < N*N; i++) {
        per_max_count = 0;
        dfs(i/N,i%N,1);
        max_count = max(max_count,per_max_count);
    } 

    cout << max_count;
    
    return 0;
}