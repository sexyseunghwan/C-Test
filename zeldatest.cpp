#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int N;
int Problem = 1;
int INF = INT_MAX;
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};
int map[126][126];
int visited[126][126];


void clean() {
    for (int i = 0; i < N*N; i++) {
        visited[i/N][i%N] = INF;
    }
}

void dijkstra() {
    priority_queue< pair< int,pair<int,int> > > pq;
    pq.push(make_pair(-map[0][0],make_pair(0,0)));
    visited[0][0] = map[0][0];

    while(!pq.empty()) {
        int cur_w = -pq.top().first;
        int cur_r = pq.top().second.first;
        int cur_c = pq.top().second.second;

        pq.pop();

        for (int i = 0; i < 4; i++) {
            int new_r = cur_r + dr[i];
            int new_c = cur_c + dc[i];

            if (new_r >= 0 && new_c >= 0 && new_r < N && new_c < N) {
                if (visited[new_r][new_c] > cur_w + map[new_r][new_c]) {
                    visited[new_r][new_c] = cur_w + map[new_r][new_c];
                    pq.push(make_pair(-visited[new_r][new_c],make_pair(new_r,new_c)));
                }
            }
        }
    }

}

int main() 
{

    while(1) {
        cin >> N;

        if (N == 0) break;

        clean();

        for (int i = 0; i < N*N; i++) {
            cin >> map[i/N][i%N];
        }

        dijkstra();
        
        cout << "Problem " << Problem++ << ": " << visited[N-1][N-1] << "\n";

    }
    


    return 0;
}
