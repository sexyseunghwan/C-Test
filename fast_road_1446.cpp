#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int INF = INT_MAX;
int N,D;
int fast_road[10002];
vector < pair<int,int> > map[10002];

void dijkstra() {

    for (int i = 0; i < D; i++) {
        fast_road[i] = INF;
    }
    
    fast_road[D] = D;

    int prev = -1;

    for (int i = 0; i <= D; i++) {
        
        if (i) prev = fast_road[i-1];
        fast_road[i] = min(fast_road[i],prev + 1);

        for (int j = 0; j < map[i].size(); j++) {
            int s_v = map[i][j].first;
            int s_d = map[i][j].second;
            
            if (fast_road[s_v] > fast_road[i] + s_d) {
                fast_road[s_v] = fast_road[i] + s_d;
            }
        }
    }
}

int main()
{

    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        int u,v,w;

        cin >> u >> v >> w;

        if ( v - u <= w) continue;
        if ( v > D ) continue;
        map[u].push_back(make_pair(v,w));
    }
    
    dijkstra();

    cout << fast_road[D];

    return 0;
}
