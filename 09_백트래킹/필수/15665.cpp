/*
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
- N개의 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 된다.
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/

#include <iostream>
#include <vector>

using namespace std;

void backtrakcing(int n, int m, int idx, vector<int> &sequence, vector<int> &nums) {
    if (idx == m) {
        for (auto x : sequence) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=0; i<nums.size(); i++) {
        sequence[idx] = nums[i];

        backtrakcing(n, m, idx + 1, sequence, nums);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> sequence(m, -1);
    vector<int> input_nums(n);
    for (int i=0; i<n; i++) {
        cin >> input_nums[i];
    }

    sort(input_nums.begin(), input_nums.end());

    vector<int> nums;
    nums.push_back(input_nums[0]);

    for (int i=1; i<n; i++) {
        if (input_nums[i] != input_nums[i-1]) {
            nums.push_back(input_nums[i]);
        }
    }

    backtrakcing(n, m, 0, sequence, nums);
}