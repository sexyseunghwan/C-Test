#include <iostream>

using namespace std;


int T,W;
int input[1002];
int dp_arr[3][1002][32];
int max_val;

int main()
{
    cin >> T >> W;

    for (int i = 1; i <= T; i++) cin >> input[i];
    
    // T W 
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= W+1; j++) {
            
            if (input[i] == 1) {

                dp_arr[1][i][j] = max(dp_arr[1][i-1][j] + 1 , dp_arr[2][i-1][j-1] + 1);
                dp_arr[2][i][j] = max(dp_arr[1][i-1][j-1], dp_arr[2][i-1][j]);

            } else {
                
                if (i == 1 && j == 1) continue;
                
                dp_arr[1][i][j] = max(dp_arr[1][i-1][j], dp_arr[2][i-1][j-1]);
                dp_arr[2][i][j] = max(dp_arr[1][i-1][j-1] + 1, dp_arr[2][i-1][j] + 1);
            }
        }
    }

    for (int i = 1; i <= T+1; i++) {
        max_val = max(max_val,max(dp_arr[1][T][i],dp_arr[2][T][i]));
    }

    cout << max_val;

    return 0;
}

