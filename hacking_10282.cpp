#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

int INF = INT_MAX;
int TN,N,D,C;
int visited[10002];
vector < pair<int,int> > map[10002];

void init() {
    for (int i = 0; i <= N; i++) {
        visited[i] = INF;
        map[i].clear();
    }
}

void dijkstra(int start) {
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(0,start));
    visited[start] = 0;

    while(!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_t = -pq.top().first;

        pq.pop();

        if (visited[cur_v] < cur_t) continue;

        for (int i = 0; i < map[cur_v].size(); i++) {
            int new_v = map[cur_v][i].first;
            int new_t = map[cur_v][i].second;

            if (visited[new_v] > new_t + cur_t) {
                visited[new_v] = new_t + cur_t;
                pq.push(make_pair(-visited[new_v],new_v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    
    cin >> TN;

    while(TN-- > 0) {
        cin >> N >> D >> C;       
        
        init();

        for (int i = 0 ; i < D; i++) {
            int a,b,s;

            cin >> a >> b >> s;

            map[b].push_back(make_pair(a,s));
        }

        dijkstra(C);
        
        int total_cnt = 0;
        int max_time = 0;

        for (int i = 1; i <= N; i++) {
            if (visited[i] != INF) {
                total_cnt++;
                max_time = max_time > visited[i] ? max_time : visited[i];
            }

        }

        cout << total_cnt << " " << max_time << "\n";
    }

    return 0;
}