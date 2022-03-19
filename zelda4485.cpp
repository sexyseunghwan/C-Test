#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int INF = 999999999;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int map[126][126];
int dist[126][126];

void clean(int size) {
    for (int i = 0; i < size*size; i++) {
        map[i/size][i%size] = 0;
    }
}


void dijkstra(int size) {
    priority_queue < pair< int,pair<int,int> > > pq;
    pq.push(make_pair(-map[0][0],make_pair(0,0)));
    dist[0][0] = map[0][0];

    while(!pq.empty()) {
        int cur_dist = -pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;

        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < size && nc < size) {
                if (dist[nr][nc] > map[nr][nc] + cur_dist) {
                    dist[nr][nc] = map[nr][nc] + cur_dist;
                    pq.push(make_pair(-dist[nr][nc],make_pair(nr,nc)));
                }
            }
        }
    }

}

int main()
{
    int count = 1;

    while(true) {
        int m_s;
        scanf("%d",&m_s);
        
        if (m_s == 0) break;
        
        for (int i = 0; i < m_s; i++) {
            for (int j = 0; j < m_s; j++) {
                scanf("%d",&map[i][j]);
                dist[i][j] = INF;
            }
        }

        dijkstra(m_s);
        printf("Problem %d: %d\n",count,dist[m_s-1][m_s-1]);
        clean(m_s);
        count++;
        
    }

    return 0;
}