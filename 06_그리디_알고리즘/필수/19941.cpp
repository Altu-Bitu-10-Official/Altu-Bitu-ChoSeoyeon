/*
기다란 벤치 모양의 식탁에 사람들과 햄버거가 아래와 같이 단위 간격으로 놓여 있다. 사람들은 자신의 위치에서 거리가 $K$ 이하인 햄버거를 먹을 수 있다.
식탁의 길이 $N$, 햄버거를 선택할 수 있는 거리 $K$, 사람과 햄버거의 위치가 주어졌을 때, 햄버거를 먹을 수 있는 사람의 최대 수를 구하는 프로그램을 작성하시오.

첫 줄에 두 정수 N과 K가 있다. 그리고 다음 줄에 사람과 햄버거의 위치가 문자 P(사람)와 H(햄버거)로 이루어지는 길이 $N$인 문자열로 주어진다.
첫 줄에 햄버거를 먹을 수 있는 최대 사람 수를 나타낸다.
*/

// 그리디 알고리즘 사용!

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    int count = 0;
    cin >> n >> k;

    string table;
    cin >> table;

    for (int i=0; i<n; i++) {
        if (table[i] == 'P') {
            int start = max(0, i-k);
            int end = min(n-1, i+k);

            for (int j=start; j<=end; j++) {
                if (table[j] == 'H') {
                    count++;
                    // 먹은 햄버거는 삭제하기
                    table[j] = 'X';
                    break;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}