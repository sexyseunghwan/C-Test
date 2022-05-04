#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

int N,M,K;
int INF = INT_MAX;
vector< pair<int,int> > map[1002];
priority_queue <int> heap[1002];

void dijkstra() {

    priority_queue < pair<int,int> > pq;
    pq.push(make_pair(0,1));
    heap[1].push(0);

    while(!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_w = -pq.top().first;
        
        pq.pop();
        
        for (int i = 0; i < map[cur_v].size(); i++) {
            int new_v = map[cur_v][i].first;
            int new_w = cur_w + map[cur_v][i].second;

            if (heap[new_v].size() < K) {
                heap[new_v].push(new_w);
                pq.push(make_pair(-new_w,new_v));
            } else {
                if (heap[new_v].top() > new_w) {
                    heap[new_v].pop();
                    heap[new_v].push(new_w);
                    pq.push(make_pair(-new_w,new_v));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    cin >> N >> M >> K;
    
    for (int i = 0; i < M; i++) {
        int s,e,d;

        cin >> s >> e >> d;
        
        map[s].push_back(make_pair(e,d));
    }    

    dijkstra();
    
    for (int i = 1; i <= N; i++) {
        if (heap[i].size() != K) cout << -1 << "\n";
        else cout << heap[i].top() << "\n";
    }

    return 0;
}