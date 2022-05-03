#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N,M;
int INF = 987654321;
vector < pair<int,int> > vec;
char map[101][101];
int visit_map[101][101];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};


void dijkstra(int r, int c) {

    queue< pair< pair<int,int>, pair<int,int> > > q;
    
    for (int i = 0; i < 4; i++) {
       q.push(make_pair(make_pair(0,i),make_pair(r,c))); 
    }
    
    visit_map[r][c] = 0;
    
    while(!q.empty()) {
        
        int cur_cnt = q.front().first.first;
        int cur_dir = q.front().first.second;
        int cur_r = q.front().second.first;
        int cur_c = q.front().second.second;
        
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_r = cur_r + dr[i];
            int new_c = cur_c + dc[i];
            int new_cur_cnt = cur_cnt;

            if (new_r < 0 || new_c < 0 || new_r >= N || new_c >= M) continue;
            if (map[new_r][new_c] == '*') continue;
            if (cur_dir != i) {
                new_cur_cnt++;
            }
            if (visit_map[new_r][new_c] >= new_cur_cnt) {
                visit_map[new_r][new_c] = new_cur_cnt;
                q.push(make_pair(make_pair(new_cur_cnt,i),make_pair(new_r,new_c)));
            }

        }
    }
}

int main()
{
    
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            visit_map[i][j] = INF;
            if (map[i][j] == 'C') vec.push_back(make_pair(i,j));
        }
    }
    
    int start_r = vec[0].first;
    int start_c = vec[0].second;
    int end_r = vec[1].first;
    int end_c = vec[1].second;
    
    dijkstra(start_r,start_c);
    
    cout << visit_map[end_r][end_c] << "\n";
    
    return 0;
}

