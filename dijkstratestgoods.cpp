#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <climits>
#define MAX 21
using namespace std;

int INF = INT_MAX;
int N,R,M;
int CASE = 1;
int visit[MAX];
int prep_map[MAX];
vector< pair<int,int> > edge[MAX];

void clean() {
    for (int i = 0; i < MAX; i++) {
        visit[i] = INF;
        prep_map[i] = -1;
        vector< pair<int,int> >().swap(edge[i]);
    }
}

void dijkstra() {

    priority_queue< pair<int,int> > queue;
    queue.push(make_pair(0,0));
    visit[0] = 0;

    while(!queue.empty()) {
        int cur = queue.top().first;//current start vertex
        int cur_w = -queue.top().second;//weight of current start vertex : because of priority_queue, needed multiple -1 
        
        queue.pop();//remove queue data

        if (visit[cur] < cur_w) continue;

        for (int i = 0; i < edge[cur].size(); i++) {
            int next = edge[cur][i].first;//next vertex
            int next_w = edge[cur][i].second;//weight of next vertex

            if (visit[next] > cur_w + next_w) {
                visit[next] = cur_w + next_w;
                prep_map[next] = cur;
                queue.push(make_pair(next,-visit[next]));
            } 
        }//for
    }//while

    //impossible meet supreme commissioner
    if (visit[M-1] == INF) cout << "Case #" << CASE++ << ": -1\n";
    //possible meet supreme commissioner
    else {
        stack<int> st;

        for (int i = (M-1); i > 0;) {
            st.push(i = prep_map[i]);
        }

        cout << "Case #" << CASE++ << ":";

        while(!st.empty()) {
            int num = st.top();
            st.pop();
            cout << " " << num;
        }

        cout << " " << M-1 << "\n";
    }
}

int main()
{
    cin >> N;

    while(N--) {
        cin >> R >> M;
        clean();

        for (int i = 0; i < R; i++) {
            int start, end, weight;

            cin >> start >> end >> weight;
            edge[start].push_back(make_pair(end,weight));
            edge[end].push_back(make_pair(start,weight));

        }

        dijkstra();
    }
    return 0;
}

