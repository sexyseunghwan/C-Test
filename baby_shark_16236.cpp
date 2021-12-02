#include <iostream>
#include <queue>
#define max_val 401

using namespace std;

int N;
int** matrix;
int** check;
int shark_x,shark_y,eat_cnt;
int min_dist,min_x,min_y,result;
int shark_size = 2;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

class Node {
    public:
        int x,y;
    Node(int x,int y) {
        this->x=x;
        this->y=y;
    }
    int get_x() {
        return x;
    }
    int get_y() {
        return y;
    }
};

void bfs(int x,int y);
void init();

int main()
{
    scanf("%d",&N);

    matrix = new int*[N];
    check = new int*[N];

    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
        check[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int in_num;
            scanf("%d",&in_num);

            if (in_num == 9) {
                shark_x = i;
                shark_y = j;
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = in_num;
            }
        }
    }//for


    while(true) {

        init();
        bfs(shark_x,shark_y);
        
        if (min_x != N && min_y != N) {
            
            result += min_dist;

            eat_cnt++;

            if (eat_cnt == shark_size) {
                shark_size++;
                eat_cnt = 0;
            }

            matrix[min_x][min_y] = 0;

            shark_x = min_x;
            shark_y = min_y;

        } else {
            break;
        }
    }
    

    printf("%d",result);
}

void init() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            check[i][j] = -1;
        }
    }

    min_x = N;
    min_y = N;
    min_dist = max_val; 

}

void bfs(int x,int y) {
    queue<Node> que;
    Node node(x,y);
    que.push(node);

    check[x][y] = 0;

    while(!que.empty()) {
        Node nodes = que.front();
        que.pop();
        int x = nodes.get_x();
        int y = nodes.get_y();

        for (int i = 0; i < 4; i++) {
            int n_x = x + dx[i];
            int n_y = y + dy[i];

            if (n_y < 0 || n_x < 0 || n_y >= N || n_x >= N ) continue; 
            if (check[n_x][n_y] != -1 || matrix[n_x][n_y] > shark_size) continue;

            check[n_x][n_y] = check[x][y] + 1;

            if (matrix[n_x][n_y] != 0 && matrix[n_x][n_y] < shark_size) {
                if (min_dist > check[n_x][n_y]) {
                    min_dist = check[n_x][n_y];
                    min_x = n_x;
                    min_y = n_y;
                } else if (min_dist == check[n_x][n_y]) {
                    if (min_x == n_x) {
                        if (min_y > n_y) {
                            min_x = n_x;
                            min_y = n_y;
                        }
                    } else if (min_x > n_x) {
                        min_x = n_x;
                        min_y = n_y;
                    }
                }
            }

            Node nod(n_x,n_y);
            que.push(nod);
        }//for
    }

}
