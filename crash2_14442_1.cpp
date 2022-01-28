#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int N,M,R;
int** map;
int** visit;
int min_root = INT_MAX;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void bfs(int r, int c);

typedef struct {
    int r,c,step,crash;
} nods;

int main()
{
    scanf("%d %d %d",&N,&M,&R);

    map = new int*[N];
    visit = new int*[N];

    for (int i = 0; i < N; i++) {
        map[i] = new int[M];
        visit[i] = new int[M];
    }

    char str[M+1];

    for (int i = 0; i < N; i++) {
        scanf("%s",str);
        for (int j = 0; j < M; j++) {
            map[i][j] = str[j] - '0';
            visit[i][j] = INT_MAX;
        }
    }
    
    bfs(0,0);

    if (min_root == INT_MAX) min_root = -1;

    printf("%d",min_root);

    return 0;
}

void bfs(int r, int c) {
    queue<nods> q;
    q.push({r,c,1,0});

    while(!q.empty()) {
        nods nd = q.front();
        q.pop();

        if (nd.r == N-1 && nd.c == M-1) {
            min_root = nd.step;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = nd.r + dr[i];
            int nc = nd.c + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M ) continue;
            
            if (visit[nr][nc] <= nd.crash) continue;

            if (map[nr][nc] == 0) {
                q.push({nr,nc,nd.step + 1, nd.crash});
                visit[nr][nc] = nd.crash;
            } else if (nd.crash < R) {
                q.push({nr,nc,nd.step + 1, nd.crash + 1});
                visit[nr][nc] = nd.crash;
            }
        }
    }
}