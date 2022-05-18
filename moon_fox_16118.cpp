#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N,M;
int INF = INT_MAX;
vector< pair<int,int> > map[4002];
double fox_result[4002];
double wolf_result[4002];

void dijkstra(double* result, int gubn) {
    
    for (int i = 0; i <= N; i++) {
        result[i] = INF;
    }
    
    if (gubn == 0) {
        priority_queue< pair<int,int> > pq_fox;
        pq_fox.push(make_pair(0,1));
        result[1] = 0;

        while(!pq_fox.empty()) {
            int cur_u = pq_fox.top().second;
            int cur_d = -pq_fox.top().first;
      
            pq_fox.pop();
      
            if (result[cur_u] < cur_d) continue;
      
            for (int i = 0; i < map[cur_u].size(); i++) {
                int next_u = map[cur_u][i].first;
                int next_d = map[cur_u][i].second + cur_d;
          
                if (result[next_u] > next_d) {
                    result[next_u] = next_d;
                    pq_fox.push(make_pair(-next_d,next_u));
                }
            }
        } 
    } else {
        priority_queue< pair< double, pair<int,int> > > pq_wolf;
        pq_wolf.push(make_pair(0,make_pair(1,1)));
        result[1] = 0;

        while(!pq_wolf.empty()) {
            int cur_u = pq_wolf.top().second.first;
            int cur_v = pq_wolf.top().second.second;
            double cur_d = -pq_wolf.top().first;

            pq_wolf.pop();

            if (result[cur_u] < cur_d) continue;

            for (int i = 0; i < map[cur_u].size(); i++) {
                int next_u = map[cur_u][i].first;
                double next_d; 
                if (cur_v == 1) next_d = (map[cur_u][i].second * 0.5) + cur_d;
                else next_d = (map[cur_u][i].second * 2) + cur_d;

                if (result[next_u] > next_d) {
                    result[next_u] = next_d;
                    pq_wolf.push(make_pair(-next_d,make_pair(next_u,cur_v*-1)));
                }
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
        
    dijkstra(fox_result,0);
    dijkstra(wolf_result,1);

    for (int i = 0; i <= N; i++) {
        cout << fox_result[i] << " ";
    }

    cout << "\n";

    for (int i = 0; i <= N; i++) {
        cout << wolf_result[i] << " ";
    }

    //int fox_win = 0;

    // for (int i = 0; i <= N; i++) {
    //     if (fox_result[i] < wolf_result[i]) fox_win++;
    // }
    
    // cout << fox_win;
    
    return 0;
}













