#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int INF = INT_MAX;
int V,E;
int s_v;
int vis[20001];
vector < pair<int,int> > map[20001];

void init() {
    for (int i = 1; i <= V; i++) {
        vis[i] = INF;
    }
}

void dijsktra() {
    priority_queue< pair<int,int> > pq;
    vis[s_v] = 0;
    pq.push(make_pair(0,s_v));

    while(!pq.empty()) {
        int cur_w = -pq.top().first;
        int cur_v = pq.top().second;
        
        pq.pop();

        if (vis[cur_v] < cur_w) continue;

        for (int i = 0; i < map[cur_v].size(); i++) {
            int new_v = map[cur_v][i].first;
            int new_w = map[cur_v][i].second;

            if (vis[new_v] > cur_w + new_w) {
                vis[new_v] = cur_w + new_w;
                pq.push(make_pair(-vis[new_v],new_v));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V >> E >> s_v;

    init();

    for (int i = 0; i < E; i++) {
        int r,c,w;

        cin >> r >> c >> w;
        
        map[r].push_back(make_pair(c,w));
    }

    dijsktra();

    for (int i = 1; i <= V; i++) {
        int val = vis[i];
        if (val == INF) cout << "INF\n";
        else cout << vis[i] << "\n";
    }
    
    return 0;
}