#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

int N,M,R;
int INF = INT_MAX;
int area[102];
int area_path[102];
int max_item_cnt = INT_MIN;
vector < pair<int,int> > map[102]; 

int dijkstra(int start) {
    
    for (int i = 0; i <= N; i++) {
        area_path[i] = INF;
    }

    priority_queue < pair<int,int> > pq;
    pq.push(make_pair(0,start));
    area_path[start] = 0;

    while(!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_w = -pq.top().first;

        pq.pop();
        
        if (area_path[cur_v] < cur_w) continue;

        for (int i = 0; i < map[cur_v].size(); i++) {
            int new_v = map[cur_v][i].first;
            int new_w = map[cur_v][i].second;
            
            if (area_path[new_v] > new_w + cur_w) {
                area_path[new_v] = new_w + cur_w;
                pq.push(make_pair(-area_path[new_v],new_v));
            }
        }
    }

    int count = 0;

    for (int i = 1; i <= N; i++) {
        if (area_path[i] <= M) {
            count += area[i];
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    cin >> N >> M >> R; 

    for (int i = 1; i <= N; i++) {
        cin >> area[i]; 
    }
    
    for (int i = 0 ; i < R; i++) {
        int s,e,w;

        cin >> s >> e >> w;

        map[s].push_back(make_pair(e,w));
        map[e].push_back(make_pair(s,w));
    }

    for (int i = 1; i <= N; i++) {
        int result = dijkstra(i);
        max_item_cnt = max_item_cnt > result ? max_item_cnt : result;
    }

    cout << max_item_cnt;
    

    return 0;
}