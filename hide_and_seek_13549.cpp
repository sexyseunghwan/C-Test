#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

const int MAX = 100002;
int N,K;
bool vs_arr[MAX];
int ress[MAX];

int dijkstra() {
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0,N));
    vs_arr[N] = true;

    while(!pq.empty()) {
        int cur_t = pq.top().first;
        int cur_n = pq.top().second;

        pq.pop();

        if (cur_n == K) return cur_t;

        if (cur_n * 2 < MAX && !vs_arr[cur_n * 2]) {
            vs_arr[cur_n * 2] = true;
            ress[cur_n * 2] = cur_t;
            pq.push(make_pair(cur_t,cur_n * 2));
        }

        if (cur_n + 1 < MAX && !vs_arr[cur_n + 1]) {
            vs_arr[cur_n + 1] = true;
            ress[cur_n + 1] = cur_t+1;
            pq.push(make_pair(cur_t + 1,cur_n + 1));
        }

        if (cur_n - 1 >= 0 && !vs_arr[cur_n - 1]) {
            vs_arr[cur_n - 1] = true;
            ress[cur_n - 1] = cur_t+1;
            pq.push(make_pair(cur_t + 1,cur_n - 1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    
    cin >> N >> K;

    int result = dijkstra();

    cout << result << "\n";



    return 0;
}