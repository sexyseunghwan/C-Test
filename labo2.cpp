#include <iostream>
#include <queue>

using namespace std;
//위치속성 데이터를 넣어줄 구조체
typedef struct {
    int x,y;
} nods;

void dfs(int cnt);
void bfs();

int N,M;
int** map;
int max_count = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main()
{
    scanf("%d %d",&N,&M);

    map = new int*[N];

    for (int i = 0; i < N; i++) map[i] = new int[M];

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

void bfs(){
    int** v_map = new int*[N];
    queue<nods> q;
    
    for (int i = 0; i < N; i++) v_map[i] = new int[M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            v_map[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v_map[i][j] == 2) q.push({i,j});        
        }
    }

    while(!q.empty()) {
        nods nd = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = nd.x + dx[i];
            int ny = nd.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && v_map[nx][ny] == 0) {
                v_map[nx][ny] = 2;
                q.push({nx,ny});
            }
        }//for
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v_map[i][j] == 0) count++;       
        }
    }
    
    max_count = max(count,max_count);
    
}