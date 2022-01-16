#include <iostream>
#include <algorithm>

using namespace std;

int ** map;
int c_count = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int v_index = 0;

void start(int x,int y,int p, int fb);
int left_rotate(int p);
void go_back(int p);

int main()
{
    int N,M;
    scanf("%d %d", &N, &M);
    
    map = new int*[N];
    for (int i = 0; i < N; i++) map[i] = new int[M];

    int r_x,r_y,r_p;

    scanf("%d %d %d",&r_x,&r_y,&r_p);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d",&map[i][j]);
        }
    }

    start(r_x,r_y,r_p,0);

    printf("%d",c_count);
}

void start(int x,int y,int p, int fb) {

    if (fb == 0) {
        map[x][y] = 2;
        c_count++;
    }
    
    for (int i = 0; i < 4; i++) {
        p = left_rotate(p);

        int n_x = x + dx[v_index];
        int n_y = y + dy[v_index];

        if (map[n_x][n_y] == 0) {
            start(n_x,n_y,p,0);
            return;
        }
    }

    go_back(p);

    int b_x = x + dx[v_index];
    int b_y = y + dy[v_index];

    if (map[b_x][b_y] != 1) {
        start(b_x,b_y,p,1);
    } else return;
    

}

int left_rotate(int p) {
    //p = 0 -> x : 0 ,y : -1 => 2, 3
    //p = 1 -> x : -1, y : 0 => 3, 0
    //p = 2 -> x : 0, y : 1 => 0, 1
    //p = 3 -> x : 1, y : 0 => 1, 2
    v_index = (p+2) % 4;
    return (p+3) % 4;
}

void go_back(int p) {
    //p = 0 -> x : 1, y : 0 => 1
    //p = 1 -> x : 0, y : -1 => 2
    //p = 2 -> x : -1, y : 0 => 3
    //p = 3 -> x : 0, y : 1 => 0
    v_index = (p+1) % 4;
}
