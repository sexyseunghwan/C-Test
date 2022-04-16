#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int N,M;
int s_v,e_v;
int INF = INT_MAX;
int visits[100002];
vector< pair<int,int> > map[100002];

void dijkstra() {
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(s_v,0));
    visits[s_v] = 0;

    while(!pq.empty()) {
        int cur_v = pq.top().first;
        int cur_w = -pq.top().second;
        
        pq.pop();

        if (visits[cur_v] < cur_w) continue;

        for (int i = 0; i < map[cur_v].size(); i++) {
            int next_v = map[cur_v][i].first;
            int next_w = map[cur_v][i].second;

            if (visits[next_v] > cur_w + next_w) {
                visits[next_v] = cur_w + next_w;
                pq.push(make_pair(next_v,-visits[next_v]));
            }
        }
    }//while
}

int main()
{
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        visits[i] = INF;
    }

    for (int i = 0; i < M; i++) {
        int r,c,w;
        cin >> r >> c >> w;

        map[r].push_back(make_pair(c,w));
    }
    
    cin >> s_v >> e_v;
    
    dijkstra();

    cout << visits[e_v];

    return 0;
}