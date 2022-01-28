#include <iostream>
#include <queue>

using namespace std;

int N,M,R;
int map[1001][1001];
bool visit[1001][1001][11];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int bfs(int r, int c);

typedef struct {
    int r,c,crash,step;
} nods;

int main()
{
    scanf("%d %d %d",&N,&M,&R);

    char str[M+1];

    for (int i = 0; i < N; i++) {
        scanf("%s",str);
        for (int j = 0; j < M; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    printf("%d",bfs(0,0));

    return 0;
}

int bfs(int r, int c) {
    queue<nods> q;
    q.push({r,c,0,1});
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

            if (nr < 0 || nc < 0 || nr >= N || nc >= M ) continue;

            if (map[nr][nc] == 0 && !visit[nr][nc][nd.crash]) {
                q.push({nr,nc,nd.crash,nd.step+1});
                visit[nr][nc][nd.crash] = true;
            } 
            if (map[nr][nc] == 1 && nd.crash < R && !visit[nr][nc][nd.crash+1]) {
                q.push({nr,nc,nd.crash+1,nd.step+1});
                visit[nr][nc][nd.crash+1] = true;
            }
        }
    }

    return -1;
    
}
