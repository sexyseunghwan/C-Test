#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int V,E,P;
vector < pair<int,int> > map[5002];
int INF = INT_MAX;
int val_matrix[5002][2];

void dijkstra() {
    
    for (int i = 0; i <= V; i++) {
        for (int j = 0; j < 2; j++) {
            val_matrix[i][j] = INF;
        }
    }
    
    priority_queue< pair< int, pair<int,int> > > pq;
    pq.push(make_pair(0,make_pair(1,0)));
    val_matrix[1][0] = 0;
    
    while(!pq.empty()) {
        int cur_v = pq.top().second.first;
        int cur_d = -pq.top().first;
        int cur_p = pq.top().second.second;
        
        pq.pop();
        
        if (val_matrix[cur_v][cur_p] < cur_d) continue;
        
        for (int i = 0; i < map[cur_v].size(); i++) {
            int next_v = map[cur_v][i].first;
            int next_d = map[cur_v][i].second + cur_d;
            int next_p = cur_p;
            
            if (next_v == P) next_p = 1;
            if (val_matrix[next_v][next_p] > next_d) {
                val_matrix[next_v][next_p] = next_d;
                pq.push(make_pair(-next_d,make_pair(next_v,next_p)));
            }
        }
    }
}

int main()
{
    
    cin >> V >> E >> P;
    
    for (int i = 0; i < E; i++) {
        int u,v,d;
        
        cin >> u >> v >> d;
        
        map[u].push_back(make_pair(v,d));
        map[v].push_back(make_pair(u,d));
    }
    
    dijkstra();
    
    if (val_matrix[V][0] < val_matrix[V][1]) cout << "GOOD BYE";
    else cout << "SAVE HIM";
    
    
    return 0;
}



