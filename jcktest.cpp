#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int N,max_count;
int matrix[501][501];
int visit[501][501];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

int dynamic(int r, int c) {

   if (visit[r][c] != 0) return visit[r][c];
   visit[r][c] = 1;
   
   for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr >= 0 && nr < N && nc >= 0 && nc < N && matrix[nr][nc] > matrix[r][c]) {
         visit[r][c] = max(visit[r][c],dynamic(nr,nc)+1);
      }
   }

   return visit[r][c];
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);
   cin >> N;

   for (int i = 0; i < N*N; i++) cin >> matrix[i/N][i%N];   

   for (int i = 0; i < N*N; i++) {
      max_count = max(dynamic(i/N,i%N),max_count);
   }

   cout << max_count;
   
   return 0;
}