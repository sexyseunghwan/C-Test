#include <iostream>
#include <queue>

using namespace std;

int N,M,R;
int map[1001][1001];
bool visit[1001][1001][11];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int bfs();

typedef struct {
    int r,c,step,crash;
} nods;

int main() 
{
    scanf("%d %d %d",&N,&M,&R);

    char line[M+1];

    for (int i = 0; i < N; i++) {
        scanf("%s",line);
        for (int j = 0; j < M; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    printf("%d",bfs());

    return 0;
}

int bfs() {
    queue<nods> q;
    nods ns = {0,0,1,0};
    q.push(ns);

    while(!q.empty()) {
        nods nd = q.front();
        q.pop();

        if (nd.r == N-1 && nd.c == M-1) return nd.step;

        for (int i = 0; i < 4; i++) {
            int nr = nd.r + dr[i];
            int nc = nd.c + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;

            if (map[nr][nc] == 0 && !visit[nr][nc][nd.crash]) {
                nods n = {nr,nc,nd.step+1,nd.crash};
                q.push(n);
                visit[nr][nc][nd.crash] = true;
            }

            if (map[nr][nc] == 1 && nd.crash < R && !visit[nr][nc][nd.crash+1]) {
                nods n = {nr,nc,nd.step+1,nd.crash+1};
                q.push(n);
                visit[nr][nc][nd.crash + 1] = true;
            }
        }
    }
    return -1;
}