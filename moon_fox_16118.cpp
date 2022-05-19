#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N,M;
int INF = INT_MAX;
vector< pair<int,int> > map[4002];
int fox_result[4002];
double wolf_result[4002][2];

void dijkstra_fox() {
    
    for (int i = 0; i <= N; i++) {
        fox_result[i] = INF;
    }

    priority_queue< pair<int,int> > pq_fox;
    pq_fox.push(make_pair(0,1));
    fox_result[1] = 0;

    while(!pq_fox.empty()) {
        int cur_u = pq_fox.top().second;
        int cur_d = -pq_fox.top().first;
    
        pq_fox.pop();
    
        if (fox_result[cur_u] < cur_d) continue;
    
        for (int i = 0; i < map[cur_u].size(); i++) {
            int next_u = map[cur_u][i].first;
            int next_d = map[cur_u][i].second + cur_d;
        
            if (fox_result[next_u] > next_d) {
                fox_result[next_u] = next_d;
                pq_fox.push(make_pair(-next_d,next_u));
            }
        }
    }     
}

void dijkstra_wolf() {
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            wolf_result[i][j] = INF;
        }
    }
    
    priority_queue< pair< double, pair<int,int> > > pq_wolf;
    pq_wolf.push(make_pair(0,make_pair(1,0)));
    wolf_result[1][0] = 0;

    while(!pq_wolf.empty()) {
        int cur_u = pq_wolf.top().second.first;
        int cur_v = pq_wolf.top().second.second;
        double cur_d = -pq_wolf.top().first;

        pq_wolf.pop();

        if (wolf_result[cur_u][cur_v] < cur_d) continue;

        for (int i = 0; i < map[cur_u].size(); i++) {
            int next_u = map[cur_u][i].first;
            double next_d; 
            int next_v;

            if (cur_v == 0) {
                next_d = (map[cur_u][i].second * 0.5) + cur_d;
                next_v = 1;
            }
            else {
                next_d = (map[cur_u][i].second * 2) + cur_d;
                next_v = 0;
            } 
            
            if (wolf_result[next_u][next_v] > next_d) {
                wolf_result[next_u][next_v] = next_d;
                if (cur_v == 0) pq_wolf.push(make_pair(-next_d,make_pair(next_u,1)));
                else pq_wolf.push(make_pair(-next_d,make_pair(next_u,0)));
            }
        }
    }
}

int main()
{   
    
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int u,v,d;
        
        cin >> u >> v >> d;
        
        map[u].push_back(make_pair(v,d));
        map[v].push_back(make_pair(u,d));
    }
        
    dijkstra_fox();
    dijkstra_wolf();

    int fox_win = 0;

    for (int i = 0; i <= N; i++) {
        if (fox_result[i] < wolf_result[i][0] && fox_result[i] < wolf_result[i][1]) fox_win++;
    }
    
    cout << fox_win;
    
    return 0;
}













