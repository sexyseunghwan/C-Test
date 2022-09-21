#include <iostream>

using namespace std;

int N,K;
int dp[3][1001][32];
int input_arr[1001];
int peach_cnt = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> input_arr[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K+1; j++) {
            if (input_arr[i] == 1) {
                dp[1][i][j] = max(dp[1][i-1][j] + 1, dp[2][i-1][j-1] + 1);
                dp[2][i][j] = max(dp[1][i-1][j-1], dp[2][i-1][j]);
            } else {
                
                if (i == 1 && j == 1) continue;

                dp[1][i][j] = max(dp[1][i-1][j], dp[2][i-1][j-1]);
                dp[2][i][j] = max(dp[1][i-1][j-1] + 1, dp[2][i-1][j] + 1);
            }
        }
    }



    for (int i = 1; i <= K+1; i++) {
        peach_cnt = max(peach_cnt,max(dp[1][N][i],dp[2][N][i]));
    }
    
    cout << peach_cnt;
    

    return 0;
}