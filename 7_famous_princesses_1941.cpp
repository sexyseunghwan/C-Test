#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

char matrix[6][6];

int main()
{

    for (int i = 0; i < 5; i++)
    {
        char ch[6];
        cin >> ch;

        for (int j = 0; j < 5; j++)
        {
            char input = ch[j];
            matrix[i][j] = input;
        }
    }

    return 0;
}