#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N,E;
int INF = 987654321;
int distances[802];
int check[802];
vector< pair<int ,int> > map[802];
int sToV1, sToV2, V1ToV2, V1ToN, V2ToN;

void dijkstra(int start) {
    
    for (int i = 0; i <= N; i++) {
        distances[i] = INF;
    }
    
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(0,start));
    distances[start] = 0;

    while(!pq.empty()) {
        int cur_s = pq.top().second;
        int cur_d = -pq.top().first;

        pq.pop();

        for (int i = 0; i < map[cur_s].size(); i++) {
            int new_e = map[cur_s][i].first;
            int new_d = map[cur_s][i].second;

            if (distances[new_e] > new_d + cur_d) {
                distances[new_e] = new_d + cur_d;
                pq.push(make_pair(-distances[new_e],new_e));
            }
        }
    }
}

int main()
{
    cin >> N >> E;
    
    for (int i = 0; i < E; i++) {
        int a,b,c;

        cin >> a >> b >> c;

        map[a].push_back(make_pair(b,c));
        map[b].push_back(make_pair(a,c));
    }
    
    int v1, v2;
    cin >> v1 >> v2;

    int min_dist = INF;

    dijkstra(1);
    sToV1 = distances[v1];
	sToV2 = distances[v2];

    dijkstra(v1);
	V1ToV2 = distances[v2];
	V1ToN = distances[N];

	dijkstra(v2);
	V2ToN = distances[N];

    min_dist = min(min_dist, sToV1 + V1ToV2 + V2ToN);
	min_dist = min(min_dist, sToV2 + V1ToV2 + V1ToN);
	
    if (V1ToV2 == INF || min_dist == INF) cout << -1;
	else cout << min_dist;
    


    return 0;
}