#include <iostream>

using namespace std;

int N,K;
long matrix[202][202];
long DIV = 1000000000;

int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> K;

    matrix[0][0] = 1;

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int u = 0; u <= j; u++) {
                matrix[i][j] += matrix[i-1][j-u];
                matrix[i][j] %= DIV;
            }
        }
    }

    cout << matrix[K][N];
    


    return 0;
}