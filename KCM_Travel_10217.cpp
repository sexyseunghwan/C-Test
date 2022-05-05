#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int T,N,M,K;
int INF = INT_MAX;
int desti_arr[102];
int cost_arr[102];
vector < pair<int, pair<int,int> > > map[102];

void dijkstra() {

    for (int i = 0; i <= N; i++) {
        desti_arr[i] = INF;
        cost_arr[i] = INF;
    }
    
    priority_queue < pair<int,pair<int,int> > > pq;
    pq.push(make_pair(0,make_pair(1,0)));
    desti_arr[1] = 0;
    cost_arr[1] = 0;

    while(!pq.empty()) {
        int cur_u = pq.top().second.first;
        int cur_d = -pq.top().first;
        int cur_c = pq.top().second.second;

        pq.pop();

        for (int i = 0; i < map[cur_u].size(); i++) {
            int next_v = map[cur_u][i].second.first;
            int next_c = map[cur_u][i].second.second;
            int next_d = map[cur_u][i].first;

            if (desti_arr[next_v] > cur_d + next_d && (cur_c + next_c) <= M) {
                
                if (cost_arr[next_v] > cur_c + next_c) {
                    cost_arr[next_v] = cur_c + next_c;
                    desti_arr[next_v] = cur_d + next_d;
                    pq.push(make_pair(-desti_arr[next_v],make_pair(next_v,cur_c + next_c)));    
                }
            }
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

            map[u].push_back(make_pair(d,make_pair(v,c)));
        }

        dijkstra();

        if (desti_arr[N] == INF) cout << "Poor KCM" << "\n";
        else cout << desti_arr[N] << "\n";
        cout << cost_arr[N];
    }
    return 0;
}