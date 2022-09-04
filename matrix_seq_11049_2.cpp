#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int dp[501][501];
int MAX = INT_MAX;
pair<int,int> matrix[501];

int remainder(int s, int k, int t) {
    return matrix[s].first * matrix[k].second * matrix[t].second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int r,c;
        cin >> matrix[i].first >> matrix[i].second;
    }
    
    if (N == 1) cout << matrix[0].first * matrix[0].second;
    else {
        for (int i = 0; i < N-1; i++) {
            for (int j = 1; j < N-i; j++) { 
                int s = j-1;
                int t = i+j;

                dp[s][t] = MAX;    
                
                for (int k = s; k < t; k++) {
                    dp[s][t] = min(dp[s][t],dp[s][k] + dp[k+1][t] + remainder(s,k,t));
                }
            }
        }
    }

    cout << dp[0][N-1];

    return 0;
}