#include <iostream>
#include <vector>
#include <queue>
#include <vector>

using namespace std;

int main() {

    priority_queue< pair< pair<int,int>,int > > pq;

    pq.push(make_pair(make_pair(-4,-2),1));
    pq.push(make_pair(make_pair(-1,-10),1));
    pq.push(make_pair(make_pair(-1,-5),1));
    pq.push(make_pair(make_pair(-1,-5),10));


    cout << pq.top().first.first << " " << pq.top().first.second << " " << pq.top().first.second;



}