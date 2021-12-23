#include <iostream>
using namespace std;

int** land;
int** visit;
int N,M;
int dx[8] = {0,0,1,-1,1,-1,-1,1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

void dfs(int x,int y);

int main()
{

    while(scanf("%d %d",&M,&N) == 2 && !(N == 0 && M == 0) ) {

        land = new int*[N];
        visit = new int*[N];
        int area_count = 0;

        for (int i = 0; i < N; i++) {
            land[i] = new int[M];
            visit[i] = new int[M];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d",&land[i][j]);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (land[i][j] == 1 && visit[i][j] == 0) {
                    dfs(i,j);
                    area_count++;
                }
            }
        }

        printf("%d\n",area_count);
    }

    return 0;
}

void dfs(int x,int y) {
    visit[x][y] = 1;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M || land[nx][ny] == 0 || visit[nx][ny] == 1) continue;

        dfs(nx,ny);
    }

}
