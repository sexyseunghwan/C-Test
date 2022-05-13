#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int INF = 1100000;
int N,M,K;
int val_matrix[10002][22];
vector < pair<int,int> > map[10002];

void dijkstra() {
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            val_matrix[i][j] = INF;
        }
    }
    
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(0,1));
    val_matrix[1][0] = 0;
    
    while(!pq.empty()) {
        int cur_u = pq.top().second;
        int cur_d = -pq.top().first;
        
        pq.pop();
        
        for (int i = 0; i < map[cur_u].size(); i++) {
            int next_u = map[cur_u][i].first;
            int next_d = map[cur_u][i].second + cur_d;
            
            pq.pop();

            if (val_matrix[next_u][0] > next_d) val_matrix[next_u][0] = next_d;

            for (int i = 1; i <= K; i++) {
                int prev_d = val_matrix[cur_u][i-1];
                if (val_matrix[next_u][i] > prev_d) {
                    val_matrix[next_u][i] = prev_d;
                    pq.push(make_pair(-prev_d,next_u));
                }
            }
        }
    }
    
}

int main()
{
    
    cin >> N >> M >> K;
    
    for (int i = 0; i < M; i++) {
        int u,v,d;
        
        cin >> u >> v >> d;
        
        map[u].push_back(make_pair(v,d));
        map[v].push_back(make_pair(u,d));
    }
    
    dijkstra();
    
    int min_val = INF;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            cout << val_matrix[i][j] << " ";
        }
        cout << "\n";
    }


    // for (int i = 0; i <= N; i++) {
    //     min_val = min(min_val,val_matrix[N][i]);
    // }

    //cout << min_val;

    return 0;
}


