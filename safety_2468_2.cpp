#include <iostream>
#include <algorithm>

using namespace std;

int N;
int** matrix;
int** visit;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x,int y,int min_val);

int main()
{

    scanf("%d",&N);

    int min_num = 101;//최소값
    int max_num = 0;//최대값
    int max_count = 1;//영역의 최대값

    matrix = new int*[N];//포인터 배열 선언
    visit = new int*[N];//방문 포인터 배열 선언

    //포인터 배열, 방문 포인터 배열 초기화
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
        visit[i] = new int[N]; 
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {   
            int num;
            scanf("%d",&num);

            min_num = min(num,min_num);
            max_num = max(num,max_num);

            matrix[i][j] = num;
        }
    }

    //주어진 배열에서 가장 물이 얕을때 부터 가장 깊을 때까지 루프문으로 돌면서 비교
    for (int s = min_num; s <= max_num; s++) {

        //방문배열 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visit[i][j] = 0;
            }
        }
        
        int count = 0;//영역 갯수 카운트

        //배열을 모두 돌면서 dfs 알고리즘 적용
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] > s && visit[i][j] == 0) {
                    dfs(i,j,s);
                    count++;
                }                
            }
        }

        //현재 합계와 이전 최고 합계와 비교후에 가장 큰 수를 집계
        max_count = max(count,max_count);
    }

    printf("%d",max_count);


    return 0;
}

//dfs 알고리즘
void dfs(int x,int y,int min_val) {
    visit[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int n_x = x + dx[i];
        int n_y = y + dy[i];

        if (n_y < 0 || n_x < 0 || n_y >= N || n_x >= N || matrix[n_x][n_y] <= min_val || visit[n_x][n_y] == 1) continue;

        dfs(n_x,n_y,min_val);
    }
    
}