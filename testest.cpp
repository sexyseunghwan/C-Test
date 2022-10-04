#include <iostream>
#include <climits>

using namespace std;

int N;
int dp[501][501];
int use_case[501];
int MAX = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        int r,c;
        cin >> r >> c;
        
        if (i==0) {
            use_case[0] = r;
            use_case[1] = c;
        } else {
            use_case[i+1] = c;
        } 
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            int s = j+i+1;
            dp[j][s] = MAX;
            
            for (int k = 0; k < i+1; k++) {    
                dp[j][s] = min(dp[j][s],dp[j][j+k] + dp[j+k+1][s] + (use_case[j] * use_case[j+k+1] * use_case[s+1]));
            }
        }
    }

    cout << dp[0][N-1];
    return 0;
} 

    //cout << answer;

    
