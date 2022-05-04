#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int N,M;
int INF = INT_MAX;
int visit_result[50002];
vector < pair<int,int> > map[50002];

void dijkstra() {
    for (int i = 0; i <= N; i++) {
        visit_result[i] = INF;
    }

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0,1));
    visit_result[1] = 0;

    while(!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_d = pq.top().first;

        pq.pop();

        if (visit_result[cur_v] < cur_d) continue;

        for (int i = 0; i < map[cur_v].size(); i++) {
            int new_v = map[cur_v][i].first;
            int new_d = map[cur_v][i].second;

            if (visit_result[new_v] > cur_d + new_d) {
                visit_result[new_v] = cur_d + new_d;
                pq.push(make_pair(visit_result[new_v],new_v));
            }
        }
    }    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int s,e,w;

        cin >> s >> e >> w;
        
        map[s].push_back(make_pair(e,w));
        map[e].push_back(make_pair(s,w));
    }

    dijkstra();
    
    cout << visit_result[N];

    return 0;
}