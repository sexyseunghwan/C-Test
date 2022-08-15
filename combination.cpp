#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int arr[5] = {1, 2, 3, 4, 5};
bool select[5];

void print()
{

    for (int i = 0; i < 5; i++)
    {
        if (select[i] == true)
        {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}

void cbn(int idx, int cnt)
{

    if (cnt == 3)
    {
        print();
        return;
    }

    for (int i = idx; i < 5; i++)
    {
        if (select[i])
            continue;
        select[i] = true;

        cbn(i, cnt + 1);
        select[i] = false;
    }
}

int main()
{

    cbn(0, 0);

    return 0;
}