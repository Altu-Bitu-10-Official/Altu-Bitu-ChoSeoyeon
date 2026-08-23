/*
1. 도도와 수연이는 각각 N장의 카드로 이루어진 덱을 배분받는다. 게임 시작 시 그라운드는 비어있는 상태이다.
    - 덱은 숫자가 보이지 않게 카드를 뒤집어 쌓아 놓은 카드 더미를 의미한다. 도도와 수연이는 자신의 덱을 가지고 게임을 진행하게 된다.
    - 그라운드는 카드를 내려놓게 되는 땅을 의미한다. 그라운드에 카드를 내려놓을 때는 자신의 그라운드에 카드를 내려놓으며, 그라운드에 카드 더미가 존재할 경우 카드 더미 위에 카드를 내려놓는 방식으로 게임을 진행한다.
2. 도도를 시작으로 도도와 수연이가 차례대로 자신이 가진 덱에서 가장 위에 위치한 카드를 그라운드에 숫자가 보이도록 내려놓는다.
3. 종을 치는 사람이 그라운드에 나와 있는 카드 더미를 모두 가져간다. 종을 치는 조건은 다음과 같다.
    - 그라운드에 나와 있는 각각의 카드 더미에서 가장 위에 위치한 카드의 숫자 합이 5가 되는 순간 수연이가 종을 친다. 단, 어느 쪽의 그라운드도 비어있으면 안된다.
    - 그라운드에 나와 있는 각각의 카드 더미 중 가장 위에 위치한 카드의 숫자가 5가 나오는 순간 도도가 종을 친다.
4. 종을 쳤다면, 상대방의 그라운드에 있는 카드 더미를 뒤집어 자신의 덱 아래로 그대로 합친 후 자신의 그라운드에 있는 카드 더미 역시 뒤집어 자신의 덱 아래로 그대로 가져와 합친다.
    - 종을 쳐서 그라운드에 있는 카드 더미를 가져가는 행위는 게임의 진행 순서에 영향을 미치지 않는다.
5. 한 명이 2-4번까지의 과정을 진행하는 것을 1번 진행한 것으로 보며 다음과 같은 방법으로 게임의 승패가 결정된다.
    - 게임 진행 도중 자신의 덱에 있는 카드의 수가 0개가 되면 상대방이 승리한 것으로 본다.
    - M번 진행한 후 자신의 덱에 더 많은 카드를 지닌 사람이 승리한다.
    - M번 진행 후 각자의 덱에 있는 카드의 개수가 같다면 비긴 것으로 본다.
게임을 M번 진행한 후 승리한 사람은 누구일까?

첫째 줄에는 도도와 수연이가 가지는 카드의 개수 N(1 <= N <= 30,000)과 게임 진행 횟수 M(1 <= M <= 2,500,000)이 주어진다.
둘째 줄부터 N개의 줄에는 띄어쓰기로 구분하여 도도와 수연이가 가진 덱의 맨 아래에 위치한 카드에 적혀 있는 수부터 맨 위에 위치한 카드에 적힌 수까지 차례대로 주어진다. (각각의 카드는 1 이상 5 이하의 자연수가 적혀있다.)
게임을 이긴 사람이 도도라면 do를 출력하고, 게임을 이긴 사람이 수연이라면 su를 출력한다. 무승부이면 dosu를 출력한다.
*/

// 덱 top == front, gnd top == front

#include <iostream>
#include <deque>

using namespace std;

void openCard(deque<int> &gnd, deque<int> &dq) {
    int a = dq.front();
    gnd.push_front(a);
    dq.pop_front();
}

void getCard(deque<int> &gnd, deque<int> &dq) {
    while (!gnd.empty()) {
        dq.push_back(gnd.back());
        gnd.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    deque<int> d;
    deque<int> s;

    while (n--) {
        // 덱 맨 아래 --> 맨 뒤에, 맨 위 --> 맨 앞
        int a, b;
        cin >> a >> b;
        d.push_front(a);
        s.push_front(b);
    }

    deque<int> gnd_do;
    deque<int> gnd_su;

    bool dodo = true;
    while (m--) {
        if (dodo) openCard(gnd_do, d);
        else openCard(gnd_su, s);

        if (d.empty() || s.empty()) break;
        
        int top_do = gnd_do.empty() ? 0 : gnd_do.front();
        int top_su = gnd_su.empty() ? 0 : gnd_su.front();

        // 도도 종
        if (top_do == 5 || top_su == 5) {
            getCard(gnd_su, d);
            getCard(gnd_do, d);
        } else if (top_do + top_su == 5 && !gnd_do.empty() && !gnd_su.empty()) { // 수연 종
            getCard(gnd_do, s);
            getCard(gnd_su, s);
        }
        
        dodo = !dodo;
    }

    if (d.size() > s.size()) cout << "do" << endl;
    else if (d.size() < s.size()) cout << "su" << endl;
    else cout << "dosu" << endl;
}