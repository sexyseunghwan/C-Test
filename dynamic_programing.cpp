#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

//아래와 같이 재귀함수를 이용해서 피보나치 수열을 구할 수 있는데 아래의 방법은 매우 비효율적인 방법이다. -> 50 번째 값만 구하려고 해도 버벅인다.
int fibo(int x)
{
    if (x == 1)
        return 1;
    if (x == 2)
        return 1;

    return fibo(x - 1) + fibo(x - 2);
}

int dynamic[100];

int new_fibo(int x)
{
    if (x == 1)
        return 1;
    if (x == 2)
        return 1;
    if (dynamic[x] != 0)
        return dynamic[x];

    return dynamic[x] = new_fibo(x - 1) + new_fibo(x - 2);
}

int main()
{

    /*

    다이나믹 프로그래밍 => 동적계획법이라고 한다 : 하나의 문제는 단 한번만 풀도록 하는 알고리즘이다.
    상당수 분할 정복 기법은 동일한 문제를 다시 푼다는 단점을 가지고 있다. 단순 분할정복으로 풀게 되면 심각한 비효율성을 낳는
    대표적인 예시로는 피보나치 수열이 존재한다.

    피보나치 수열의 점화식 : D[i] = D[i-1] + D[i-2]
    1,1,2,3,5,8,13,21,.....

    분할정복으로 알고리즘을 구성하게 되면 이미 완료한 계산을 계속 다시 해주는 불합리성이 존재하는데
    이를 막기 위해 메모이제이션을 사용하여 이미 계산한 결과는 배열에 저장함으로써 나중에 동일한 계산을 할 때는 저장된 값을 단순히 반환하기만 하면 된다.
    */

    cout << fibo(10);

    cout << "\n";

    new_fibo(10);

    cout << dynamic[10];
}