/*
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다. 두 숫자 카드에 같은 수가 적혀있는 경우는 없다.
셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.
*/

// 이분탐색 사용해서 출력

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int key, vector<int> &nums) {
    int left = 0;
    int right = n-1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == key) return 1;
        else if (nums[mid] > key) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> card;

    for (int i=0; i<n; i++) {
        int input;
        cin >> input;
        card.push_back(input);
    }

    cin >> m;
    vector<int> num;
    for (int i=0; i<m; i++) {
        int input;
        cin >> input;
        num.push_back(input);
    }

    sort(card.begin(), card.end());
    
    for (int i=0; i<m; i++) {
        cout << binarySearch(n, num[i], card) << " ";
    }
    cout << "\n";
}