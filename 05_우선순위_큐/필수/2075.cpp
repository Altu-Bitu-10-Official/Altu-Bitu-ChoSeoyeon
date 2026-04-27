/*
N×N의 표에 수 N2개 채워져 있다. 채워진 수에는 한 가지 특징이 있는데, 모든 수는 자신의 한 칸 위에 있는 수보다 크다는 것이다. N=5일 때의 예를 보자.
이러한 표가 주어졌을 때, N번째 큰 수를 찾는 프로그램을 작성하시오. 표에 채워진 수는 모두 다르다.

첫째 줄에 N(1 ≤ N ≤ 1,500)이 주어진다. 다음 N개의 줄에는 각 줄마다 N개의 수가 주어진다. 표에 적힌 수는 -10억보다 크거나 같고, 10억보다 작거나 같은 정수이다.
첫째 줄에 N번째 큰 수를 출력한다.
*/

// 최대힙 썻더니 메모리 초과....... 최소힙 써서 개수 제한하고 top 출력

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> num;
    int n;
    cin >> n;

    int n1 = n*n;
    while (n1--) {
        int x;
        cin >> x;
        
        if (num.size() < n) {
            num.push(x);
        } else {
            if (x > num.top()) {
                num.pop();
                num.push(x);
            } else continue;
        }
    }    
    cout << num.top() << endl;
}