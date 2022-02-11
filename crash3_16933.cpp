#include <iostream>
#include <queue>

using namespace std;

int N,M,C;
int map[1001][1001];
bool visit[1001][1001][11];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

typedef struct {
    int r,c,step,crash,day_yn;
} nods;

int bfs();

int main()
{
    scanf("%d %d %d",&N,&M,&C);
    
    char line[M+1];
    
    for (int i = 0; i < N; i++) {
        scanf("%s",line);
        for (int j= 0 ;j < M; j++) {
            map[i][j] = line[j] - '0';
        }
    }
    
    printf("%d",bfs());
    
    return 0;
}

int bfs() {
    queue<nods> q;
    nods nod = {0,0,1,0,1};
    q.push(nod);
    visit[0][0][0] = true;
    
    while(!q.empty()) {
        nods nd = q.front();
        q.pop();
        
        if (nd.r == N-1 && nd.c == M-1) return nd.step;
        
        for (int i = 0; i < 4; i++) {
            int nr = nd.r + dr[i];
            int nc = nd.c + dc[i];
            
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            
            if (map[nr][nc] == 0 && !visit[nr][nc][nd.crash]) {
                nods ns = {nr,nc,nd.step+1,nd.crash, -1 *nd.day_yn};
                q.push(ns);
                visit[nr][nc][nd.crash] = true;
            }
            
            if (map[nr][nc] == 1 && nd.crash < C &&!visit[nr][nc][nd.crash+1]) {
                if (nd.day_yn == 1) {
                    nods ns = {nr,nc,nd.step+1,nd.crash+1, -1 *nd.day_yn};
                    visit[nr][nc][nd.crash+1] = true;
                    q.push(ns);   
                } else {
                    nods ns = {nd.r,nd.c,nd.step+1,nd.crash, -1 *nd.day_yn};
                    q.push(ns);
                }
            }
        }
    }
    return -1;
}