#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int N,M;
int INF = INT_MAX;
int map[102][102];
int vist[102][102];
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

void dijkstra() {
    priority_queue < pair< int,pair<int,int> > > pq;
    pq.push(make_pair(0,make_pair(0,0)));
    vist[0][0] = 0;

    while(!pq.empty()) {
        int cur_crash = -pq.top().first;
        int cur_r = pq.top().second.first;
        int cur_c = pq.top().second.second;

        pq.pop();

        for (int i = 0; i < 4; i++) {
            int new_r = dr[i] + cur_r;
            int new_c = dc[i] + cur_c;

            if (new_r >= 0 && new_c >= 0 && new_r < M && new_c < N) {
                if (vist[new_r][new_c] > cur_crash + map[new_r][new_c]) {
                    vist[new_r][new_c] = cur_crash + map[new_r][new_c];
                    pq.push(make_pair(-vist[new_r][new_c],make_pair(new_r,new_c)));
                }
            }
        }
    }
}

int main()
{
        
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        char ch[102];
        cin >> ch;
        for (int j = 0; j < N; j++) {
            map[i][j] = ch[j]-'0';
            vist[i][j] = INF;
        }
    }
    
    dijkstra();

    cout << vist[M-1][N-1];

    return 0;
}