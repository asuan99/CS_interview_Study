# MST(Minimum Spanning Tree)에 대해서 설명해주세요.

- **자료 조사**
    - **신장 트리(Spanning Tree)**
        - 정의
            - 신장 트리(Spanning Tree)란, 그래프에서 모든 정점을 포함하면서 사이클을 포함하지 않는 부분 그래프를 말합니다.
        
        다음 그림은 무방향 그래프 G에서 생성된 신장 트리를 나타내는 그림입니다.
        
        ![[그림 1] 완전 그래프 G와 신장 트리 A, B, C](https://github.com/BangDori/CS_interview_Study/blob/main/algorithm%26data_structure/img/Spanning_Tree.png)
        
        [그림 1] 완전 그래프 G와 신장 트리 A, B, C
        
        그래프 A, B,C는 그래프 G의 모든 정점을 포함하면서, 사이클을 형성하지 않고 연결되어 있습니다. 신장 트리를 구성하는 방법에는 DFS와 BFS가 있습니다. 아래 예시를 통해 확인해보겠습니다.
        
        ![[그림 2] 그래프 G](https://github.com/BangDori/CS_interview_Study/blob/main/algorithm%26data_structure/img/Graph.png)
        
        [그림 2] 그래프 G
        
        - **깊이 우선 탐색(Depth First Search)의 동작 과정**
            
            ![[그림 3] 그래프 G에 대한 DFS 동작 과정](https://github.com/BangDori/CS_interview_Study/blob/main/algorithm%26data_structure/img/DFS_Mechanism.png) 
            
            [그림 3] 그래프 G에 대한 DFS 동작 과정
            
            - **코드**
                
                ```c
                #define FALSE 0 // 미방문
                #define TRUE 1 // 방문
                short int visited[MAX_VERTICES]; // 방문 check를 위한 함수
                
                void dfs(int v) {
                	struct node *w;
                	visited[v] = TRUE; // 방문한 노드 Chcek
                	****printf("%5d", v);
                	for (w = graph[v]; w; w = w->link)
                		if (!visited[w->vertex]) dfs(w->vertex);
                }
                ```
                
            
            DFS 순서: $v_0, v_1, v_3, v_7, v_4, v_5, v_2, v_6$
            
            ![[그림 4] 그래프 G에 대한 DFS 순서](https://github.com/BangDori/CS_interview_Study/blob/main/algorithm%26data_structure/img/DFS_Mechanism_Order.png)
            
            [그림 4] 그래프 G에 대한 DFS 순서
            
        - **너비 우선 탐색(Breadth First Search)의 동작 과정**
            
            ![[그림 5] 그래프 G에 대한 BFS 동작 과정](https://github.com/BangDori/CS_interview_Study/blob/main/algorithm%26data_structure/img/BFS_Mechanism.png)
            
            [그림 5] 그래프 G에 대한 BFS 동작 과정
            
            BFS 순서: $v_0, v_1, v_2, v_3, v_4, v_5, v_6, v_7$
            
            ![[그림 6] 그래프 G에 대한 BFS 순서](https://github.com/BangDori/CS_interview_Study/blob/main/algorithm%26data_structure/img/BFS_Mechanism_Order.png)
                        
            [그림 6] 그래프 G에 대한 BFS 순서
            
    - **최소 신장 트리(Minimum Spanning Tree)**
        - 정의
            - 최소 비용 신장 트리(Minimum Cost Spanning Tree, MCST)는 그래프의 모든 정점을 포함하는 신장 트리 중에서, 간선의 가중치 합이 최소인 신장 트리를 의미합니다.
        
        - 사용 사례
            1. 도로 건설
                - 도시들을 모두 연결하면서 도로의 길이가 최소가 되도록 하는 문제
            2. 전기 회로
                - 단자들을 모두 연결하면서 전선의 길이가 가장 최소가 되도록 하는 문제
            3. 통신
                - 전화선의 길이가 최소가 되도록 전화 케이블 망을 구성하는 문제
            4. 배관
                - 파이프를 모두 연결하면서 파이프의 총 길이가 최소가 되도록 연결하는 문제
        
        [그림 1]에서 최소 신장 트리는 비용이 가장 작은 그래프 B인 것을 확인할 수 있습니다. 신장 비용 트리를 구성하는 알고리즘에는 대표적으로 두 가지가 존재합니다:
        
        1. 크루스칼 알고리즘(Kruskal Algorithm)
            - 그래프의 모든 간선을 가중치의 오름차순으로 정렬한 뒤, 가장 작은 가중치부터 선택합니다.
            - 선택한 간선이 사이클을 생성하지 않는다면, 해당 간선을 신장 트리에 포함시킵니다.
            - 선택된 간선의 수가 (정점의 개수 - 1)이 될 때까지 위 과정을 반복합니다.
            
            - **동작 과정**
                
                ![[그림 7] Kruskal Algorithm의 동작 과정](https://github.com/BangDori/CS_interview_Study/blob/main/algorithm%26data_structure/img/Kruskal_Algorithm.png)
                
                [그림 7] Kruskal Algorithm의 동작 과정
                
        2. 프림 알고리즘(Prim Algorithm)
            - 임의의 한 정점을 선택하고, 해당 정점과 연결된 간선 중 가장 작은 가중치의 간선을 선택합니다.
            - 선택한 간선으로 연결된 정점들 중 아직 신장 트리에 포함되지 않은 정점들을 대상으로, 가장 작은 가중치의 간선을 선택하여 신장 트리에 추가합니다.
            - 선택된 간선의 수가 (정점의 개수 - 1)이 될 때까지 위 과정을 반복합니다.
            
            - **동작 과정**
                
                ![[그림 8] Prim Algorithm의 동작 과정](https://github.com/BangDori/CS_interview_Study/blob/main/algorithm%26data_structure/img/Prim_Algorithm.png)
                
                [그림 8] Prim Algorithm의 동작 과정
                
- **답안**
    
    최소 신장 트리란 그래프의 모든 정점이 사이클 없이 연결된 신장 트리 중 간선 가중치의 합이 최소인 신장 트리를 의미합니다. 최소 신장 트리는 Kruskal과 Prim 알고리즘을 통해서 구현할 수 있습니다. Kruskal의 경우 그래프의 간선들을 오름차순으로 정렬하여 가장 낮은 가중치의 간선부터 차례로 추가하는 그리디 알고리즘 방식이고, Prim의 경우는 시작 정점부터 단계적으로 트리를 확장하는 방법입니다.
    
- **[꼬리 질문] MST(Minimum Spanning Tree)에서 사이클이 형성되었는지 확인하는 방법에 대해서 설명해주세요.**
    - **답안**
        
        사이클이 발생하는지의 여부는 Union-Find 알고리즘을 통해 간선으로 연결되어진 정점이 동일한 부모를 가르키는지 확인 함으로써 사이클이 형성되었는지 확인할 수 있습니다.
        
- **참고 자료**
    - **Data Structure (조행래 교수님)**
    - **Wikipedia** - [Spaninng tree](https://en.wikipedia.org/wiki/Spanning_tree)
    - ****Data Structure & Algorithms - Spanning Tree -**** [tutorialspoint](https://www.tutorialspoint.com/data_structures_algorithms/spanning_tree.htm)
    - **Kruskal Alogrithm** - [안경잡이 개발자](https://m.blog.naver.com/ndb796/221230994142)
    - **Kruskal Algorithm** - [조용한고라니](https://dev-gorany.tistory.com/60)
