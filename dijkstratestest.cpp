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
int weight[MAX];
int pre_index[MAX];
vector< pair<int,int> > nodes[MAX];


void clear() {
    for (int i = 0; i < MAX; i++) {
        weight[i] = INF;
        pre_index[i] = -1;
        vector< pair<int,int> >().swap(nodes[i]);
    }
}

void dijkstra() {
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(0,0));
    weight[0] = 0;

    while(!pq.empty()) {
        int cur = pq.top().first;
        int cur_w = -pq.top().second;

        pq.pop();

        if (weight[cur] < cur_w) continue;

        for (int i = 0; i < nodes[cur].size(); i++) {
            int next = nodes[cur][i].first;
            int next_w = nodes[cur][i].second;

            if (weight[next] > cur_w + next_w) {
                weight[next] = cur_w + next_w;
                pre_index[next] = cur;
                pq.push(make_pair(next,-weight[next]));
            }
        }
    }//while

    if (weight[M-1] == INF) cout << "Case #" << CASE++ << ": -1\n";
    else {
        stack<int> stack;

        for (int i = (M-1); i > 0;) {
            stack.push(i = pre_index[i]);
        }

        cout << "Case #" << CASE++ << ":";

        while(!stack.empty()) {
            cout << " " << stack.top();
            stack.pop();
        }

        cout << " " << (M-1) << "\n";
    }

}

int main()
{
    cin >> N;

    while(N--) {
        cin >> R >> M;
        clear();

        for (int i = 0; i < R; i++) {
            int r,c,w;

            cin >> r >> c >> w;

            nodes[r].push_back(make_pair(c,w));
            nodes[c].push_back(make_pair(r,w));
        }

        dijkstra();
    }
}