#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int T,N,M,K;
int INF = INT_MAX;
int v_arr[102];
int sum_arr[102];
vector < pair<int,int> > map[102];


void init() {
    for (int i = 0; i<= N; i++) {
        sum_arr[i] = 0;
        map[i].clear();
    }
}

void dijkstra(int start) {
    
    for (int i = 0; i <= N; i++) {
        v_arr[i] = INF;
    }
    
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0,start));
    v_arr[start] = 0;

    while(!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_d = pq.top().first;
        
        pq.pop();

        if (v_arr[cur_v] < cur_d) continue;

        for (int i = 0; i < map[cur_v].size(); i++) {
            int new_v = map[cur_v][i].first;
            int new_d = map[cur_v][i].second;
            
            if (v_arr[new_v] > new_d + cur_d) {
                v_arr[new_v] = new_d + cur_d;
                pq.push(make_pair(v_arr[new_v],new_v));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        sum_arr[i] += v_arr[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    
    cin >> T;

    while(T-- > 0) {
        
        init();

        cin >> N >> M;
        
        for (int i = 0; i < M; i++) {
            int s,e,d;

            cin >> s >> e >> d;

            map[s].push_back(make_pair(e,d));
            map[e].push_back(make_pair(s,d));
        }

        cin >> K;
        
        for (int i = 0; i < K; i++) {
            int index;
            cin >> index;

            dijkstra(index);
        } 

        int result = INT_MAX;
        int min_index = 0;

        for (int i = 1; i <= N; i++) {
            if (result > sum_arr[i]) {
                min_index = i;
                result = sum_arr[i];
            }
        }

        cout << min_index << "\n";
        
    }


    return 0;
}