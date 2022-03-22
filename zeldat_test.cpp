#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int INF = INT_MAX;
int vertex[126][126];
int distances[126][126];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,-1,1};
int COUNT = 1;
int N;

void clean() {
    for (int i = 0; i < N*N; i++) {
        distances[i/N][i%N] = INF;
        vertex[i/N][i%N] = 0;
    }
}

void dijkstra() {
    priority_queue < pair< int,pair<int,int> > > pq;
    distances[0][0] = vertex[0][0];
    pq.push(make_pair(-vertex[0][0],make_pair(0,0)));

    while(!pq.empty()) {
        int cur_d = -pq.top().first;
        int cur_r = pq.top().second.first;
        int cur_c = pq.top().second.second;
        
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int next_r = dr[i] + cur_r;
            int next_c = dc[i] + cur_c;

            if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < N) {
                if (distances[next_r][next_c] > cur_d + vertex[next_r][next_c]) {
                    distances[next_r][next_c] = cur_d + vertex[next_r][next_c];
                    pq.push(make_pair(-distances[next_r][next_c],make_pair(next_r,next_c)));
                }
            }

        }
    }//while
}

int main()
{

    while(1) {
        cin >> N;

        if (N == 0) break;
        
        clean();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> vertex[i][j];
            }
        }

        dijkstra();

        cout << "Problem " << COUNT++ << ": " << distances[N-1][N-1] << "\n";
    }

}