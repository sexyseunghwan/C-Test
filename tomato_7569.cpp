#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int h,r,c,day;
} node;

int map[101][101][101];
int visit[101][101][101];
queue<node> q;
int H,N,M;
int dh[6] = {1,-1,0,0,0,0};
int dr[6] = {0,0,1,-1,0,0};
int dc[6] = {0,0,0,0,1,-1};
int bfs();

int main()
{
    scanf("%d %d %d",&M,&N,&H);
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int num;
                scanf("%d",&num);

                if (num == 1) {
                    node nd = {i,j,k,0}; 
                    q.push(nd);
                }
                map[i][j][k] = num;
            }
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

        for (int i = 0; i < 6; i++) {
            int nh = nd.h + dh[i];
            int nr = nd.r + dr[i];
            int nc = nd.c + dc[i];

            if (nh < 0 || nr < 0 || nc < 0 || nh >= H || nr >= N || nc >= M) continue;

            if (map[nh][nr][nc] == 0 && visit[nh][nr][nc] == 0) {
                node nds = {nh,nr,nc,nd.day + 1};
                q.push(nds);
                map[nh][nr][nc] = 1;
                visit[nh][nr][nc] = nd.day + 1;
            }
        }
    }

    int max_day = 0;
    int index = M*N;

    for (int i = 0; i < H*N*M; i++) {
        int page_index = i / index;
        int rest_index = i % index;
        
        if(map[page_index][rest_index/M][rest_index%M] == 0) return -1;

        int visit_value = visit[page_index][rest_index/M][rest_index%M];

        max_day = max_day > visit_value ? max_day : visit_value;

    }

    return max_day;
}

