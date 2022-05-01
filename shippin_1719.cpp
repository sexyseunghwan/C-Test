#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int N,M;
int INF = INT_MAX;
int hist_arr[202];
int vist_arr[202];
int result_arr[202][202];
vector < pair<int,int> > maps[202];


void dijsktra(int start) {
    
    for (int i = 0; i <= N; i++) {
        vist_arr[i] = INF;
        hist_arr[i] = 0;
    }
    
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(0,start));
    vist_arr[start] = 0;
    
    while(!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_d = -pq.top().first;

        pq.pop();
        
        if (vist_arr[cur_v] < cur_d) continue;

        for (int i = 0; i < maps[cur_v].size(); i++) {
            int next_v = maps[cur_v][i].first;
            int next_d = maps[cur_v][i].second;

            if (vist_arr[next_v] > next_d + cur_d) {
                hist_arr[next_v] = cur_v;
                vist_arr[next_v] = next_d + cur_d;
                pq.push(make_pair(-vist_arr[next_v],next_v));
            }
        }
    }

    //poward
    for (int i = 1; i <= N; i++) {
        if (i != start) {
            
            int index = i;
            
            while(1) {
                int new_index = hist_arr[index];
                if (new_index == start) {
                    result_arr[start][i] = index;
                    break;
                } 
                index = new_index;
            }
        }
    }//for

    //inverse
    for (int i = 1; i <= N; i++) {
        if ( i != start) {
            result_arr[i][start] = hist_arr[i];
        }
    }
}

int main()
{   
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int s,e,d;

        cin >> s >> e >> d;

        maps[s].push_back(make_pair(e,d));
        maps[e].push_back(make_pair(s,d));

    }


    for (int i = 1; i <= N; i++) {
        dijsktra(i);
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) cout << "- ";
            else cout << result_arr[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}