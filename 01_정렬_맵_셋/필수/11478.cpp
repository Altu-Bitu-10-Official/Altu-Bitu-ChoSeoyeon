/*
문자열 S가 주어졌을 때, S의 서로 다른 부분 문자열의 개수를 구하는 프로그램을 작성하시오.
부분 문자열은 S에서 연속된 일부분을 말하며, 길이가 1보다 크거나 같아야 한다.
예를 들어, ababc의 부분 문자열은 a, b, a, b, c, ab, ba, ab, bc, aba, bab, abc, abab, babc, ababc가 있고, 서로 다른것의 개수는 12개이다.

첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 1,000 이하이다.

첫째 줄에 S의 서로 다른 부분 문자열의 개수를 출력한다.
*/

// for문 안에서 substr 함수로 string 잘라서 str에 저장

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string S;
    cin >> S;

    unordered_set<string> us;

    for (int i=0; i<S.size(); i++) {
        for (int j=1; i+j<=S.size(); j++) {
            string s1 = S.substr(i, j);
            us.insert(s1);
        }
    }

    cout << us.size() << endl;

    return 0;
}