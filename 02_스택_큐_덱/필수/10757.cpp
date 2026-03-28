/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
첫째 줄에 A와 B가 주어진다. (0 < A,B < 10^10000)
첫째 줄에 A+B를 출력한다.
*/

// long long 2^63-1, 약 19자리(9.22 * 10^18)
// 스택 사용 > 맨 마지막에 들어온 일의자리수부터 더하고 자리올림
// >> 스택보다 벡터/문자열을 이용하는게 나을거라는 피드백으로 로직 수정

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    /*stack<int> A;
    stack<int> B;
    stack<int> R;
    stack<int> Carry;

    int x, y;

    while (cin >> x) {
        A.push(x);
        if (cin.peek() == ' ') break;
    }

    while (cin >> y) {
        B.push(y);
        if (cin.peek() == '\n') break;
    }

    while (!A.empty() || !B.empty()) {
        int a, b, r;
        a = A.top(), b = B.top();
        r = (a+b)%10;
        if (a+b > 9) {
            Carry.push(((a+b)/10));
        }
        if (!Carry.empty()) {
            R.push(r+Carry.top());
        } else R.push(r);
        A.pop();
        B.pop();
        Carry.pop();
    }

    if (A.empty()) {
        while (!B.empty()) {
            int b = B.top();
            if (!Carry.empty()) {
                R.push(b + Carry.top());
            } else R.push(b);
        }
    } else if (B.empty()) {
        while (!A.empty()) {
            int a = A.top();
            if (!Carry.empty()) {
                R.push(a + Carry.top());
            } else R.push(a);
        }
    } else {
        
    }*/

    vector<int> A;
    vector<int> B;
    int carry = 0;
    stack<int> R;
    string s1, s2;
    cin >> s1 >> s2;

    for (int i=s1.length()-1; i>=0; i--) {
        A.push_back(s1[i] - '0');
    }

    for (int j=s2.length()-1; j>=0; j--) {
        B.push_back(s2[j] - '0');
    }

    int k = 0;
    while (A.size() > k || B.size() > k || carry) {
        int sum = carry;
        if (k<A.size()) sum += A[k];
        if (k<B.size()) sum += B[k];

        R.push(sum % 10);
        carry = sum / 10;
        k++;
    }

    while (!R.empty()) {
        cout << R.top();
        R.pop();
    }
    cout << endl;
}