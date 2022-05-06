#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int T,N,M,K;
int INF = INT_MAX;
vector < pair < pair<int,int>,int > > map[102];
int dist_res[102][10002];

int dijkstra() {

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dist_res[i][j] = INF;
        }
    }

    priority_queue< pair< pair<int,int>,int > > pq;
    pq.push(make_pair(make_pair(0,0),1));
    dist_res[1][0] = 0;

    while(!pq.empty()) {
        int cur_u = pq.top().second;
        int cur_d = -pq.top().first.first;
        int cur_c = -pq.top().first.second;

        for (int i = 0; i < map[cur_u].size(); i++) {
            int next_u = map[cur_u][i].second;
            int next_d = map[cur_u][i].first.first + cur_d;
            int next_c = map[cur_u][i].first.second + cur_c;
            
            if (next_c > M) continue;
            else if (dist_res[next_u][next_c] > next_d) {
                //for (int i = )
            }

        }
    }

    return 0;
}


int main()
{

    cin >> T;

    while(T--) {
        
        cin >> N >> M >> K;

        for (int i = 0; i <= N; i++) {
            map[i].clear();
        }

        for (int i = 0; i < K; i++) {
            int u,v,c,d;

            cin >> u >> v >> c >> d;

            map[u].push_back(make_pair(make_pair(d,c),v));
        }

        int result = dijkstra();

    }

    
    
    


    return 0;
}