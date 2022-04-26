#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int matrix[52][52];
int flag_visit[52][52];
int N;
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};
int INF = INT_MAX;

void dijkstra() {
    
    for (int i = 0; i <= N*N; i++) {
        flag_visit[i/N][i%N] = INF;
    }
    
    priority_queue < pair< int, pair<int,int> > > pq;
    pq.push(make_pair(0,make_pair(0,0)));
    flag_visit[0][0] = 0;
    
    while(!pq.empty()) {
        int cur_w = -pq.top().first;
        int cur_r = pq.top().second.first;
        int cur_c = pq.top().second.second;
        
        pq.pop();

        if (flag_visit[cur_r][cur_c] < cur_w) continue;
        
        for (int i = 0; i < 4; i++) {
            int new_r = cur_r + dr[i];
            int new_c = cur_c + dc[i];
            
            if (new_r >= 0 && new_c >= 0 && new_r < N && new_c < N) {
                if (flag_visit[new_r][new_c] > cur_w + matrix[new_r][new_c]) {
                    flag_visit[new_r][new_c] = cur_w + matrix[new_r][new_c];
                    pq.push(make_pair(-flag_visit[new_r][new_c],make_pair(new_r,new_c)));
                }
            }
        }
    }
}

int main()
{
    cin >> N;
    
    for (int i = 0; i < N; i++ ) {
        char ch[N+1];
        cin >> ch;
        for (int j = 0; j < N; j++) {
            int input = ch[j] - '0';
            if (input == 1) matrix[i][j] = 0;
            else  matrix[i][j] = 1;
        }
    }
    
    dijkstra();
    
    cout << flag_visit[N-1][N-1];

    
    return 0;
}
