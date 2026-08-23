/*
간선에 가중치와 방향성이 없는 임의의 루트 있는 트리가 주어졌을 때, 아래의 쿼리에 답해보도록 하자.
    - 정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력한다.
만약 이 문제를 해결하는 데에 어려움이 있다면, 하단의 힌트에 첨부한 문서를 참고하자.

트리의 정점의 수 N과 루트의 번호 R, 쿼리의 수 Q가 주어진다. $(2 ≤ N ≤ 10^5, 1 ≤ R ≤ N, 1 ≤ Q ≤ 10^5)$
이어 N-1줄에 걸쳐, U V의 형태로 트리에 속한 간선의 정보가 주어진다. (1 ≤ U, V ≤ N, U ≠ V)
이는 U와 V를 양 끝점으로 하는 간선이 트리에 속함을 의미한다.
이어 Q줄에 걸쳐, 문제에 설명한 U가 하나씩 주어진다. (1 ≤ U ≤ N)
입력으로 주어지는 트리는 항상 올바른 트리임이 보장된다.

Q줄에 걸쳐 각 쿼리의 답을 정수 하나로 출력한다.
*/

// DFS와 dp 사용하기
// 양방향 간선 연결 / 서브트리 크기 누적

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001; 
vector<int> adj[MAX];
int tree_size[MAX];
bool visited[MAX];

void countSubtree(int current) {
    visited[current] = true;
    tree_size[current] = 1;

    for (int next : adj[current]) {
        if (!visited[next]) {
            countSubtree(next);
            tree_size[current] += tree_size[next];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    countSubtree(r);

    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << tree_size[u] << "\n";
    }
}