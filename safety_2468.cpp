#include <iostream>
#include <algorithm>

using namespace std;

int N;
int** matrix;
int** visit;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x,int y,int floor);

int main()
{

    scanf("%d",&N);
    matrix = new int*[N];
    visit = new int*[N];

    int max_number = -1;
    int min_number = 101;
    int max_count = 1;

    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
        visit[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            scanf("%d",&input);
            min_number = min(min_number,input);
            max_number = max(max_number,input);
            matrix[i][j] = input;
        }
    }

    for (int i = min_number; i <= max_number; i++) {
        int count = 0;
        for (int s = 0; s < N; s++) {
            for (int v = 0; v < N; v++) {
                visit[s][v] = 0;
            }
        }
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (matrix[j][k] > i && visit[j][k] == 0) {
                    dfs(j,k,i);
                    count++;
                }
            }
        }
        max_count = max(max_count,count);
    }
    
    
    printf("%d",max_count);

    return 0;
}

void dfs(int x,int y,int floor) {
    visit[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_y < 0 || new_x < 0 || new_y >= N || new_x >= N || matrix[new_x][new_y] <= floor || visit[new_x][new_y] == 1) continue;

        dfs(new_x,new_y,floor);
    }
}