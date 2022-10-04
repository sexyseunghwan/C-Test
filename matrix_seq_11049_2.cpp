#include <iostream>
#include <vector>
#include <climits>

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
    
    for (int i = 0; i < N-1; i++) {// i = 0 1 2 3
        for (int j = 0; j < N-i-1; j++) { 
            //i == 0 : j = 0 1 
            int k = j;
            int s = i+j+1;

            dp[k][s] = MAX;
            for (int t = k; t < s; t++) {
                dp[k][s] = min(dp[k][s],dp[k][t] + dp[t+1][s] + bias(k,t,s));       
            }   
        } 
    }

    cout << dp[0][N-1];    
    
    
    return 0;
}

// int N;
// int dp[501][501];
// int MAX = INT_MAX;
// pair<int,int> matrix[501];

// int remainder(int s, int k, int t) {
//     return matrix[s].first * matrix[k].second * matrix[t].second;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
    
//     cin >> N;
    
//     for (int i = 0; i < N; i++) {
//         int r,c;
//         cin >> r >> c;



//         matrix[i].first = r;
//         //>> 
//         matrix[i].second = c;
//     }
    
//     if (N == 1) {
//         cout << matrix[0].first << endl;
//         cout << matrix[0].second << endl;
//         cout << matrix[0].first * matrix[0].second;        
//     }
    
//     else {
//         for (int i = 0; i < N-1; i++) {
//             for (int j = 1; j < N-i; j++) { 
//                 int s = j-1;
//                 int t = i+j;

//                 dp[s][t] = MAX;    
                
//                 for (int k = s; k < t; k++) {
//                     dp[s][t] = min(dp[s][t],dp[s][k] + dp[k+1][t] + remainder(s,k,t));
//                 }
//             }
//         }
//     }

//     cout << dp[0][N-1];

//     return 0;
// }