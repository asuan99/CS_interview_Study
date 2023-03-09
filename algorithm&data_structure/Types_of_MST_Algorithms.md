# MST 알고리즘

# MST가 무엇이며 MST를 찾는 알고리즘에는 어떤것이 있나요

- Spanning Tree
    
    ![Untitled](MST%20%E1%84%8B%E1%85%A1%E1%86%AF%E1%84%80%E1%85%A9%E1%84%85%E1%85%B5%E1%84%8C%E1%85%B3%E1%86%B7%20bc78c99b2f634199b0e324833d136399/Untitled.png)
    
    - 그래프 내의 모든 정점을 포함하는 트리, 최소 연결 부분 그래프
- MST (Minimum Cost Spannig Tree) : 최소 비용 신장 트리
    
    ![Untitled](MST%20%E1%84%8B%E1%85%A1%E1%86%AF%E1%84%80%E1%85%A9%E1%84%85%E1%85%B5%E1%84%8C%E1%85%B3%E1%86%B7%20bc78c99b2f634199b0e324833d136399/Untitled%201.png)
    
    - 무방향 가중치 그래프에서 신장 트리를 구성하는 간선들의 가중치 합이 최소인 신장트리
    - 모든 정점을 가장 적은 수의 간선과 비용으로 연결하는 것
- Kruskal MST
    - 탐욕적인 방법(Greedy method)를 이용하여 모든 정점을 최소 비용으로 연결하여 최적 해답을 구하는 것
        - 탐욕적인 방법
            - 결정을 해야 할 때마다 그 순간에 가장 좋다고 생각되는 것을 선택함으로써 최종적인 해답에 도달하는 것
            - 그 순간에는 최적이지만 전체적인 관점에서는 최적이라는 보장이 없으므로 검증이 필요
    - Kruskal 알고리즘의 동작 과정
        
        ![Untitled](MST%20%E1%84%8B%E1%85%A1%E1%86%AF%E1%84%80%E1%85%A9%E1%84%85%E1%85%B5%E1%84%8C%E1%85%B3%E1%86%B7%20bc78c99b2f634199b0e324833d136399/Untitled%202.png)
        
        1. 그래프의 간선들을 가중치의 오름차순으로 정렬
        2. 사이클을 형성하지 않는 간선을 선택
            - 가장 낮은 가중치 먼저 선택
            - 사이클을 형성하는 간선은 제외
        3. 선택된 간선을 MST의 집합에 추가
        
        <aside>
        💡 사이클 생성 여부를 확인하는 방법?
        
        - Union-find 알고리즘 이용!
        </aside>
        
- Prim
    - 시작 정점에서부터 출발하여 신장트리 집합을 단계적으로 확장해나가는 방법
    - Prim 알고리즘의 동작 과정
        
        ![Untitled](MST%20%E1%84%8B%E1%85%A1%E1%86%AF%E1%84%80%E1%85%A9%E1%84%85%E1%85%B5%E1%84%8C%E1%85%B3%E1%86%B7%20bc78c99b2f634199b0e324833d136399/Untitled%203.png)
        
        - 정점 선택을 기반으로 하는 알고리즘
        - 이전 단계에서 만들어진 신장 트리를 확장하는 방법
    
- 답안
    
    MST는 최소 비용 신장 트리로 가장 적은 수의 간선과 가중치 합이 최소인 신장트리이며 MST를 찾는 알고리즘에는 Kruskal 과 Prim 알고리즘이 있다.
    
- 질문
    1. 각 알고리즘이 어떤 그래프에서 사용되나요?
        - 적은 숫자의 간선을 가지는 희소 그래프의 경우 Kruskal 이 적합하고, 간선이 많이 존재하는 밀집 그래프의 경우 Prim 알고리즘이 적합하다.
    2. Union-find 함수를 간단하게 설명해주세요
        - 정점을 집합에 추가할 때 사이클을 형성하는 간선인지를 Find 함수로 판단하고, 해당 간선이 MST 집합에 추가할 때 Union 함수를 사용한다.
- 참고자료
    
    [[알고리즘] 최소 신장 트리(MST, Minimum Spanning Tree)란 - Heee's Development Blog](https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html)
    
    [[알고리즘] Kruskal 알고리즘 이란 - Heee's Development Blog](https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html)
    
    [[알고리즘] Prim 알고리즘 이란 - Heee's Development Blog](https://gmlwjd9405.github.io/2018/08/30/algorithm-prim-mst.html)