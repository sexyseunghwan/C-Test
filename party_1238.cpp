#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

//최적화를 생각해볼 필요가 있음

int N,M,X;
int max_dist = INT_MIN;
int visites[1002];
int INF = INT_MAX;
vector < pair<int,int> > map[1002];

void clean() {
    for (int i = 0 ; i < N+1; i++) {
        visites[i] = INF;
    }
}

int dijkstra(int start,int end) {

    clean();
    priority_queue< pair<int,int> > pq;
    
    visites[start] = 0;
    pq.push(make_pair(0,start));

    while(!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_w = -pq.top().first;

        pq.pop();

        if (visites[cur_v] < cur_w) continue;

        for (int i = 0; i < map[cur_v].size(); i++) {
            int new_v = map[cur_v][i].first;
            int new_w = map[cur_v][i].second;

            if (visites[new_v] > new_w + cur_w) {
                visites[new_v] = new_w + cur_w;
                pq.push(make_pair(-visites[new_v],new_v));
            }
        }
    }

    return visites[end];
}


int main()
{
    
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int s,e,w;

        cin >> s >> e >> w;

        map[s].push_back(make_pair(e,w));
    }
    
    for (int i = 1; i <= N; i++) {
        
        if (i != X) {
            int cur_start = dijkstra(i,X);
            int cur_end = dijkstra(X,i);

            int cur_dist = cur_start + cur_end;

            max_dist = max_dist > cur_dist ? max_dist : cur_dist;
        } 
    }

    cout << max_dist;

    return 0;
}