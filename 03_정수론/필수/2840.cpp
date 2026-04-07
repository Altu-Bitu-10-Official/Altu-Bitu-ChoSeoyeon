/*
바퀴에 같은 글자는 두 번 이상 등장하지 않는다. 또, 바퀴는 시계방향으로만 돌아간다. 바퀴 옆에는 화살표가 있는데, 이 화살표는 항상 한 곳을 가리키고 있으며, 돌아가는 동안 가리키는 글자는 바뀌게 된다. 위의 그림에서는 H를 가리키고 있다.
상덕이는 바퀴를 연속해서 K번 돌릴 것이다. 매번 바퀴를 돌릴 때 마다, 상덕이는 화살표가 가리키는 글자가 변하는 횟수와 어떤 글자에서 회전을 멈추었는지를 종이에 적는다.
희원이는 상덕이가 적어놓은 종이를 발견했다. 그 종이를 바탕으로 상덕이가 바퀴에 적은 알파벳을 알아내려고 한다.
상덕이가 종이에 적어놓은 내용과 바퀴의 칸의 수가 주어졌을 때, 바퀴에 적어놓은 알파벳을 알아내는 프로그램을 작성하시오.

첫째 줄에 바퀴의 칸의 수 N과 상덕이가 바퀴를 돌리는 횟수 K가 주어진다. (2 ≤ N ≤ 25, 1 ≤ K ≤ 100)
다음 줄부터 K줄에는 바퀴를 회전시켰을 때 화살표가 가리키는 글자가 몇 번 바뀌었는지를 나타내는 S와 회전을 멈추었을 때 가리키던 글자가 주어진다. (1 ≤ S ≤ 100)
첫째 줄에 마지막 회전에서 화살표가 가리키는 문자부터 시계방향으로 바퀴에 적어놓은 알파벳을 출력한다. 이때, 어떤 글자인지 결정하지 못하는 칸은 '?'를 출력한다. 만약, 상덕이가 적어놓은 종이에 해당하는 행운의 바퀴가 없다면 "!"를 출력한다. 
*/

// 원형큐 쓰기??? 아니다 굳이인듯 걍 배열로 ㄱㄱ

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<char> wheel(n, '?');
    vector<bool> alphabet_used(26, false); 
    int sum = 0;
    bool ok = true;

    for (int i=0; i<k; i++) {
        int s;
        char ch;
        cin >> s >> ch;
        sum = (sum + s) % n;

        if (wheel[sum] == '?') {
            if (!alphabet_used[ch - 'A']) {
                wheel[sum] = ch;
                alphabet_used[ch - 'A'] = true;
            } else {
                ok = false;
                break;
            }
        } else if (wheel[sum] != ch){
            ok = false;
            break;
        }
    }
    
    if (!ok) {
        cout << "!" << '\n';
    } else {
        for (int i = 0; i < n; i++) {
            cout << wheel[(sum - i + n) % n];
        }
        cout << "\n";
    }
}