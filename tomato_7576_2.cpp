#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int r,c,day;
} node;

int map[1001][1001];
int visit[1001][1001];
queue<node> q;
int N,M;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int bfs();

int main()
{
    scanf("%d %d",&M,&N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            scanf("%d",&num);

            if (num == 1) {
                q.push({i,j,0});
            }
            map[i][j] = num;
        }
    }

    int result = bfs();

    printf("%d",result);

    return 0;
}

int bfs() {
    
    while(!q.empty()) {
        node nd = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = nd.r + dr[i];
            int nc = nd.c + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;

            if (map[nr][nc] == 0 && visit[nr][nc] == 0) {
                q.push({nr,nc,nd.day + 1});
                visit[nr][nc] = nd.day + 1;
                map[nr][nc] = 1;
            }
        }
    }

    int max_day = 0;

    for (int i = 0; i < N*M; i++) {
        if (map[i/M][i%M] == 0) return -1;
        else max_day = visit[i/M][i%M] > max_day ? visit[i/M][i%M] : max_day;
    }

    return max_day;
}

