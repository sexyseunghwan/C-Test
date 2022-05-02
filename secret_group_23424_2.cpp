#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int T,N,M,K;
int INF = 1000000000;
int sum_arr[102];
int map[102][102];

void init() {
    for (int i = 1; i <= N; i++) {
        sum_arr[i] = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) map[i][j] = 0; 
            else map[i][j] = INF;
        }
    }
}

void floyd_washall() {
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                else  map[i][j] = min(map[i][j],map[i][k] + map[k][j]);
            }
        }
    }
}

void find_min(int start) {

    for (int i = 1; i <= N; i++) {
        sum_arr[i] += map[start][i];
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    
    cin >> T;

    while(T-- > 0) {

        cin >> N >> M;
        
        init();

        for (int i = 0; i < M; i++) {
            int s,e,d;

            cin >> s >> e >> d;

            map[s][e] = d;
            map[e][s] = d;
        }

        floyd_washall();

        cin >> K;
        
        for (int i = 0; i < K; i++) {
            int index;
            cin >> index;

            find_min(index);
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