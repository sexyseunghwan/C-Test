#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 987654321;
int N,E;
vector < pair<int,int> > map[802];
int result_dist[802];
int stov1, stov2, v1tov2, v1ton, v2ton;

void dijkstra(int start) {
    
    for (int i = 0; i <= N; i++) {
        result_dist[i] = INF;
    }
    
    priority_queue < pair<int,int> > pq;
    pq.push(make_pair(0,start));
    result_dist[start] = 0;

    while(!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_d = -pq.top().first;

        pq.pop();
        
        if (result_dist[cur_v] < cur_d) continue;

        for (int i = 0; i < map[cur_v].size(); i++) {
            int next_v = map[cur_v][i].first;
            int next_d = map[cur_v][i].second;
            
            if (result_dist[next_v] > next_d + cur_d) {
                result_dist[next_v] = next_d + cur_d;
                pq.push(make_pair(-result_dist[next_v],next_v));
            }
        }
    }
}

int main()
{
    cin >> N >> E;
    
    for (int i = 0; i < E; i++) {
        int s,e,d;

        cin >> s >> e >> d;

        map[s].push_back(make_pair(e,d));
        map[e].push_back(make_pair(s,d));
    }

    int v1,v2;

    cin >> v1 >> v2;

    int res = INF;

    dijkstra(1);
    stov1 = result_dist[v1];
    stov2 = result_dist[v2];
    
    dijkstra(v1);
    v1tov2 = result_dist[v2];
    v1ton = result_dist[N];

    dijkstra(v2);
    v2ton = result_dist[N];

    res = min(res,stov1+v1tov2+v2ton);
    res = min(res,stov2+v1tov2+v1ton);
    
    if (v1tov2 == INF || res == INF) cout << -1;
    else cout << res;
    
    return 0;
}