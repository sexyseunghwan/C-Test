#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[501][501];
int MAX = INT_MAX;
//vector < pair<int,int> > matrix;
pair<int,int> matrix[501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> matrix[i].first >> matrix[i].second;
    }

    

    // if (N == 1) {
    //     //int x,y;
        
    // }

    // for (int i = 0; i < N-1; i++) { // 1 2 3
    //     for (int j = 1; j < N-i; j++) { // n-i : 4-0 : 4; 1 2 3; 1 2
    //         int s = j-1;
    //         int t = i+j;

    //         dp[s][t] = MAX;
            
    //         //for (int k = 0; k < t; k++) {
                
    //         //}
    //     }
    // }
    

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    


    

    return 0;
}