/*
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다.

첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.
둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.
check 연산이 주어질때마다, 결과를 출력한다.
*/

// 비트마스킹 사용해서 풀기!!

#include <iostream>

using namespace std;
int s = 0;

void operation(string str, int x) {
    if (str == "add") {
        s |= (1 << x);
    } 
    if (str == "remove") {
        s &= ~(1 << x);
    } 
    if (str == "check") {
        if (s & (1 << x)) { // x가 있을 때
            cout << 1 << '\n';
        } else cout << 0 << '\n';
    } 
    if (str == "toggle") {
        if (s & (1 << x)) { // x가 있을 때
            s &= ~(1 << x);
        } else s |= (1 << x);
    } 
    if (str == "all") {
        for (int i=0; i<21; i++) {
            s |= (1 << i);
        }
    } 
    if (str == "empty") {
        s = 0;
    }

}

int main() {
    // 안쓰니까 시간초과;;ㅠ
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;
    cin >> m;
    while (m--) {
        string str;
        int x;
        cin >> str;
        if (str == "all" || str == "empty") {
            operation(str, 0);
        } else {
            cin >> x;
            operation(str, x);
        }
    }

    return 0;
}