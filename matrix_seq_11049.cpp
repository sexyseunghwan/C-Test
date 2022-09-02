#include <iostream>

using namespace std;

int N;
int matrix[501][501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    
    for (int i = 1; i < N; i++) {
        for (int dx = 1; dx + i <= N; dx++) {
            int dy = dx + i;
            for (int mid = dx; mid < dy; mid++) {
                printf("i : %d, dx : %d, dy : %d, mid : %d\n",i,dx,dy,mid);
            }
        }
    }


    

    return 0;
}