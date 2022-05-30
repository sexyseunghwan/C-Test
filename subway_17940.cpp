#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int N,M;
int station[1002];
int INF = INT_MAX;
int min_statcion[1002][1002];
vector < pair<int,int> > map[1002];

void dijkstra() {
    
    for (int i = 0; i < N*N; i++) {
        min_statcion[i/N][i%N] = INF;
    }
    
    priority_queue < pair< pair<int,int>,pair< int,int > > > pq;
    pq.push(make_pair(make_pair(0,0),make_pair(0,0)));
    min_statcion[0][0] = 0;

    while(!pq.empty()) {
        int cur_u = pq.top().second.first;
        int cur_station = pq.top().second.second;
        int cur_dist = -pq.top().first.second;
        int cur_trans = -pq.top().first.first;
        
        pq.pop();

        if (min_statcion[cur_u][cur_trans] < cur_dist) continue;

        for (int i = 0; i < map[cur_u].size(); i++) {
            int next_u = map[cur_u][i].first;
            int next_dist = map[cur_u][i].second + cur_dist;
            int next_station = station[next_u];

            if (next_station == cur_station) {
                if (min_statcion[next_u][cur_trans] > next_dist) {
                    min_statcion[next_u][cur_trans] = next_dist;
                    pq.push(make_pair(make_pair(-cur_trans,-next_dist),make_pair(next_u,next_station)));
                }
            } else {
                if (min_statcion[next_u][cur_trans+1] > next_dist) {
                    min_statcion[next_u][cur_trans+1] = next_dist;
                    pq.push(make_pair(make_pair(-(cur_trans+1),-next_dist),make_pair(next_u,next_station)));
                }
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

    for (int i = 0; i < N; i++) {
        cin >> station[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j= 0; j < N; j++) {
            int num;
            cin >> num;
            
            if (num != 0) map[i].push_back(make_pair(j,num));
        }
    }
    
    dijkstra();

    for (int i = 0; i < N; i++) {
        if (min_statcion[M][i] != INF) {
            cout << i << " " << min_statcion[M][i];
            break;
        }
    }

    return 0;
}