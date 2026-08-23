/*
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 n이 주어진다. (1≤n≤1000)
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10007로 나눈 나머지를 출력한다.
*/

// if n짝수 --> 세로 줄 짝수개인 경우 확인; // n홀수 --> 세로 줄 홀수개인 경우 체크
// n=1 --> 1; n=2 --> 2; n=3 --> 3; n=4 --> 5; n=5 --> 8; ... 피보나치...

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, 0);

    if (n >= 2) {
        dp[1] = 1;
        dp[2] = 2;
    } else dp[1] = 1;
    
    for (int i=3; i<=n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n] << endl;
}