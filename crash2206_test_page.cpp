#include <iostream>
#include <queue>

using namespace std;

int N,M;
int** map;
bool visit[1001][1001][3];
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

int bfs();
typedef struct {
    int r,c,step,crush;
} nods;

int main() 
{   

    scanf("%d %d",&N,&M);

    map = new int*[N];
    for (int i = 0; i < N; i++) map[i] = new int[M];

    char line[M+1];
    for (int i = 0; i < N; i++) {
        scanf("%s",line);
        for (int j = 0; j < M; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    printf("%d",bfs());

}

int bfs() {
    queue<nods> q;
    nods nn = {0,0,1,0};
    q.push(nn);
    visit[0][0][0] = true;

    while(!q.empty()) {
        nods nd = q.front();
        q.pop();

        if (nd.r == N-1 && nd.c == M-1) {
            return nd.step;
        }

        for (int i = 0; i < 4; i++) {
            int nr = nd.r + dr[i];
            int nc = nd.c + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;

            if (map[nr][nc] == 0 && !visit[nr][nc][nd.crush]) {
                nods ns = {nr,nc,nd.step+1,nd.crush};
                q.push(ns);
                visit[nr][nc][nd.crush] = true;
            } 
            if (map[nr][nc] == 1 && nd.crush < 1 && !visit[nr][nc][nd.crush+1]) {
                nods ns = {nr,nc,nd.step+1,nd.crush+1};
                q.push(ns);
                visit[nr][nc][nd.crush+1] = true;
            }
        }
    }

    return -1;

}