#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int INF = INT_MAX;
int N,D;
int fast_road[10002];
vector < pair<int,int> > map[10002];

void dq() {

    for (int i = 0; i < D; i++) {
        fast_road[i] = INF;
    }

    fast_road[D] = D;

    for (int i = 0; i <= D; i++) {
        
        int prev_dist;

        if (i == 0) prev_dist = -1; 
        else prev_dist = fast_road[i-1];

        fast_road[i] = min(fast_road[i],prev_dist+1);

        for (int j = 0; j < map[i].size(); j++) {
            int road = map[i][j].first;
            int dist = map[i][j].second;
            
            if (fast_road[road] > fast_road[i] + dist) {
                fast_road[road] = fast_road[i] + dist;
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

        if (v > D) continue;
        if (v - u < w) continue;

        map[u].push_back(make_pair(v,w));
    }
    
    dq();

    cout << fast_road[D];
  
    return 0;
}
