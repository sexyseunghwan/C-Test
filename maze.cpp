#include <iostream>
#include <queue>

using namespace std;

class Node{
    int x,y;
    public: 
    Node(int x,int y) {
        this->x = x;
        this->y = y;
    }
    int getX() {return x;}
    int getY() {return y;}
};


int main() {
    
    int N,M;
    scanf("%d %d",&N,&M);
    int maze[N][M];
    int visit[N][M];
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    char line[M+1]; 
    queue<Node> queue;

    for (int i = 0; i < N; i++) {
        scanf("%s",line);
        for (int j = 0; j < M; j++) {
            maze[i][j] = line[j] - '0';
        }
    }

    Node n(0,0);
    visit[0][0] = 1;
    queue.push(n);

    while(!queue.empty()) {
        Node node = queue.front();
        queue.pop();

        if (node.getX() == N-1 || node.getY() == M-1) {
            printf("%d",maze[N-1][M-1]);
        }


    }

    


    return 0;

}
