#include <iostream>

using namespace std;

int N,K;
long dp[201][201];
int DIV = 1000000000;

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> K;
    
    for (int i = 0; i <= N; i++) dp[1][i] = 1;
    for (int i = 0; i <= K; i++) dp[i][0] = 1;
    
    for (int i = 2; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            long num = dp[i][j-1] + dp[i-1][j];
            dp[i][j] = num % DIV;
        }
    }

    cout << dp[K][N];
    
    return 0;
}

