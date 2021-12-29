#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
int** map;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int max_count = 0;

typedef struct {
    int x,y;
} nods;

void bfs();
void dfs(int cnt);

int main()
{
    scanf("%d %d",&N,&M);

    map = new int*[N];

    for (int i = 0; i < N; i++) {
        map[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d",&map[i][j]);
        }
    }

    dfs(0);

    printf("%d",max_count);

    return 0;
}

void dfs(int cnt) {
    if (cnt == 3) {
        bfs();
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                dfs(cnt+1);
                map[i][j] = 0;
            }
        }
    }
}

void bfs() {
    queue<nods> q;
    int** virus_map = new int*[N];

    for (int i = 0; i < N; i++) virus_map[i] = new int[M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            virus_map[i][j] = map[i][j];
        }
    }//for
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(virus_map[i][j] == 2) {
                q.push({i,j});
            }
        }
    }//for

    while(!q.empty()) {
        nods nd = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = nd.x + dx[i];
            int ny = nd.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && virus_map[nx][ny] == 0){
                virus_map[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }//while

    int count = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (virus_map[i][j] == 0) count++;
        }
    }

    max_count = max(max_count,count);

}