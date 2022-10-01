#include <iostream>

using namespace std;


int T,W;
int input[1002];
int dp[3][32][1002];
int max_val;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> T >> W;

    for (int i = 1; i <= T; i++) cin >> input[i];
    
    // T W 
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= W+1; j++) {
            
            if (input[i] == 1) {

                dp[1][j][i] = max(dp[1][j][i-1] + 1 , dp[2][j-1][i-1] + 1);
                dp[2][j][i] = max(dp[1][j-1][i-1], dp[2][j][i-1]);

            } else {
                
                if (i == 1 && j == 1) continue;
                
                dp[1][j][i] = max(dp[1][j][i-1], dp[2][j-1][i-1]);
                dp[2][j][i] = max(dp[1][j-1][i-1] + 1, dp[2][j][i-1] + 1);
            }
        }
    }

    for (int i = 1; i <= W+1; i++) {
        max_val = max(max_val,max(dp[1][i][T],dp[2][i][T]));
    }

    cout << max_val;


     

    return 0;
}

