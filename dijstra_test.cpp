#include <iostream>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;
    
int a[6][6] = {
    {0,2,5,1,INF,INF},
    {2,0,3,2,INF,INF},
    {5,3,0,3,1,5},
    {1,2,3,0,1,INF},
    {INF,INF,1,1,0,2},
    {INF,INF,5,INF,2,0}
};

bool v[6]; // 방문한 노드
int d[6]; // 거리

int get_small_index(){
    int min = INF;
    int index = 0;
    for (int i = 0; i < number; i++) {
        if (!v[i] && d[i] < min) {
            min = d[i];
            index = i;
        }
    }
    return index;
}

//선형탐색을 이용하는 방법
void dijkstra(int start) {
    for (int i = 0; i < number; i++) {
        d[i] = a[start][i];
    }
    
    v[start] = true;

    for (int i = 0; i < number - 2; i++) {
        int current = get_small_index();
        v[current] = true;

        for (int j = 0; j < number; j++) {
            if (!v[j] && d[j] > a[current][j] + d[current]) {
                d[j] = a[current][j] + d[current];
            }
        }
    }

}

int main()
{

    dijkstra(0);

    for (int i = 0; i < number; i++) {
        printf("%d ",d[i]);
    }



    return 0;
}

