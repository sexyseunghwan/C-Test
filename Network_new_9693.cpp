#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <climits>
#define MAX 21

using namespace std;

int INF = INT_MAX;
int dist[MAX];
int preve[MAX];
int CASE = 1;
stack<int> st;
int T,N,M;
vector< pair<int,int> > edge[MAX];//간선정보

void clean() {
    for (int i = 0; i < MAX; i++) {
        preve[i] = -1;
        dist[i] = INF;
        edge[i].clear();
    }
}

void dijkstra() {
    priority_queue < pair<int,int> > pq;
    dist[0] = 0;
    pq.push(make_pair(0,0));

    while(!pq.empty()) {
        int cur_r = pq.top().first;
        int cur_w = -pq.top().second;

        pq.pop();

        if (dist[cur_r] < cur_w) continue;

        for (int i = 0; i < edge[cur_r].size(); i++) {
            int next_r = edge[cur_r][i].first;
            int next_w = edge[cur_r][i].second;

            if (dist[next_r] > next_w + cur_w) {
                dist[next_r] = next_w + cur_w;
                preve[next_r] = cur_r;
                pq.push(make_pair(next_r,- dist[next_r]));
            }
        }

    }
}

void answer() {
    if (dist[M-1] == INF) cout << "Case #" << CASE++ << ": -1\n";
    else {

        stack<int> st;
        cout << "Case #" << CASE++ << ":";
        
        for (int i = M-1; i >0;) {
            st.push(i = preve[i]);
        }
        
        while(!st.empty()) {
            cout << " " << st.top();
            st.pop();
        }
        cout << " " << M-1 << "\n";
    }
}

int main()
{   
    scanf("%d",&T);

    while(T--) {
        scanf("%d %d",&N,&M);
        clean();

        for (int i = 0; i < N; i++) {
            int r,c,w;
            scanf("%d %d %d",&r,&c,&w);

            edge[r].push_back(make_pair(c,w));
            edge[c].push_back(make_pair(r,w));
        }

        dijkstra();
        answer();
            
    }

    return 0;
}