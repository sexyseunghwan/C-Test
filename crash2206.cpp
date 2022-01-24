#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int N,M;
int** map;
int** visit;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int amp = INT_MAX;

void bfs(int r, int c);

typedef struct {
    int r,c,step,drill;
} nods;

int main() {

    scanf("%d %d",&N,&M);

    map = new int*[N];
    visit = new int*[N];

    for (int i = 0; i < N; i++) {
        map[i] = new int[M];
        visit[i] = new int[M];
    }

    char line[M+1];

    for (int i = 0; i < N; i++) {
        scanf("%s",line);
        for (int j = 0; j < M; j++) {
            map[i][j] = line[j] - '0';
            visit[i][j] = 2;
        }
    }

    bfs(0,0);

    if (amp == INT_MAX) printf("-1");
    else printf("%d",amp);

    return 0;
}

void bfs(int r, int c) {

    queue<nods> q;
    q.push({r,c,1,0});

    while(!q.empty()) {
        
        nods nd = q.front();
        q.pop();

        if (nd.r == N-1 && nd.c == M-1){
            amp = nd.step;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = nd.r + dr[i];
            int nc = nd.c + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M || visit[nr][nc] <= nd.drill) continue; 

            if (map[nr][nc] == 0) {
                visit[nr][nc] = nd.drill;
                q.push({nr,nc,nd.step+1,nd.drill});
            } else if (nd.drill == 0) {
                visit[nr][nc] = nd.drill + 1;
                q.push({nr,nc,nd.step+1,nd.drill+1});
            }
        }
    }
}