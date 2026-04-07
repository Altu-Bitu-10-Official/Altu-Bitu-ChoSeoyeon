/*
수빈이는 동생 N명과 숨바꼭질을 하고 있다. 수빈이는 현재 점 S에 있고, 동생은 A1, A2, ..., AN에 있다.
수빈이는 걸어서 이동을 할 수 있다. 수빈이의 위치가 X일때 걷는다면 1초 후에 X+D나 X-D로 이동할 수 있다. 수빈이의 위치가 동생이 있는 위치와 같으면, 동생을 찾았다고 한다.
모든 동생을 찾기위해 D의 값을 정하려고 한다. 가능한 D의 최댓값을 구해보자.

첫째 줄에 N(1 ≤ N ≤ 105)과 S(1 ≤ S ≤ 109)가 주어진다. 둘째 줄에 동생의 위치 Ai(1 ≤ Ai ≤ 109)가 주어진다. 동생의 위치는 모두 다르며, 수빈이의 위치와 같지 않다.
가능한 D값의 최댓값을 출력한다.
*/

// 수빈이와 동생들의 거리를 각각 구하고 > 최대공약수 구하기

#include <iostream>
#include <vector>

using namespace std;

int gcdIter(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> brothers(n);
    for (int i=0; i<n; i++) {
        cin >> brothers[i];
    }
    
    for (int i=0; i<n; i++) {
        int distance;
        distance = s - brothers[i];
        distance = distance > 0 ? distance : -distance;
        brothers[i] = distance;
    }

    for (int i=0; i<n-1; i++) {
        int k = 0;
        k = gcdIter(brothers[i], brothers[i+1]);
        brothers[i+1] = k;
    }

    cout << brothers[n-1] << '\n';
}