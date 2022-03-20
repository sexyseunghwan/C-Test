#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 21
#define LL long long
#define INF 1e9

using namespace std;


int dist[MAX];
int preve[MAX];
int CASE = 1;
stack<int> st;
int T,N,M;
vector< pair<int,int> > edge[MAX];//간선정보


void clean() {
    for (int i = 0; i < 21; i++) {
        dist[i] = INF;
        preve[i] = -1;
        edge[i].clear();
    }
}

void input() {
    cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		edge[X].push_back(make_pair(Y,Z));
        edge[Y].push_back(make_pair(X,Z));
	}
}

void dijkstra() {
    priority_queue< pair<int,int> > pq;
    dist[0] = 0;
    pq.push(make_pair(0,0));

    while(!pq.empty()) {
        int cur = pq.top().first;
        int cur_cost = -pq.top().second;
        pq.pop();

        if (dist[cur] < cur_cost) continue;

        for (int i = 0; i < edge[cur].size(); i++) {
            int next = edge[cur][i].first;
            int next_cost = edge[cur][i].second;

            if (dist[next] > cur_cost + next_cost) {
                dist[next] = cur_cost + next_cost;
                preve[next] = cur;
                pq.push(make_pair(next,-dist[next]));
            }
        }
        
    }//while
}


void find_Answer() {
	if (dist[M-1] == INF) {
        cout << "Case #" << CASE++ << ": " << -1 << "\n";
    }
    else {
        for (int i = M-1; i > 0;) {
            st.push(i = preve[i]);
        }
        cout << "Case #" << CASE++ << ":";

        while(!st.empty()) {
            cout << " " << st.top();
            st.pop();
        }
        cout << " " << M-1 << "\n";

    }
}   

int main()
{   
    FASTIO
	cin >> T;
	while (T--) {
		clean();
		input();
		dijkstra();
		find_Answer();
	};

    return 0;
}