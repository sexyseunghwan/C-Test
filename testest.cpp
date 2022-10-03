#include <iostream>

using namespace std;

int N;
int dp[501][501];
//pair < int,int > pairs[501];
int use_case[501];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;

    //모든 dp 배열을 최대로 지정해준다.

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
            for (int k = 0; k < i+1; k++) {
                //dp[j][j+1] = dp[][] + dp[][] + use_case[]*use_case[]*use_case[];
            }
        }
    }

    
    return 0;
}
