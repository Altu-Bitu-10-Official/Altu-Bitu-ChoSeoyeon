/*
8*8크기의 체스판에 왕이 하나 있다. 킹의 현재 위치가 주어진다. 체스판에서 말의 위치는 다음과 같이 주어진다. 알파벳 하나와 숫자 하나로 이루어져 있는데, 알파벳은 열을 상징하고, 숫자는 행을 상징한다. 열은 가장 왼쪽 열이 A이고, 가장 오른쪽 열이 H까지 이고, 행은 가장 아래가 1이고 가장 위가 8이다. 예를 들어, 왼쪽 아래 코너는 A1이고, 그 오른쪽 칸은 B1이다.
킹은 다음과 같이 움직일 수 있다.

R : 한 칸 오른쪽으로
L : 한 칸 왼쪽으로
B : 한 칸 아래로
T : 한 칸 위로
RT : 오른쪽 위 대각선으로
LT : 왼쪽 위 대각선으로
RB : 오른쪽 아래 대각선으로
LB : 왼쪽 아래 대각선으로
체스판에는 돌이 하나 있는데, 돌과 같은 곳으로 이동할 때는, 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킨다. 아래 그림을 참고하자.

입력으로 킹이 어떻게 움직여야 하는지 주어진다. 입력으로 주어진 대로 움직여서 킹이나 돌이 체스판 밖으로 나갈 경우에는 그 이동은 건너 뛰고 다음 이동을 한다.
킹과 돌의 마지막 위치를 구하는 프로그램을 작성하시오.

첫째 줄에 킹의 위치, 돌의 위치, 움직이는 횟수 N이 주어진다. 둘째 줄부터 N개의 줄에는 킹이 어떻게 움직여야 하는지 주어진다. N은 50보다 작거나 같은 자연수이고, 움직이는 정보는 위에 쓰여 있는 8가지 중 하나이다.
첫째 줄에 킹의 마지막 위치, 둘째 줄에 돌의 마지막 위치를 출력한다.
*/

// str.contains("RLBT") 사용 -> contains는 C++ 23버전?부터 가능해서 str.find != std::string::npos로 변경
// 킹 이동 -> 돌과 킹이 같은 곳에 있는지 확인 -> 같은 곳이라면 돌 이동 / 이동 후 위치가 체스판 내부인지 확인
// 저장 변수를 따로 만들어서 if 먼저 킹 움직여보고 그 범위를 체크해서 범위 안에 들어가면 저장변수에 move 결과 저장

#include <iostream>

using namespace std;

pair<int, int> stone;
pair<int, int> king;

void move(string str, pair<int, int> &p1) {
    if (str.find("R") != std::string::npos) {
        p1.first += 1;
    }
    if (str.find("L") != std::string::npos) {
        p1.first -= 1;
    }
    if (str.find("B") != std::string::npos) {
        p1.second -= 1;
    }
    if (str.find("T") != std::string::npos) {
        p1.second += 1;
    }
}


void checkStone(string str, pair<int, int> &p1, pair<int, int> &p2) { // p1이 stone, p2가 king
    if (p1.first == p2.first && p1.second == p2.second) { // king이랑 stone 위치가 겹치면
        move(str, p1); // stone을 똑같이 이동
    }
}

bool checkRange(pair<int, int> &p1) {
    if ( 1 > p1.first || p1.first > 8 || 1 > p1.second || p1.second > 8) { // 체스판을 벗어난다면
        //cout << p1.first << " " << p1.second << endl;
        return false;
    }
    return true;
}

int main() {
    string k, s;
    int n;

    cin >> k >> s >> n;

    king.first = k[0] - 'A' + 1;
    king.second = k[1] - '0';

    stone.first = s[0] - 'A' + 1;
    stone.second = s[1] - '0';

    while (n--) {
        string str;
        cin >> str;

        pair<int, int> current_king = king;
        pair<int, int> current_stone = stone;

        // king을 먼저 이동
        move(str, king);
        // stone이랑 겹치는지 확인하고 이동
        //cout << "king "<< char(king.first + 'A') << king.second << endl;
        //cout << "stone "<< char(stone.first + 'A') << stone.second << endl;
        checkStone(str, stone, king);
        // 체스판 안에 있는지 확인하고 없으면 current로 초기화
        if (!checkRange(stone) || !checkRange(king)) {
            king = current_king;
            stone = current_stone;
            //cout << char(king.first + 'A') << king.second << endl;
            //cout << char(stone.first + 'A') << stone.second << endl;
        }
    }

    cout << char(king.first + 'A' - 1) << king.second << endl;
    cout << char(stone.first + 'A' - 1) << stone.second << endl;

}