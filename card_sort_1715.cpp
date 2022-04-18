#include <iostream>
#include <queue>

using namespace std;

int main() {

    int N;

    priority_queue <int> pq;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(-num);
    }    

    int compare_cnt = 0;
    int result = 0;
    
    while(!pq.empty()) {

        if (compare_cnt == N-1) break;

        int sum = 0;

        for (int i = 0; i < 2; i++) {
            sum += -pq.top();
            pq.pop();
        }

        result = result + sum;
        pq.push(-sum);
        compare_cnt++;
    }

    cout << result;

    return 0;
}