#include <iostream>
#include <queue>

using namespace std;

int N,M;
int map[1001][1001];
int visit[1001][1001];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

typedef struct {
    int r,c,day;
} node;

queue<node> q;

int bfs();

int main()
{
    scanf("%d %d",&N,&M);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            scanf("%d",&num);
            map[i][j] = num;
            if (num == 1) {
                node n = {i,j,0};
                q.push(n);
            }
        }
    }

    printf("%d",bfs());

    return 0;
}

int bfs() {

    while(!q.empty()) {
        node nd = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = nd.r + dr[i];
            int nc = nd.c + dc[i];

            if (nr < 0 | nc < 0 || nr >= M || nc >= N) continue;

            if (map[nr][nc] == 0) {
                node nnd = {nr,nc,nd.day + 1};
                q.push(nnd);
                map[nr][nc] = 1;
                visit[nr][nc] = nd.day + 1;
            }
        }
    }

    int max_day = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if(map[i][j] == 0) {
                return -1;
            }  
            max_day = visit[i][j] > max_day ? visit[i][j] : max_day;
        }
    }
    return max_day;

}