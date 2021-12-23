#include <iostream>
#include <queue>

using namespace std;
//위치속성 데이터를 넣어줄 구조체
typedef struct {
    int x,y;
} nods;

void bfs(int x,int y);

int N,M;//미로의 행렬 크기
int** maze;//미로배열
int** visit;//미로 방문 배열
queue<nods> q;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main()
{
    scanf("%d %d",&N,&M);

    maze = new int*[N];//미로 배열 초기화
    visit = new int*[N];//방문 배열 초기화

    for (int i = 0; i < N; i++) {
        maze[i] = new int[M];
        visit[i] = new int[M];
    }

    char line[M+1];//미로배열입력 받기 위한 문자열 

    for (int i = 0; i < N; i++) {
        scanf("%s",line);
        for (int j = 0; j < M; j++) {
            maze[i][j] = line[j] - '0';
        }
    }

    q.push({0,0});
    visit[0][0] = 1;

    while(!q.empty()) {
        nods nd = q.front();
        q.pop();

        if (nd.x == N-1 && nd.y == M-1) {
            printf("%d",visit[N-1][M-1]);
        }

        bfs(nd.x,nd.y);
    }
     
    return 0;
}

void bfs(int x,int y) {

    for (int i = 0; i < 4; i++) {
        int n_x = x + dx[i];
        int n_y = y + dy[i];
        
        if(n_x < 0 || n_y < 0 || n_x >= N || n_y >= M || maze[n_x][n_y] == 0 || visit[n_x][n_y] != 0) continue;

        visit[n_x][n_y] = visit[x][y] + 1;//전단계의 trace + 1
        q.push({n_x,n_y});
    }
}