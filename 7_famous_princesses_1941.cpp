#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int matrix[5][5];
int visit[25];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int total_cnt = 0;

bool adjacent()
{
    queue< pair <int, int> > que;
    bool answer = false;
    int check_select[5][5];
    int queue_select[5][5];

    memset(check_select,0,sizeof(check_select));
    memset(queue_select,0,sizeof(queue_select));

    int temp = 0;
    for (int i = 0; i < 25; i++) {
        if (visit[i] == 1) {
            int r = i/5;
            int c = i%5;

            check_select[r][c] = 1;

            if (temp == 0) {
                que.push(make_pair(r,c));
                queue_select[r][c] = 1;
                temp++;
            }
        }
    }

    int cnt = 1;
    while(!que.empty()) {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        if (cnt == 7) {
            answer = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            if (new_r >= 0 && new_c >= 0 && new_r < 5 && new_c < 5) {
                if (check_select[new_r][new_c] == 1 && queue_select[new_r][new_c] == 0) {
                    queue_select[new_r][new_c] = 1;
                    que.push(make_pair(new_r,new_c));
                    cnt++;
                }
            }
        }
    }

    return answer;

}

bool more_than_four()
{
    int scnt = 0;
    bool flag = false;

    for (int i = 0; i < 25; i++)
    {
        if (visit[i] == 1)
        {
            int r = i / 5;
            int c = i % 5;

            if (matrix[r][c] == 1) scnt++;
        }

        if (scnt == 4)
        {
            flag = true;
            break;
        }
    }

    return flag;
}

void dfs(int idx, int cnt)
{

    if (cnt == 7)
    {   
        if (more_than_four()) {
            if (adjacent()) total_cnt++;
        }
        return;
    }
    

    for (int i = idx; i < 25; i++)
    {
        if (visit[i] == 1) continue;
        
        visit[i] = 1;
        dfs(i, cnt + 1);
        visit[i] = 0;
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; i++)
    {
        char ch[6];
        cin >> ch;

        for (int j = 0; j < 5; j++)
        {
            char input = ch[j];
            if (input == 'S') matrix[i][j] = 1;
            else matrix[i][j] = 2;
        }
    }

    dfs(0, 0);

    cout << total_cnt;

    return 0;
}