#include <iostream>
#include <algorithm>

using namespace std;

int ** map;
int c_count = 0;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
int v_index = 0;

void clear_start(int rr,int rc, int rd, int byn);
int left_rotate(int rd);
void back_rotate(int rd);

int main()
{   
    int N,M;
    scanf("%d %d",&N,&M);

    map = new int*[N];
    for (int i = 0; i < N; i++) map[i] = new int[M];

    int rr,rc,rd;
    scanf("%d %d %d",&rr,&rc,&rd);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d",&map[i][j]);
        }
    }

    clear_start(rr,rc,rd,1);

    printf("%d",c_count);

    return 0;
}

void clear_start(int rr,int rc, int rd, int byn) {
    
    if (byn == 1) {
        map[rr][rc] = 2;
        c_count++;
    }

    for (int i = 0; i < 4; i++) {
        rd = left_rotate(rd);

        int nr = rr + dr[v_index];
        int nc = rc + dc[v_index];

        if (map[nr][nc] == 0) {
            clear_start(nr,nc,rd,1);
            return;
        }
    }

    back_rotate(rd);

    int nr = rr + dr[v_index];
    int nc = rc + dc[v_index];

    if (map[nr][nc] != 1) clear_start(nr,nc,rd,0);
    else return;
    
}

int left_rotate(int rd) {
    v_index = (rd + 2) % 4;
    return (rd + 3) % 4;
}

void back_rotate(int rd) {
    v_index = (rd + 1) % 4;
}