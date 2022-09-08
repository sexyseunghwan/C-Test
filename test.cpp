#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int N;
int MAX = INT_MAX;
pair < int,int > pairs[501];
int dp[501][501];

int bias(int k, int t, int s) {
    return pairs[k].first * pairs[t].second * pairs[s].second;    
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int r,c;
        cin >> r >> c;
        pairs[i] = make_pair(r,c);
    }  
    
    for (int i = 0; i < N; i++) { // 0 1 2
        for (int j = 0; j < N-i; j++) { 
            // i == 0 : 0 1 2
            // i == 1 : 0 1
            // i == 2 : 0
            int k = j;
            int s = i+j+1;

            dp[k][s] = MAX;
            for (int t = 0; t < s; t++) {
                dp[k][s] = min(dp[k][s],dp[k][t] + dp[t+1][s] + bias(k,t,s));       
            }   
        } 
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //cout << dp[0][N-1];    
    
    
    return 0;
}

