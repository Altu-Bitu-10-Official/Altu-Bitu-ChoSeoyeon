/*
다솜이는 기타를 많이 가지고 있다. 그리고 각각의 기타는 모두 다른 시리얼 번호를 가지고 있다. 다솜이는 기타를 빨리 찾아서 빨리 사람들에게 연주해주기 위해서 기타를 시리얼 번호 순서대로 정렬하고자 한다.

모든 시리얼 번호는 알파벳 대문자 (A-Z)와 숫자 (0-9)로 이루어져 있다.

시리얼번호 A가 시리얼번호 B의 앞에 오는 경우는 다음과 같다.

A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
시리얼이 주어졌을 때, 정렬해서 출력하는 프로그램을 작성하시오.

첫째 줄에 기타의 개수 N이 주어진다. N은 50보다 작거나 같다. 둘째 줄부터 N개의 줄에 시리얼 번호가 하나씩 주어진다. 시리얼 번호의 길이는 최대 50이고, 알파벳 대문자 또는 숫자로만 이루어져 있다. 시리얼 번호는 중복되지 않는다.
*/

// AB compare 함수, 자리수 합 함수, 정렬 함수

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// 자리수 합 함수
int sumNum(string s0) {
    int sum = 0;
    for (int i=0; i<s0.size(); i++) {
        if(isdigit(s0[i])) {
            sum += s0[i] - '0';
        }
    }
    return sum;
}

// AB compare 함수
bool cmpAB(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size(); // 짧은 것이 먼저
    }
    if (sumNum(s1) != sumNum(s2)) {
        return sumNum(s1) < sumNum(s2); // 작은 합 먼저
    }
    return s1 < s2; // 사전순
}

int main() {
    int N;
    cin >> N;

    vector<string> guitar(N);
    
    // 입력
    for (int i=0; i<N; i++) {
        cin >> guitar[i];
    }
    // 정렬
    sort(guitar.begin(), guitar.end(), cmpAB);
    // 출력
    for (string g : guitar) {
        cout << g << endl;
    }
    return 0;
}