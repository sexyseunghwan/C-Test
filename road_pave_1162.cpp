#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

ll INF = 1e15;
int N,M,K;
ll val_matrix[10002][22];
vector < pair<int,int> > map[10002];

void dijkstra() {
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            val_matrix[i][j] = INF;
        }
    }
    
    priority_queue< pair< ll,pair<int,int> > > pq;
    pq.push(make_pair(0,make_pair(0,1)));
    val_matrix[1][0] = 0;

    while(!pq.empty()) {
        int cur_cnt = pq.top().second.first;
        int cur_u = pq.top().second.second;
        ll cur_d = -pq.top().first;

        pq.pop();

        if (val_matrix[cur_u][cur_cnt] < cur_d) continue;
        
        for (int i = 0; i < map[cur_u].size(); i++) {
            int next_u = map[cur_u][i].first;
            ll next_d = map[cur_u][i].second + cur_d;

            if (val_matrix[next_u][cur_cnt] > next_d) {
                val_matrix[next_u][cur_cnt] = next_d;
                pq.push(make_pair(-next_d,make_pair(cur_cnt,next_u)));
            }

            if (val_matrix[next_u][cur_cnt + 1] > cur_d && cur_cnt + 1 <= K) {
                val_matrix[next_u][cur_cnt + 1] = cur_d;
                pq.push(make_pair(-cur_d,make_pair(cur_cnt+1,next_u)));
            }
        }   
    }
}
    

int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> K;
    
    for (int i = 0; i < M; i++) {
        int u,v,d;
        
        cin >> u >> v >> d;
        
        map[u].push_back(make_pair(v,d));
        map[v].push_back(make_pair(u,d));
    }
    
    dijkstra();
    
    ll min_val = INF;

    for (int i = 0; i <= K; i++) {
        min_val = min_val > val_matrix[N][i] ? val_matrix[N][i] : min_val;
    }

    cout << min_val;

    return 0;
}


