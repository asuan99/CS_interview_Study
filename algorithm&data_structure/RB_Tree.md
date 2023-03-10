## 질문 2 : AVL트리와 RB트리의 대하여 비교하며 설명하시오.

- 자료조사
    
    ### 개념
    
    레드-블랙 트리는 자가 균형 이진 탐색 트리이다.
    
    - RB트리의 조건
        1. 모든 노드는 빨간색 혹은 검은색이다
        2. 루트 노드는 검은색이다.
        3. 모든 리프 노드(NIL)들은 검은색이다.
            1. NIL : 자료를 갖지 않고 트리의 끝을 나타내는 노드
        4. 빨간색 노드의 자식은 검은색이다.
            1. 빨간색 노드가 연속으로 나올 수 없다.
        5. 모든 리프 노드에서 Black Depth는 같다.
            1. 리프노드에서 루트 노드까지 가는 경로에서 만나는 검은색 노드의 개수가 같다.
    
    ### RB 트리 삽입 과정
        - RB트리에 새로운 노드를 삽입할 때 새로운 노드는 항상 빨간색으로 삽입한다.
    - Double Red 상황이 발생한다.
        - Double Red 문제를 해결하기 위한 2가지 전략
            - 삼촌 노드가 검은색 → Restructuring
            - 삼촌 노드가 빨간색 → Recoloring
    ### Restructuring

    - 과정
        1. 새로운 노드(N), 부모 노드(P), 조상 노드(G)를 오름차순으로 정렬한다.
        2. 셋 중 중간값을 부모로 만들고 나머지 둘을 자식으로 만든다
        3. 새로 부모가 된 노드를 검은색으로 만들고 나머지 자식들을 빨간색으로 만든다.

    - 삼촌 노드가 검은색이다. 따라서 Restructuring을 수행한다.
    - 새로운 노드 N과 부모 P, 조상 G를 오름차순으로 정렬한다. 그러면 3이 중간값이 된다.
    - 중간값인 3을 부모노드로 바꾸고 나머지 2와 5를 자식 노드로 바꾼다
    - 원래 5의 자식 노드였던 7은 딸려가게 된다.
    - 새롭게 부모가 된 3을 검은색으로 바꿔주고 나머지 두 자식인 2, 5의 색을 빨간색으로 바꿔주면 Double Red 문제가 해결된다
    - NIL은 검은색 노드만 지칭 → 조건 3만족
    
    ### Recoloring

    - 과정
        1. 새로운 노드(N)의 부모(P)와 삼촌(U)을 검은색으로 바꾸고 조상(G)을 빨간색으로 바꾼다
            - 조상이 루트 노드라면 검은색으로 바꾼다
            - 조상을 빨간색으로 바꿨을 때 또다시 DR이 발생하면 Restructuring 혹은 Recoloring을 상황에 따라 사용하여 DR을 해결
        - DR이 발생했는데 삼촌 노드가 빨간색 → Recoloring 수행
        - 부모와 삼촌을 검은색으로 바꾸고 조상을 빨간색으로 바꾼다
        - 루트 노드는 검은색이여야 하니 루트노드를 검은색으로 바꾼다.
        - 검은색 노드는 2번 나와도 ㄱㅊ

    ### AVL트리와 RB트리의 차이

        - AVL 트리는 균형을 엄격하게 유지하는데, red-black tree는 색상이 추가되어 여유롭게 균형을 유지하기 때문에 AVL 트리에 비하여 삽입, 삭제가 빠르다.
        - 둘다 self-balancing트리인 것은 같다, 즉 삽일할 때 리밸런싱해야 하는 것은 같다 하지만 그 과정이 다르다.
        - 리밸런싱 과정 비교
            - AVL트리
                - 삽입할때 무조건 페런트 노드를 차례대로 하나씩 비교하여 리밸런싱 하는 과정이 포함되기 때문에 평균, 최악의 경우 둘다 O(log n)의 시간복잡도를 지닌다.
            - RB트리
                - color가 추가 되었기 때문에 무조건 트리를 회전하는 것이 아니라 색깔만 바꾸는 등의 방법으로 좀 더 느슨하게 리밸런싱 하므로 트리 회전 횟수가 감소된다.
                - 삽입, 삭제할때의 시간복잡도에서 차이를 보이게 되는데, 두 트리 다 O(logN)의 복잡도를 가지지만 RB트리는 삽입 한번당 관점에서 보면 실제로 구현할때는 2-3트리와 같이 색상 포인터만 바꿔 시간복잡도가 O(1) 경우도 있고, AVL트리와 같이 재귀를 무조건 사용하지 않아 CPU의 오버헤드가 적기 때문에 일반적으로 선호된다.



- 답안
    
    AVL 트리와 RB 트리는 모두 이진 검색 트리의 일종으로, 데이터를 탐색하고 삽입 및 삭제할 때 사용됩니다. AVL 트리는 균형 잡힌 트리로 높이 차이가 1을 넘지 않는 특징이 있으며, RB 트리는 레드 블랙 트리로, 모든 노드가 빨간색 또는 검은색이며 일정한 규칙을 따릅니다. AVL 트리는 검색 속도가 빠르지만, 삽입, 삭제에 있어서는 느리고 구현이 복잡합니다. 반면 RB 트리는 삽입, 삭제가 빠르고 구현이 간단하지만 검색 속도가 상대적으로 느립니다.
    
    - 즉 두 트리 모두 삽입, 삭제, 검색시 O(log N)의 시간이 소요되는건 똑같다. 하지만 AVL트리는 밸런스가 좀 더 엄격하게 유지되기 때문에 탐색에 유리하고 RB트리는 탐색에는 불리하지만 그만큼 삽입과 삭제에 유리하다.                


-reference
[알고리즘] Red Black tree그리고 avl tree와의 비교 https://ebongzzang.github.io/algorithm/Red-Black-tree-%EA%B7%B8%EB%A6%AC%EA%B3%A0-AVL-tree%EC%99%80%EC%9D%98-%EB%B9%84%EA%B5%90/