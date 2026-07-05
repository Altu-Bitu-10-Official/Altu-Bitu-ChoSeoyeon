/*
이진 검색 트리는 다음과 같은 세 가지 조건을 만족하는 이진 트리이다.
    - 노드의 왼쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 작다.
    - 노드의 오른쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 크다.
    - 왼쪽, 오른쪽 서브트리도 이진 검색 트리이다
전위 순회 (루트-왼쪽-오른쪽)은 루트를 방문하고, 왼쪽 서브트리, 오른쪽 서브 트리를 순서대로 방문하면서 노드의 키를 출력한다. 후위 순회 (왼쪽-오른쪽-루트)는 왼쪽 서브트리, 오른쪽 서브트리, 루트 노드 순서대로 키를 출력한다. 예를 들어, 위의 이진 검색 트리의 전위 순회 결과는 50 30 24 5 28 45 98 52 60 이고, 후위 순회 결과는 5 28 24 45 30 60 52 98 50 이다.
이진 검색 트리를 전위 순회한 결과가 주어졌을 때, 이 트리를 후위 순회한 결과를 구하는 프로그램을 작성하시오.

트리를 전위 순회한 결과가 주어진다. 노드에 들어있는 키의 값은 10^6보다 작은 양의 정수이다. 모든 값은 한 줄에 하나씩 주어지며, 노드의 수는 10,000개 이하이다. 같은 키를 가지는 노드는 없다.

입력으로 주어진 이진 검색 트리를 후위 순회한 결과를 한 줄에 하나씩 출력한다.
*/

// 우선 입력값을 받아 트리를 만들고, postorder로 순회 --> 계속 출력값이 안나와서 제미나이한테 물어봤더니 cin >> num이 끝나는 지점을 vscode가 알 수 없어서 입력값 복붙 후 ctrl+D를 해야 출력값 나옴

#include <iostream>

using namespace std;

struct Node {
    int left = 0;
    int right = 0;
};

Node tree[1000000];
int rootNode = 0;

void insertNode(int current, int val) {
    if (val < current) {
        if (tree[current].left == 0) tree[current].left = val;
        else insertNode(tree[current].left, val);
    } else {
        if (tree[current].right == 0) tree[current].right = val;
        else insertNode(tree[current].right, val);
    }
}

void postorder(int v) {
    if (v == 0) return;

    postorder(tree[v].left);
    postorder(tree[v].right);
    cout << v << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int num;
    while (cin >> num) {
        if (rootNode == 0) {
            rootNode = num;
        } else {
            insertNode(rootNode, num);
        }
    }

    postorder(rootNode);
}