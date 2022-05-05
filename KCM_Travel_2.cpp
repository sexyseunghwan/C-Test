#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int T,N,M,K;
int INF = INT_MAX;
int desti_arr[102][10002];
vector < pair<pair<int,int> , int > > map[102];

void dijkstra() {

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            desti_arr[i][j] = INF;
        }
    }

    priority_queue < pair< pair<int,int>, int > > pq;
    pq.push(make_pair(make_pair(0,0),1));
    desti_arr[1][0] = 0;

     while(!pq.empty()) {
        int cur_u = pq.top().second;
        int cur_d = -pq.top().first.first;
        int cur_c = -pq.top().first.second;
        
        pq.pop();

        if (desti_arr[cur_u][cur_c] < cur_d) continue;

        for (int i = 0; i < map[cur_u].size(); i++) {
            int next_v = map[cur_u][i].second;
            int next_c = map[cur_u][i].first.second + cur_c;
            int next_d = map[cur_u][i].first.first + cur_d;

            if (next_c > M) continue;

            if (desti_arr[next_v][next_c] <= next_d) continue;

            desti_arr[next_v][next_c] = next_d;
            pq.push(make_pair(make_pair(-desti_arr[next_v][next_c],-next_c),next_v));  
        }
    }
}





int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

        dijkstra();
        
        int result = INT_MAX;

        for (int i = 0; i <= M; i++) {
            result = min(result,desti_arr[N][i]);    
        }

        if (result == INF) cout << "Poor KCM" << "\n";
        else cout << result << "\n";
    }
    return 0;
}