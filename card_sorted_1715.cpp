#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;

    cin >> N;
    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        pq.push(-input);
    }
    
    int result = 0;
    int compare_cnt = 0;
    
    while(!pq.empty()) {
        
        if (compare_cnt == N-1) break;

        int sum = 0;
        
        for (int i = 0; i < 2; i++) {
            sum += -pq.top();
            pq.pop();
        }
        
        result += sum;
        pq.push(-sum);
        compare_cnt++;
    }//while

    cout << result;

    return 0;
}