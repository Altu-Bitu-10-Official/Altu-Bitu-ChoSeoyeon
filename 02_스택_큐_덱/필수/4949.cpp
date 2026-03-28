/*
세계는 균형이 잘 잡혀있어야 한다. 양과 음, 빛과 어둠 그리고 왼쪽 괄호와 오른쪽 괄호처럼 말이다.
정민이의 임무는 어떤 문자열이 주어졌을 때, 괄호들의 균형이 잘 맞춰져 있는지 판단하는 프로그램을 짜는 것이다.
문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고, 문자열이 균형을 이루는 조건은 아래와 같다.

모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.

정민이를 도와 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를 판단해보자.

각 문자열은 마지막 글자를 제외하고 영문 알파벳, 공백, 소괄호("( )"), 대괄호("[ ]")로 이루어져 있으며, 온점(".")으로 끝나고, 길이는 100글자보다 작거나 같다.
입력의 종료조건으로 맨 마지막에 온점 하나(".")가 들어온다.
각 줄마다 해당 문자열이 균형을 이루고 있으면 "yes"를, 아니면 "no"를 출력한다.
*/

// cin cout으로 입출력 불가능 > 띄어쓰기까지 포함해서 문자열을 입력받으려면? >> cin.getline(저장변수, 저장원하는개수-1=실제원하는문자수)
// 스택 사용

#include <iostream>
#include <stack>

using namespace std;

int check_balance(char* ch) {
    stack<char> s;
    for (int i=0; ch[i]!='\0'; i++) {    
        if (ch[0]=='.') break;
        switch (ch[i]) {
            case '(':
            case '[':
            case '{':
                s.push(ch[i]);
                break;
            case ')':
            case ']':
            case '}':
                if (s.empty()) return 0;
                else {
                    char st_Top = s.top();
                    s.pop();
                    if ((st_Top == '(' && ch[i] != ')') ||
                        (st_Top == '[' && ch[i] != ']') ||
                        (st_Top == '{' && ch[i] != '}')) {
                        return 0;
                    } break;
                }
        }
    }
    return s.empty() ? 1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    char ch[200];
    while (cin.getline(ch, 200)) {
        if (ch[0] == '.') break;

        if (check_balance(ch) == 1) cout << "yes\n";
        else cout << "no\n";
    }
}