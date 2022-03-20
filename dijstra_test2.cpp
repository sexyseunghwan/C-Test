#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 6;
int INF = 1000000000;

vector< pair<int,int> > a[7];//간선정보
int d[7];//최소비용

void dijkstra(int start) {
    d[start] = 0;
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(start,0));

    while(!pq.empty()) {
        int current = pq.top().first;
        int distance = -pq.top().second;


        pq.pop();

        if (d[current] < distance) continue;

        for (int i = 0; i < a[current].size(); i++) {

            int next = a[current][i].first;//선택된 노드의 인접 노드
            
            int next_distance = distance + a[current][i].second;//선택된 노드를 인접 노드로 가져서 가는 최소 비용
            
            if (d[next] > next_distance) {
                d[next] = next_distance;
                pq.push(make_pair(next,-next_distance));
            }

        }

    }

}


int main()
{
    for (int i = 0; i <= number; i++) {
        d[i] = INF;
    }
    
    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(3,5));
    a[1].push_back(make_pair(4,1));


    a[2].push_back(make_pair(1,2));
    a[2].push_back(make_pair(3,3));
    a[2].push_back(make_pair(4,2));


    a[3].push_back(make_pair(1,5));
    a[3].push_back(make_pair(2,3));
    a[3].push_back(make_pair(4,2));
    a[3].push_back(make_pair(5,1));
    a[3].push_back(make_pair(6,5));


    a[4].push_back(make_pair(1,1));
    a[4].push_back(make_pair(2,2));
    a[4].push_back(make_pair(3,3));
    a[4].push_back(make_pair(5,1));


    a[5].push_back(make_pair(3,1));
    a[5].push_back(make_pair(4,1));
    a[5].push_back(make_pair(6,2));


    a[6].push_back(make_pair(3,5));
    a[6].push_back(make_pair(5,2));

    dijkstra(1);

    for (int i = 1; i <= number; i++) {
        printf("%d ",d[i] );
    }

    return 0;
}