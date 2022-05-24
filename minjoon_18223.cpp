#include <iostream>
#include <queue>
#include <vector>
#include <climits>

typedef long long ll;

using namespace std;

int V,E,P;
vector < pair<int,int> > map[5002];
int INF = INT_MAX;
int min_roots[5002];

int dijkstra(int stp,int endp) {
    
    for (int i = 0; i <= V; i++) {
        min_roots[i] = INF;
    }
    
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(0,stp));
    min_roots[stp] = 0;
    
    while(!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_d = -pq.top().first;

        pq.pop();
        
        if (min_roots[cur_v] < cur_d) continue;
        
        for (int i = 0; i < map[cur_v].size(); i++) {
            int next_v = map[cur_v][i].first;
            int next_d = map[cur_v][i].second + cur_d;
    
            if (min_roots[next_v] > next_d) {
                min_roots[next_v] = next_d;
                pq.push(make_pair(-next_d,next_v));
            }
        }
    }
    
    return min_roots[endp];
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
    
    int min_root = dijkstra(1,V);
    int f_root_f = dijkstra(1,P);
    int f_root_s = dijkstra(P,V);
    
    if (min_root < f_root_f + f_root_s) cout << "GOOD BYE";
    else cout << "SAVE HIM";
    
    
    return 0;
}


