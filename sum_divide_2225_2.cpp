#include <iostream>

using namespace std;

int N,K;
long matrix[202][202];
long DIV = 1000000000;

long dp(int r, int c) {

    if (matrix[r][c] > 0) return matrix[r][c];
    if (r == 1 || c == 0) {
        matrix[r][c] = 1;
        return 1;
    }

    for (int i = 0; i <= c; i++) {
        matrix[r][c] += dp(r-1,i);
        matrix[r][c] %= DIV;
    }

    return matrix[r][c];
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> K;

    long answer = dp(K,N);

    cout << answer;
}