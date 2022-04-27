#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

int costs[1002];
int visited[1002];
int N,M,S_V,E_V,total;
int INF = INT_MAX;
stack<int> st;
vector < pair<int,int> > map[1002];

void dijkstra(int start) {
    for (int i = 0; i <= N; i++) {
        costs[i] = INF;
    }
    
    priority_queue < pair<int,int> > pq;
    pq.push(make_pair(0,start));
    costs[start] = 0;
    int index = 0;
    
    while(!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_w = -pq.top().first;
        
        pq.pop();
        
        if (costs[cur_v] < cur_w) continue;
        
        for (int i = 0; i < map[cur_v].size(); i++) {
            int new_v =  map[cur_v][i].first;
            int new_w =  map[cur_v][i].second;
            
            if (costs[new_v] > cur_w + new_w) {
                costs[new_v] = cur_w + new_w;
                pq.push(make_pair(-costs[new_v],new_v));
                visited[new_v] = cur_v;
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
        int s,e,w;
        
        cin >> s >> e >> w;
        
        map[s].push_back(make_pair(e,w));
    }
    
    cin >> S_V >> E_V;
    
    dijkstra(S_V);

    for (int i = E_V; i > 0;) {
        if (visited[i] != 0) st.push(i=visited[i]);
        else i = visited[i];
    }
    
    total = st.size() + 1;
    
    cout << costs[E_V] << "\n" << total << "\n";
    
    while(!st.empty()) {
         cout << st.top() << " ";
         st.pop();
    }
    
    cout << E_V;
    
    
    return 0;
}