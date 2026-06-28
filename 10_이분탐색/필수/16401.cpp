/*
명절이 되면, 홍익이 집에는 조카들이 놀러 온다. 떼를 쓰는 조카들을 달래기 위해 홍익이는 막대 과자를 하나씩 나눠준다.
조카들이 과자를 먹는 동안은 떼를 쓰지 않기 때문에, 홍익이는 조카들에게 최대한 긴 과자를 나눠주려고 한다.
그런데 나눠준 과자의 길이가 하나라도 다르면 조카끼리 싸움이 일어난다. 따라서 반드시 모든 조카에게 같은 길이의 막대 과자를 나눠주어야 한다.
M명의 조카가 있고 N개의 과자가 있을 때, 조카 1명에게 줄 수 있는 막대 과자의 최대 길이를 구하라.
단, 막대 과자는 길이와 상관없이 여러 조각으로 나눠질 수 있지만, 과자를 하나로 합칠 수는 없다. 단, 막대 과자의 길이는 양의 정수여야 한다.

첫째 줄에 조카의 수 M (1 ≤ M ≤ 1,000,000), 과자의 수 N (1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에 과자 N개의 길이 L1, L2, ..., LN이 공백으로 구분되어 주어진다. 과자의 길이는 (1 ≤ L1, L2, ..., LN ≤ 1,000,000,000) 를 만족한다.

첫째 줄에 조카 1명에게 줄 수 있는 막대 과자의 최대 길이를 출력한다.
단, 모든 조카에게 같은 길이의 막대과자를 나눠줄 수 없다면, 0을 출력한다.
*/

// 과자개수 >= 조카 --> 정렬, 상위 조카만큼 // 과자개수 < 조카 --> 가장 긴 과자 / (조카-과자개수) ------> 이렇게 하려 햇지만 n>m인데 과자가 1 1 1 10 이렇게 있으면 오류...
// 1부터 가장 긴 과자 길이 이분 탐색 mid --> (모든 과자를 mid로 나눈 몫의 합) >= 조카 수 조건을 만족하는 mid의 최댓값 갱신

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<int> snack(n);
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        cin >> snack[i];
        if (snack[i] > max_len) {
            max_len = snack[i];
        }
    }

    int left = 1;
    int right = max_len;
    int answer = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        long long count = 0;
        
        for (int i = 0; i < n; i++) {
            count += snack[i] / mid;
        }

        if (count >= m) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << "\n";

    return 0;
}