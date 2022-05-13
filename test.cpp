#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int INF = INT_MAX;
int T,N,M,K;
int ver_val[102][10002];
vector < pair< pair<int,int>,int> > map[102];

void dijkstra() {
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            ver_val[i][j] = INF;
        }
    }
    
   priority_queue< pair< pair<int,int> ,int> > pq;
   pq.push(make_pair(make_pair(0,0),1));
   ver_val[1][0] = 0;
   
   while(!pq.empty()) {
       int cur_u = pq.top().second;
       int cur_d = -pq.top().first.first;
       int cur_c = -pq.top().first.second;
       
       pq.pop();
       
       for (int i = 0; i < map[cur_u].size(); i++) {
            int new_u = map[cur_u][i].second;
            int new_d = map[cur_u][i].first.first + cur_d;
            int new_c = map[cur_u][i].first.second + cur_c;
            
            if (new_c > M) continue;
            else if (ver_val[new_u][new_c] > new_d) {
                ver_val[new_u][new_c] = new_d;
                pq.push(make_pair(make_pair(-new_d,-new_c),new_u));
            }
            
       }
   }
}

int main()
{
    cin >> T;
    
    while(T--) {
        cin >> N >> M >> K;
        
        for (int i = 0; i <= N; i++) {
            map[i].clear();
        }
        
        for (int i = 0; i < K; i++) {
            int u,v,c,d;
            cin >> u >> v >> c >> d;
            
            map[u].push_back(make_pair(make_pair(d,c),v));
        }
        
        dijkstra();
        
        int result = INF;
        
        for (int i = 0; i <= M; i++) {
            result = min(result,ver_val[N][i]);
        }
        
        if (result == INF) cout << "Poor KCM\n";
        else cout << result << "\n";
    }
    
    return 0;
}
