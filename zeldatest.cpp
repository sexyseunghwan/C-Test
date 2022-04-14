#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int N;
int CASE = 1;
int INF = INT_MAX;
int map[126][126];
int check[126][126];
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

void clear() {
    for (int i = 0; i < N*N; i++) {
        check[i/N][i%N] = INF;
    }
}

void dijkstra() {
    priority_queue< pair<int , pair<int,int> > > pq;
    check[0][0] = map[0][0];
    pq.push(make_pair(-map[0][0],make_pair(0,0)));

    while(!pq.empty()) {
        int cur_d = -pq.top().first;
        int cur_r = pq.top().second.first;
        int cur_c = pq.top().second.second;

        pq.pop();

        for (int i = 0; i < 4; i++) {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];

            if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < N) {
                if (check[next_r][next_c] > cur_d + map[next_r][next_c]) {
                    check[next_r][next_c] = cur_d + map[next_r][next_c];
                    pq.push(make_pair(-check[next_r][next_c],make_pair(next_r,next_c)));
                }
            }            
        }
    }//while

    cout << "Problem " << CASE++ << ": " << check[N-1][N-1] << "\n";

}

int main() 
{
    while(1) {
        cin >> N;

        if (N == 0) break;
        
        clear();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        dijkstra();
    }


}
