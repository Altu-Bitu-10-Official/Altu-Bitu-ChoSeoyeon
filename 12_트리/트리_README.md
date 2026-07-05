# Tree
비선형 자료구조
그래프의 부분집합으로 사이클이 없고, V개의 정점에 대해 V-1개의 간선이 있음
부모-자식의 계층 구조
트리 탐색의 시간 복잡도는 O(h) (h = 트리의 높이)
그래프와 마찬가지로 DFS, BFS를 이용하여 탐색

용어
    Root: 부모 정점이 없는 정점
    Subtree: 트리의 부분 집합
    Leaf node: 자식 정점이 없는 정점 (4, 5, 6번 정점)
    Level: 트리의 각 계층
    Depth: 자신을 제외한 조상 노드의 개수
    Height: 노드의 Height - 해당 노드의 자식의 height중 가장 높은 값+1
            트리의 Height – 루트노드의 height
    
    Binary Tree (이진 트리): 자식 정점의 수가 2개 이하
    General Tree (일반 트리): 자식 정점의 수에 제한 없음
    
    Perfect Binary Tree (포화 이진 트리)
    Complete Binary Tree (완전 이진 트리)


구조체 + 포인터
    실시간으로 트리를 만들어야 할 때 적합

맵
    이미 트리 관계가 정의되어 있을 때 적합
    정점 번호가 연속하지 않을 때 적합

2차원 벡터
    정점 번호가 연속할 때 적합

순회
    레벨 순회 (Level traversal)
    전위 순회 (Preorder traversal)
    중위 순회 (Inorder traversal)
    후위 순회 (Postorder traversal)

정리
    그래프의 부분집합인 트리
    그래프와 트리의 차이점을 잘 기억해두기
    이진 트리와 일반 트리로 나눌 수 있고, 이진 트리는 전위 & 중위 & 후위 순회 가능
    기본적으로 그래프의 한 종류라서 DFS, BFS 탐색 가능

